import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        int length = Integer.parseInt(reader.readLine());
        int[] inputArr = new int[length];

        StringTokenizer tokenizer = new StringTokenizer(reader.readLine()," ");

        for (int i = 0; i < length; i++) {
            inputArr[i] = Integer.parseInt(tokenizer.nextToken());
        }

        mergeSort(inputArr,0,length - 1);

        int result = findGOODNumber(inputArr);

        System.out.println(result);
    }

    public static int findGOODNumber(int[] inputArr) {
        int result = 0;
        int length = inputArr.length;
        for(int i = 0;i<length;i++){
            int left = 0;
            int right = length - 1;

            while(true){
                if(left == i) left++;
                if(right == i) right--;

                if(left >= right) break;

                int sum = inputArr[left] + inputArr[right];
                //정렬된 배열이므로 합이 크면 right--, 작으면 left++
                if(sum > inputArr[i]){
                    //두 포인터의 원소 합이 i번째 원소보다 큰 경우
                    right--;
                } else if(sum < inputArr[i]){
                    //두 포인터의 원소 합이 i번째 원소보다 작은 경우
                    left++;
                } else{
                    //두 포인터의 원소 합이 같은 경우 GOOD! Number!
                    result++;
                    break;
                }
            }
        }
        return result;
    }

    public static void mergeSort(int[] arr,int start, int end){
        if(start >= end){
            return;
        }
        int mid = (start + end) / 2;
        mergeSort(arr,start, mid);
        mergeSort(arr,mid + 1, end);
        merge(arr,start,mid,end);
    }

    private static void merge(int[] arr, int start, int mid, int end) {
        int i = start;
        int j = mid + 1;
        int k = 0;
        int[] temp = new int[end - start + 1];

        while(i <= mid && j <= end){
            if(arr[i] > arr[j]){
                temp[k++] = arr[j++];
            } else {
                temp[k++] = arr[i++];
            }
        }

        if(i <= mid){
            while(i <= mid){
                temp[k++] = arr[i++];
            }
        } else {
            while(j <= end){
                temp[k++] = arr[j++];
            }
        }

        for(int l = 0;l < k; l++){
            arr[start + l] = temp[l];
        }
    }

}
