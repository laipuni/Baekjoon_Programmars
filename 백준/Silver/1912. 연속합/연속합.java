import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Main{

    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        int length = Integer.parseInt(reader.readLine());
        String[] numbers = reader.readLine().split(" ");

        int bestSum = Integer.MIN_VALUE;
        int endSum = 0;

        for (String number : numbers) {
            int intNumber = Integer.parseInt(number);
            endSum = Math.max(endSum + intNumber, intNumber);
            bestSum = Math.max(bestSum,endSum);
        }
        
        reader.close();
        System.out.println(bestSum);
    }

}