import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Main {

    private static int[] parent;
    private static int planet;

    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        planet = Integer.parseInt(reader.readLine());
        initParentArr();
        PriorityQueue<edge> heap = createHeap(reader);
        long sum = getSpanningTreeCost(heap);
        System.out.println(sum);
    }

    private static PriorityQueue<edge> createHeap(final BufferedReader reader) throws IOException {
        PriorityQueue<edge> heap = new PriorityQueue<>(new Comparator<edge>() {
            @Override
            public int compare(final edge o1, final edge o2) {
                return o1.getCost() - o2.getCost();
            }
        });

        for (int i = 0; i < planet; i++) {
            StringTokenizer tokenizer = new StringTokenizer(reader.readLine());
            for (int j = 0; j < planet; j++) {
                if(i == j){
                    tokenizer.nextToken();
                    continue;
                }
                int cost = Integer.parseInt(tokenizer.nextToken());
                heap.add(new edge(i,j,cost));
            }
        }
        return heap;
    }

    private static long getSpanningTreeCost(final PriorityQueue<edge> heap) {
        long sum = 0L;
        int count = 0;
        while(count < planet - 1){
            edge now = heap.poll();
            int x = find(now.getFront());
            int y = find(now.getBack());
            if(x == y){
                continue;
            } else {
                parent[y] = x;
                count++;
                sum+=now.getCost();
            }
        }
        return sum;
    }

    private static void initParentArr() {
        parent = new int[planet];
        for (int i = 0; i < planet; i++) {
            parent[i] = i;
        }
    }

    private static int find(int x){
        if(parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }

    static class edge{
        private int front;
        private int back;
        private int cost;

        public edge(final int front, final int back, final int cost) {
            this.front = front;
            this.back = back;
            this.cost = cost;
        }

        public int getFront() {
            return front;
        }

        public int getBack() {
            return back;
        }

        public int getCost() {
            return cost;
        }
    }

}
