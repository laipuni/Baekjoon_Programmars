import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    static int n,m;
    static int order,scc_idx;
    static int[] sccIndegree;
    static int[] scc;
    static int[] order_arr;
    static boolean[] visited;
    static Stack<Integer> stack;
    static ArrayList<ArrayList<Integer>> info;

    private static void initField() {
        scc = new int[n+1];
        sccIndegree = new int[n+1];
        info = new ArrayList<>();
        visited = new boolean[n+1];
        order_arr = new int[n+1];
        stack = new Stack<>();
        scc_idx = 0;
        order = 0;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int t = Integer.parseInt(br.readLine());

        while(t != 0){
            StringTokenizer st = new StringTokenizer(br.readLine()," ");
            n = Integer.parseInt(st.nextToken());
            m = Integer.parseInt(st.nextToken());

            initField();

            for(int i=0;i<=n;i++){
                info.add(new ArrayList<>());
            }

            for(int i = 0; i<m; i++){
                st = new StringTokenizer(br.readLine()," ");

                int a = Integer.parseInt(st.nextToken());
                int b = Integer.parseInt(st.nextToken());

                info.get(a).add(b);
            }

            solve();
            t--;
        }
    }

    static void solve(){
        for (int i=1;i<=n;i++){
            if(!visited[i]){
                DFS(i);
            }
        }

        for(int i=1;i<=n;i++){
            for (int next : info.get(i)) {
                if(scc[i] == scc[next]) continue;
                sccIndegree[scc[next]]++;
            }
        }

        int result = 0;
        for(int i=0;i<scc_idx;i++){
            result += sccIndegree[i] == 0 ? 1 : 0;
        }

        System.out.println(result);
    }

    static int DFS(int num){
        order_arr[num] = ++order;
        stack.push(num);

        int parent = order;
        for(int next : info.get(num)){
            if(order_arr[next] == 0){
                parent = Math.min(parent,DFS(next));
            } else if(!visited[next]){
                parent = Math.min(parent,order_arr[next]);
            }
        }

        if(parent == order_arr[num]){
            while(true){
                int top = stack.pop();
                visited[top] = true;
                scc[top] = scc_idx;

                if(top == num){
                    break;
                }
            }

            scc_idx++;
        }

        return parent;
    }
}