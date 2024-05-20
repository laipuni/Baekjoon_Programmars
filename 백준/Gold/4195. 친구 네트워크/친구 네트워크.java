import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.Map;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder builder = new StringBuilder();
        int test = Integer.parseInt(reader.readLine());
        for (int i = 0; i < test; i++) {
            findFriendNetWork(reader,builder);
        }
        System.out.print(builder.toString());
    }
    
    private static void findFriendNetWork(final BufferedReader reader, final StringBuilder builder) throws IOException {
        int network = Integer.parseInt(reader.readLine());
        StringTokenizer tokenizer;
        Map<String, Integer> friendMap = new HashMap<>();
        int[] parent = new int[network * 2];
        int[] level = new int[network * 2];

        initArr(network, parent, level);

        int idx = 0;
        for (int i = 0; i < network; i++) {
            tokenizer = new StringTokenizer(reader.readLine(), " ");
            String first = tokenizer.nextToken();
            String second = tokenizer.nextToken();
            
            if(!friendMap.containsKey(first)){
                    friendMap.put(first,idx++);
            }

            if(!friendMap.containsKey(second)){
                    friendMap.put(second,idx++);
            }

            builder.append(union(parent,level, friendMap.get(first), friendMap.get(second))).append("\n");
        }
                
    }

    private static void initArr(final int network, final int[] parent, final int[] level) {
        for (int i = 0; i < network * 2; i++) {
            parent[i] = i;
            level[i] = 1;
        }
    }

    private static int find(final int x, final int[] parent){
        if(parent[x] == x) return x;
        return parent[x] = find(parent[x],parent);
    }
    
    private static int union(final int[] parent, final int[] level, final int first, final int second) {
        int firstParent = find(first,parent);
        int secondParent = find(second,parent);
        if(firstParent != secondParent){
            parent[secondParent] = firstParent;
            level[firstParent] += level[secondParent];
        }
        return level[firstParent];
    }

}
