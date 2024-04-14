import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder builder = new StringBuilder();
        StringTokenizer tokenizer;

        int count = Integer.parseInt(reader.readLine());
        List<Position> positions = new LinkedList<>();

        for (int i = 0; i < count; i++) {
            tokenizer = new StringTokenizer(reader.readLine()," ");
            int x = Integer.parseInt(tokenizer.nextToken());
            int y = Integer.parseInt(tokenizer.nextToken());

            positions.add(new Position(x,y));
        }

        positions.sort(createComparator());
        positions.forEach(position -> builder.append(position.toString()).append("\n"));
        System.out.println(builder.toString());
    }

    private static Comparator<Position> createComparator() {
        return (o1, o2) -> {
            if (o1.getY() > o2.getY()) {
                return 1;
            } else if (o1.getY() == o2.getY()) {
                if (o1.getX() > o2.getX()) {
                    return 1;
                } else if(o1.getX() < o2.getX()){
                    return -1;
                }
                return 0;
            } else {
                return -1;
            }
        };
    }

    static class Position{
        private int x;
        private int y;

        public Position(final int x, final int y) {
            this.x = x;
            this.y = y;
        }

        public int getX() {
            return x;
        }

        public int getY() {
            return y;
        }

        @Override
        public String toString() {
            return x + " " + y;
        }
    }

}
