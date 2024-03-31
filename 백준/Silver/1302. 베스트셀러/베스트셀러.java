import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    public static <List> void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder builder = new StringBuilder();
        int count = Integer.parseInt(reader.readLine());

        Map<String,Integer> bookMap = new HashMap<>();
        for (int i = 0; i < count; i++) {
            String inputString = reader.readLine();
            if(bookMap.get(inputString) == null){
                bookMap.put(inputString,1);
            } else {
                bookMap.replace(inputString, bookMap.get(inputString) + 1);
            }
        }

        Integer max = bookMap.values().stream()
                .mapToInt(number -> number)
                .max()
                .orElseThrow(NoSuchElementException::new);

        ArrayList<String> bestSeller = new ArrayList<>();

        for (Map.Entry<String, Integer> entry : bookMap.entrySet()) {
            Integer value = entry.getValue();
            if(max.equals(value)){
                bestSeller.add(entry.getKey());
            }
        }

        Collections.sort(bestSeller);
        

        System.out.println(bestSeller.get(0));
    }
}
