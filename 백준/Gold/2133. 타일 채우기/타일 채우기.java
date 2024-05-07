import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int[] dp = new int[31];
        int n = Integer.parseInt(br.readLine());

        dp[2] = 3;
        dp[0] = 1;

        if(n%2 == 0){
            for(int i=4;i<=n;i+=2){
                dp[i] += 3*dp[i-2];

                for(int j=i-4;j>=0;j-=2){
                    dp[i] += 2*dp[j];
                }

            }

            System.out.println(dp[n]);
        } else{
            System.out.println("0");
        }
    }
}