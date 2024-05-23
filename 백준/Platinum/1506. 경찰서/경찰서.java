import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    static int n;
    static int order;
    static int result;
    static int[] cost;
    static int[] order_arr;
    static boolean[] visited;
    static ArrayList<ArrayList<Integer>> info;
    static Stack<Integer> q;

   static void initAndInputData() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st =new StringTokenizer(br.readLine());

        n = Integer.parseInt(st.nextToken());

        cost = new int[n+1];
        order_arr = new int[n+1];
        visited = new boolean[n+1];
        q = new Stack<>();
        info = new ArrayList<>();

        for(int i=0;i<=n;i++){
            info.add(new ArrayList<>());
        }

        st = new StringTokenizer(br.readLine()," ");
        for(int i=1;i<=n;i++){
            cost[i] = Integer.parseInt(st.nextToken());
        }

        for(int i=1;i<=n;i++){
            String str = br.readLine();

            for(int j=1;j<=n;j++){
                if(str.charAt(j-1) == '1'){
                    info.get(i).add(j);
                }
            }
        }

    }

    public static void main(String[] args) throws IOException {
        initAndInputData();

        for(int i=1;i<=n;i++){
            if(!visited[i]){
                DFS(i);
            }
        }

        System.out.println(result);
    }

    static int DFS(int num){
       order++;
       order_arr[num] = order;
       q.push(num);

       int parent = order;
       for(int next : info.get(num)){
           if(order_arr[next] == 0){
               int temp = DFS(next);

               parent = Math.min(temp,parent);
           } else if (!visited[next]) {
               parent = Math.min(parent,order_arr[next]);
           }
       }

       if(order_arr[num] == parent){
           int min = 1000000;

           while(true){
               int top = q.pop();
               visited[top] = true;
               min  = Math.min(min,cost[top]);

               if(top == num){
                   break;
               }
           }

           result += min;
       }

       return parent;
    }
}
