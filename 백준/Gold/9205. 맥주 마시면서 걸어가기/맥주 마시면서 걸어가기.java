import java.io.*;
import java.util.*;

public class Main {

    static int n;
    static List<int[]> market;
    static int end_x,end_y;
    static int start_x,start_y;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringBuilder sb = new StringBuilder();
        StringTokenizer st;

        int t = Integer.parseInt(br.readLine());

        while(t > 0){
            n = Integer.parseInt(br.readLine());

            market = new ArrayList<>();

            st = new StringTokenizer(br.readLine()," ");
            start_x = Integer.parseInt(st.nextToken());
            start_y = Integer.parseInt(st.nextToken());

            for(int i=0;i<n;i++){
                st = new StringTokenizer(br.readLine()," ");

                int x = Integer.parseInt(st.nextToken());
                int y = Integer.parseInt(st.nextToken());

                market.add(new int[] {x,y});
            }

            st = new StringTokenizer(br.readLine()," ");
            end_x = Integer.parseInt(st.nextToken());
            end_y = Integer.parseInt(st.nextToken());


            sb.append(BFS()).append("\n");
            t--;
        }

        System.out.print(sb);
    }

    private static String BFS() {
        Queue<int[]> q = new LinkedList<>();

        boolean[] visited = new boolean[n+1];

        q.offer(new int[] {start_x,start_y});

        while (!q.isEmpty()){
            int[] now = q.poll();//x,y

            if(Math.abs(now[0] - end_x) + Math.abs(now[1] - end_y) <= 1000){
                return "happy";
            }

            for (int i=0;i<n;i++) {
                int[] ints = market.get(i);
                int next = Math.abs(ints[0] - now[0]) + Math.abs(ints[1] - now[1]);

                if(next <= 1000 && !visited[i]){
                    visited[i] = true;
                    q.offer(new int[] {ints[0],ints[1]});
                }
            }
        }

        return "sad";
    }

}