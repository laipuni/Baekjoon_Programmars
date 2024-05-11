import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    public static final int INF = Integer.MAX_VALUE;

    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer tokenizer = new StringTokenizer(reader.readLine(), " ");
        int regionNum = Integer.parseInt(tokenizer.nextToken());
        int detectRange = Integer.parseInt(tokenizer.nextToken());
        int loadNum = Integer.parseInt(tokenizer.nextToken());

        int[][] dis = new int[regionNum + 1][regionNum + 1];
        int[] regionItem = new int[regionNum + 1];
        List<LinkedList<Edge>> edgeList = new ArrayList<>();

        for (int i = 0; i <= regionNum; i++) {
            edgeList.add(new LinkedList<>());
        }

        for (int i = 1; i <= regionNum; i++) {
            for (int j = 1; j <= regionNum; j++) {
                if(i==j) continue;
                dis[i][j] = INF;
            }
        }

        //각 지역의 아이템 개수 입력받기
        tokenizer = new StringTokenizer(reader.readLine()," ");
        for (int i = 1; i <= regionNum; i++) {
            regionItem[i] = Integer.parseInt(tokenizer.nextToken());
        }

        //연결된 두 노드의 간선 정보와 비용을 입력받기
        for (int i = 0; i <loadNum; i++) {
            tokenizer = new StringTokenizer(reader.readLine(), " ");
            int front = Integer.parseInt(tokenizer.nextToken());
            int back = Integer.parseInt(tokenizer.nextToken());
            int cost = Integer.parseInt(tokenizer.nextToken());
            edgeList.get(front).add(new Edge(back,cost));
            edgeList.get(back).add(new Edge(front,cost));
        }

        for (int i = 1; i <= regionNum; i++) {
            dijkstra(regionNum,dis,edgeList,i);
        }

        int max = 0;
        for (int i = 1; i <= regionNum; i++) {
            int sum = 0;
            for (int j = 1; j <= regionNum; j++) {
                if(dis[i][j] == INF || dis[i][j] > detectRange) continue;
                sum += regionItem[j];
            }
            max = Math.max(max, sum);
        }

        System.out.println(max);

    }

    public static void dijkstra(final int regionNum,final int[][] dis, final List<LinkedList<Edge>> edgeList, int start){
        PriorityQueue<Edge> heap = new PriorityQueue<>(new Comparator<Edge>() {
            @Override
            public int compare(final Edge o1, final Edge o2) {
                return o1.getCost() - o2.getCost();
            }
        });
        boolean[] visited = new boolean[regionNum + 1];
        heap.add(new Edge(start,0));

        while(!heap.isEmpty()){
            Edge now = heap.poll();
            visited[now.vertices] = true;

            for (Edge next : edgeList.get(now.vertices)) {
                int sumCost = now.getCost() + next.getCost();
                int nextRegion = next.getVertices();
                if(dis[start][nextRegion] > sumCost && !visited[nextRegion]){
                    dis[start][nextRegion] = sumCost;
                    heap.add(new Edge(nextRegion,sumCost));
                }
            }
        }
    }

    static class Edge{
        private int vertices;
        private int cost;

        public Edge(final int vertices, final int cost) {
            this.vertices = vertices;
            this.cost = cost;
        }

        public int getVertices() {
            return vertices;
        }

        public int getCost() {
            return cost;
        }
    }
}
