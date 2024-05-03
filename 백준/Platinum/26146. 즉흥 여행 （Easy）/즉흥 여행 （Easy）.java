import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    public static int nowNum = 1;
    public static int[] nodeNum;
    public static boolean[] visited;
    public static List<LinkedList<Integer>> vertices = new ArrayList<>();

    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer tokenizer = new StringTokenizer(reader.readLine(), " ");
        int region = Integer.parseInt(tokenizer.nextToken());
        int load = Integer.parseInt(tokenizer.nextToken());
        
        nodeNum = new int[region + 1];
        visited = new boolean[region + 1];

        for(int i=0;i<region;i++){
            vertices.add(new LinkedList<>());
        }

        for(int i=0;i<load;i++){
            tokenizer = new StringTokenizer(reader.readLine(), " ");
            int front = Integer.parseInt(tokenizer.nextToken()) - 1;
            int back = Integer.parseInt(tokenizer.nextToken()) - 1;
            vertices.get(front).add(back);
        }

        List<List<Integer>> groupList = new ArrayList<>();
        for(int i=0;i<region;i++){
            if(!visited[i]){
                dfs(i,new Stack<Integer>(),groupList);
            }
        }

        System.out.println(groupList.size() == 1 ? "Yes" : "No");
    }

    public static int dfs(int now, Stack<Integer> stack,List<List<Integer>> groupList){
        nodeNum[now] = nowNum++;
        stack.add(now);
        int parent = nodeNum[now];

        for (int next : vertices.get(now)) {
            if(nodeNum[next] == 0){
                parent = Math.min(parent,dfs(next,stack,groupList));
            } else if(!visited[next]){
                parent = Math.min(parent,nodeNum[next]);
            }
        }

        if(nodeNum[now] == parent){
            List<Integer> group = new ArrayList<>();
            int popNum;
            while(stack.peek() != now){
                popNum = stack.pop();
                visited[popNum] = true;
                group.add(popNum);
            }

            popNum = stack.pop();
            group.add(popNum);
            visited[popNum] = true;
            groupList.add(group);
        }

        return parent;
    }
}
