import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

    static final int DIV_NUM = 1000000000;
    static final int NUM_MAX = 9;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());

        long[][] dp = new long[NUM_MAX + 1][n+1]; //dp[현재 숫자][길이]

        if(n==1){
            System.out.println("9");
            return;
        }

        for(int i=0;i<=NUM_MAX;i++){
            dp[i][1] = 1;
        }

        for(int i=2;i<=n;i++){
           for(int j=0;j<=NUM_MAX;j++){
               if(i==2 && j==1){
                   dp[1][2] = 1;
                   continue;
               }

               if(j >= 1){
                   dp[j][i] += dp[j-1][i-1]%DIV_NUM;
               }

               if(j <= 8){
                   dp[j][i] += dp[j+1][i-1]%DIV_NUM;
               }
           }
        }

        long sum = 0;
        for(int i = 0;i<=NUM_MAX;i++){
            sum+= dp[i][n] % DIV_NUM;
        }

        System.out.println(sum%DIV_NUM);
    }
}