import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static final int MAX_MEDICINE = 30;
    public static long[][] dp = new long[MAX_MEDICINE + 1][MAX_MEDICINE + 1];

    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder builder = new StringBuilder();

        for (int i = 1; i <= MAX_MEDICINE; i++) {
            DFS(i,0);
        }

        while(true){
            int num = Integer.parseInt(reader.readLine());

            if(num == 0){
                break;
            }

            builder.append(dp[num][0]).append("\n");
        }

        System.out.print(builder.toString());
    }

    public static long DFS(int one,int half){
        if(dp[one][half] != 0){
            return dp[one][half];
        }

        if(one == 0 && half == 0){
            return 1;
        }

        if(one > 0){
            dp[one][half] += DFS(one-1,half+1);
        }

        if(half > 0){
            dp[one][half] += DFS(one,half-1);
        }

        return dp[one][half];
    }
}
