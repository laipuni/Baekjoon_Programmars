import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
    static int[] map = new int[101];

    static void BFS(){
        int result = 0;
        Queue<Integer> q = new LinkedList<>();

        int[] check = new int[101];

        q.offer(1);
        check[1] = 0;

        while(!q.isEmpty()){
            int now = q.poll();

            for(int i=1;i<=6;i++){
                int next = now + i;

                if(next > 100){
                    continue;
                }

                if(map[next] != 0){
                    next = map[next];
                }

                if(check[next] != 0){
                    continue;
                }

                if(next == 100){
                    System.out.println(check[now] + 1);
                    return;
                }

                q.offer(next);
                check[next] = check[now] + 1;
            }
        }

    }

    static void input() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st = new StringTokenizer(br.readLine(), " ");

        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());

        for(int i=0; i<n; i++){
            st = new StringTokenizer(br.readLine()," ");
            int now = Integer.parseInt(st.nextToken());
            int next = Integer.parseInt(st.nextToken());
            map[now] = next;
        }

        for(int i=0; i<m; i++){
            st = new StringTokenizer(br.readLine()," ");
            int now = Integer.parseInt(st.nextToken());
            int next = Integer.parseInt(st.nextToken());
            map[now] = next;
        }
    }

    public static void main(String[] args) throws IOException {
        input();

        BFS();
    }
}