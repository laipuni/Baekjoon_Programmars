import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        int length = Integer.parseInt(reader.readLine());
        StringTokenizer tokenizer = new StringTokenizer(reader.readLine()," ");
        int[] inputArr = new int[length + 1];

        for (int i = 0; i < length; i++) {
            inputArr[i] = Integer.parseInt(tokenizer.nextToken());
        }

        System.out.println(mergeSort(inputArr,0,length - 1));
    }

    private static Long mergeSort(int[] inputArr,int start,int end){
        if(start < end){
            int mid = (start + end) / 2;
            Long result = 0L;
            result += mergeSort(inputArr,start,mid);
            result += mergeSort(inputArr,mid+1,end);
            result += merge(inputArr,start,end,mid);
            return result;
        }

        return 0L;
    }

    private static Long merge(int[] inputArr, int start, int end, int mid) {
        int i = start;
        int j = mid + 1;
        int k = 0;
        Long crossCount = 0L;
        Long result = 0L;
        int[] temp = new int[end - start + 1];

        while(i <= mid && j <= end){
            if(inputArr[i] > inputArr[j]){
                crossCount++;
                temp[k++] = inputArr[j++];
            } else {
                result += crossCount;
                temp[k++] = inputArr[i++];
            }
        }

        if(i<= mid){
            while(i <= mid){
                result += crossCount;
                temp[k++] = inputArr[i++];
            }
        } else {
            while(j <= end){
                crossCount++;
                temp[k++] = inputArr[j++];
            }
        }

        for (int l = 0; l < k; l++) {
            inputArr[start + l] = temp[l];
        }

        return result;
    }

}
