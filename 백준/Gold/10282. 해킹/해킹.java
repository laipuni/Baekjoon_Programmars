import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    public static final Integer INF = Integer.MAX_VALUE;

    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder builder = new StringBuilder();
        int testNum = Integer.parseInt(reader.readLine());

        for (int i = 0; i < testNum; i++) {
            builder.append(findCorruptionTime(reader)).append("\n");
        }

        System.out.print(builder.toString());
    }

    private static String findCorruptionTime(final BufferedReader reader) throws IOException {
        StringTokenizer tokenizer = new StringTokenizer(reader.readLine(), " ");
        List<LinkedList<Edge>> edgeList = new ArrayList<>();
        int computerNum = Integer.parseInt(tokenizer.nextToken());
        int edgeNum = Integer.parseInt(tokenizer.nextToken());
        int start = Integer.parseInt(tokenizer.nextToken());
        int[] duration = new int[computerNum];

        init(computerNum, start - 1, duration, edgeList);

        for (int i = 0; i < edgeNum; i++) {
            tokenizer = new StringTokenizer(reader.readLine(), " ");
            int front = Integer.parseInt(tokenizer.nextToken()) - 1;
            int back = Integer.parseInt(tokenizer.nextToken()) - 1;
            int cost = Integer.parseInt(tokenizer.nextToken());
            edgeList.get(back).add(new Edge(front,cost));
        }

        dijkstra(computerNum,start - 1,edgeList,duration);

        int max = 0;
        int count = 0;
        for (int i = 0; i < computerNum; i++) {
            if(duration[i] == INF) continue;
            max = Math.max(max, duration[i]);
            count++;
        }

        return count + " " + max;
    }

    private static void init(final int computerNum, final int start, final int[] duration, final List<LinkedList<Edge>> edgeList) {
        for (int i = 0; i < computerNum; i++) {
            if(start == i) continue;
            duration[i] = INF;
        }

        for (int i = 0; i < computerNum; i++) {
            edgeList.add(new LinkedList<>());
        }
    }

    private static void dijkstra(int computerNum,int start, List<LinkedList<Edge>> edgeList,int[] duration){
        PriorityQueue<Edge> heap = new PriorityQueue<>(new Comparator<Edge>() {
            @Override
            public int compare(final Edge o1, final Edge o2) {
                return o1.getCost() - o2.getCost();
            }
        });
        boolean[] visited = new boolean[computerNum];
        try {
            heap.add(new Edge(start,0));
        } catch (Exception e){
            e.printStackTrace();
        }

        while(!heap.isEmpty()){
            Edge now = heap.poll();
            visited[now.getVertices()] = true;

            for (Edge next : edgeList.get(now.getVertices())) {
                int sumCost = now.getCost() + next.getCost();
                int nextEdge = next.getVertices();
                if(duration[nextEdge] > sumCost && !visited[nextEdge]){
                    duration[nextEdge] = sumCost;
                    heap.add(new Edge(nextEdge,sumCost));
                }
            }
        }
    }

    static class Edge {
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
