import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Main {

    public static final int MAX_COST = 100000;

    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer tokenizer = new StringTokenizer(reader.readLine(), " ");
        int min = Integer.parseInt(tokenizer.nextToken());
        int city = Integer.parseInt(tokenizer.nextToken());

        int[][] dp = new int[city + 1][MAX_COST + 1];
        List<Advert> cityList = new ArrayList<>();

        for (int i = 0; i < city; i++) {
            tokenizer = new StringTokenizer(reader.readLine(), " ");
            int cost = Integer.parseInt(tokenizer.nextToken());
            int people = Integer.parseInt(tokenizer.nextToken());
            cityList.add(new Advert(cost,people));
        }
        int minCost = Integer.MAX_VALUE;
        for (int i = 1; i <= city; i++) {
            Advert advert = cityList.get(i - 1);
            for (int j = 1; j <= MAX_COST; j++) {
                if(j >= advert.cost){
                    dp[i][j] = Math.max(dp[i][j-1], dp[i][j - advert.cost] + advert.people);
                    dp[i][j] = Math.max(dp[i][j],dp[i-1][j]);
                } else {
                    dp[i][j] = Math.max(dp[i][j-1],dp[i-1][j]);
                }
                if(min <= dp[i][j]) minCost = Math.min(minCost,j);
            }
        }

        System.out.println(minCost);
    }

    static class Advert{
        private int cost;
        private int people;

        public Advert(final int cost, final int people) {
            this.cost = cost;
            this.people = people;
        }

        public int getCost() {
            return cost;
        }

        public int getPeople() {
            return people;
        }
    }

}
