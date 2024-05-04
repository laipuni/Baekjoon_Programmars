import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static int[] tree;
    public static int[] inputArr;

    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        int length = Integer.parseInt(reader.readLine());// input 값들 길이
        tree = new int[length*4 + 1];
        inputArr = new int[length + 1];

        inputNumbers(reader, length);
        initTree(1,length,1);
        query(reader, length);

    }

    private static void query(final BufferedReader reader, final int length) throws IOException {
        StringBuilder builder = new StringBuilder();
        int m = Integer.parseInt(reader.readLine()); //쿼리의 개수

        for (int i = 0; i < m; i++) {
            StringTokenizer tokenizer = new StringTokenizer(reader.readLine()," ");
            switch (tokenizer.nextToken()){
                case "1": //1 5 3으로 받았을 경우 inputArr에 5번째 원소를 3으로 바꾸는 쿼리
                    int idx = Integer.parseInt(tokenizer.nextToken());
                    int changeNum = Integer.parseInt(tokenizer.nextToken());
                    inputArr[idx] = changeNum;
                    updateTree(1, length,idx,1);
                    break;
                case "2": //가장 작은 원소를 조회하는 쿼리
                    builder.append(tree[1]).append("\n");
                    break;
            }
        }
        System.out.print(builder.toString());
    }

    private static void inputNumbers(final BufferedReader reader, final int length) throws IOException {
        StringTokenizer tokenizer = new StringTokenizer(reader.readLine(), " ");

        for (int i = 1; i <= length; i++) {
            inputArr[i] = Integer.parseInt(tokenizer.nextToken());
        }
    }

    public static void initTree(int start,int end, int node){
        if(start == end){
            tree[node] = start;
            return;
        }

        int mid = (start + end) / 2;

        initTree(start, mid,node*2);
        initTree(mid + 1, end,node*2 + 1);

        if(inputArr[tree[node*2]] > inputArr[tree[node*2 + 1]]){
            tree[node] = tree[node*2 + 1];
        } else {
            tree[node] = tree[node*2];
        }
    }

    public static void updateTree(int start,int end, int idx, int node){
        if(idx < start || idx > end || start == end){
            return;
        }

        int mid = (start + end)/ 2;

        updateTree(start,mid,idx,node*2);
        updateTree(mid + 1, end,idx,node*2 + 1);

        if(inputArr[tree[node*2]] > inputArr[tree[node*2 + 1]]){
            tree[node] = tree[node * 2 + 1];
        } else {
            tree[node] = tree[node * 2];
        }
    }

}
