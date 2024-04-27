import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

    public static final int INF = 100000001;

    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer tokenizer;

        int cityNum = Integer.parseInt(reader.readLine());
        int roadNum = Integer.parseInt(reader.readLine());

        int[][] map = createMap(cityNum);

        for(int i=1;i<= roadNum;i++){
            tokenizer = new StringTokenizer(reader.readLine()," ");
            int fromCity = Integer.parseInt(tokenizer.nextToken());
            int toCity = Integer.parseInt(tokenizer.nextToken());
            int cost = Integer.parseInt(tokenizer.nextToken());

            map[fromCity][toCity] = Math.min(map[fromCity][toCity],cost);
        }

        floyd(map,cityNum);
        printMap(cityNum, map);
    }

    private static void printMap(final int cityNum, final int[][] map) {
        StringBuilder builder = new StringBuilder();

        for (int i = 1; i <= cityNum; i++) {
            for (int j = 1; j <= cityNum; j++) {
                if(map[i][j] == INF){
                    builder.append(0).append(" ");
                } else{
                    builder.append(map[i][j]).append(" ");
                }
            }
            builder.append("\n");
        }

        System.out.print(builder.toString());
    }

    public static void floyd(int[][] map,int cityNum){
        for (int k = 1; k <=cityNum; k++) {
            for (int i = 1; i <= cityNum; i++) {
                for (int j = 1; j <= cityNum; j++) {
                    map[i][j] = Math.min(map[i][j],map[i][k] + map[k][j]);
                }
            }
        }
    }

    private static int[][] createMap(final int cityNum) {
        int[][] map = new int[cityNum + 1][cityNum + 1];
        for (int i = 1; i <= cityNum; i++) {
            for (int j = 1; j <= cityNum; j++) {
                if(i == j){
                    continue;
                }
                map[i][j] = INF;
            }
        }
        return map;
    }
}
