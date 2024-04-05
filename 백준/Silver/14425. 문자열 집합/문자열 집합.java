import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.Map;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer tokenizer = new StringTokenizer(reader.readLine()," ");
        int n = Integer.parseInt(tokenizer.nextToken());
        int m = Integer.parseInt(tokenizer.nextToken());

        Map<String,String> stringMap = new HashMap<>();

        for (int i = 0; i < n; i++) {
            String inputString = reader.readLine();
            stringMap.put(inputString,inputString);
        }

        int count = 0;
        for (int i = 0; i < m; i++) {
            String inputString = reader.readLine();
            if(stringMap.get(inputString) != null){
                count++;
            }
        }

        System.out.println(count);
    }

}