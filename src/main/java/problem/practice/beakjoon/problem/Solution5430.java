package problem.practice.beakjoon.problem;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;
import java.util.stream.Collectors;

public class Solution5430 {
    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder builder = new StringBuilder();
        int count = Integer.parseInt(reader.readLine());

        for (int i = 0; i < count; i++) {
            String command = reader.readLine();
            int length = Integer.parseInt(reader.readLine());
            Numbers numbers = Numbers.of(reader.readLine(), Direction.ASC);

            if(executeCommand(command, numbers)){
                builder.append("error").append("\n");
                continue;
            }

            builder.append(numbers.toString()).append("\n");
        }

        System.out.print(builder.toString());

    }

    private static boolean executeCommand(String command, Numbers numbers) {
        for (int j = 0; j < command.length(); j++) {
            char commandChar = command.charAt(j);
            if(commandChar == 'R'){
                numbers.reversDirection();
            } else {
                if(!numbers.delete()){
                    return true;
                }
            }
        }
        return false;
    }

    static class Numbers{
        private Direction direction;
        private List<Integer> numbers;

        private Numbers(List<Integer> numbers,Direction direction){
            this.direction = direction;
            this.numbers = numbers;
        }

        public static Numbers of(String inputNumbers,Direction direction){
            List<Integer> numbers = convertToListBy(inputNumbers);
            return new Numbers(numbers,direction);
        }

        public boolean delete(){
            if(numbers.isEmpty()){
                return false;
            }

            if(Direction.ASC.equals(direction)){
                //순방향 일경우
                numbers.remove(0);
            } else if(Direction.DESC.equals(direction)){
                //역방향 일경우
                numbers.remove(numbers.size() - 1);
            }
            return true;
        }

        public void reversDirection(){
            if(Direction.ASC.equals(direction)){
                //순방향 일경우
                this.direction = Direction.DESC;
            } else if(Direction.DESC.equals(direction)){
                //역방향 일경우
                this.direction = Direction.ASC;
            }
        }

        public List<Integer> copyNumbers(){
            return List.copyOf(numbers);
        }

        public Direction getDirection() {
            return direction;
        }

        private static List<Integer> convertToListBy(String inputNumbers) {
            if(inputNumbers.equals("[]")){
                return new ArrayList<>();
            }

            return Arrays.stream(replaceBy(inputNumbers))
                    .map(Integer::valueOf)
                    .collect(Collectors.toList());
        }

        private static String[] replaceBy(String inputNumbers) {
            return inputNumbers
                    .replace("[", "")
                    .replace("]", "")
                    .split(",");
        }

        @Override
        public String toString() {
            StringJoiner joiner = new StringJoiner(",");

            if(Direction.DESC.equals(direction)){
                reverseJoiner(joiner);
            } else {
                numbers.forEach(n -> joiner.add(String.valueOf(n)));
            }

            return "[" + joiner.toString() + "]";
        }

        private void reverseJoiner(StringJoiner joiner){
            for (int i = numbers.size() - 1; i >=0 ; i--) {
                joiner.add(String.valueOf(numbers.get(i)));
            }
        }
    }


    static enum Direction{
        ASC,DESC
    }
}
