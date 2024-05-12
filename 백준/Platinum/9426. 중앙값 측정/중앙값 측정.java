import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    static int n,k;
    static int[] arr;
    static int[] tree = new int[65535 * 4 +1];

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st = new StringTokenizer(br.readLine()," ");

        n = Integer.parseInt(st.nextToken());
        k = Integer.parseInt(st.nextToken());

        arr = new int[n+1];

        int max = 0;
        for(int i=0; i<n; i++){
            arr[i] = Integer.parseInt(br.readLine());
            max = Math.max(max,arr[i]);
        }

        for(int i=0;i<k;i++){
            update(0,max,arr[i],1,1);
        }

        Long result = 0l;
        for(int i=0;i<n-k+1;i++){
            result += query(0,max,(k+1)/ 2,1);
            update(0,max,arr[i],-1,1);
            update(0,max,arr[k+i],1,1);
        }

        System.out.println(result);
    }

    static void update(int start, int end, int num, int dif, int node){
        if(num < start || end < num){
            return;
        }

        tree[node] += dif;

        if(start == end){
            return;
        }

        int mid = (start + end)/2;

        update(start,mid,num,dif,node*2);
        update(mid + 1,end,num,dif,node*2 + 1);
    }

    static int query(int start, int end, int k,int node){
        if(start == end){
            return start;
        }

        int mid = (start + end) / 2;

        if(tree[node * 2] >= k){
            return query(start, mid, k,node * 2);
        } else{
            return query(mid+1, end,k - tree[node * 2],node*2+1);
        }
    }

}
