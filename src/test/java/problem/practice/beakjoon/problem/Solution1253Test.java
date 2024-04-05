package problem.practice.beakjoon.problem;

import org.assertj.core.api.Assertions;
import org.junit.jupiter.api.DisplayName;
import org.junit.jupiter.api.Test;

import java.util.Arrays;

import static org.assertj.core.api.Assertions.assertThat;
import static org.junit.jupiter.api.Assertions.*;

class Solution1253Test {

    @DisplayName("양수로 이루어지고 정렬되지 않은 배열을 정렬된 배열로 바꿔준다")
    @Test
    void mergeSortPositive(){
        //given
        int[] arr = {8,7,6,5,4,3,2,1};
        //when
        Solution1253.mergeSort(arr,0, arr.length - 1);
        //then
        assertThat(arr).isEqualTo(new int[]{1,2,3,4,5,6,7,8});
    }

    @DisplayName("음수로 이루지고 정렬되지 않은 배열을 정렬된 배열로 바꿔준다")
    @Test
    void mergeSortNegative(){
        //given
        int[] arr = {-10,-1,-2,-9,-8,-7,-3,-4,-5,-6};
        //when
        Solution1253.mergeSort(arr,0, arr.length - 1);
        //then
        assertThat(arr).isEqualTo(new int[]{-10,-9,-8,-7,-6,-5,-4,-3,-2,-1});
    }

    @DisplayName("음수,양수로 이루지고 정렬되지 않은 배열을 정렬된 배열로 바꿔준다")
    @Test
    void mergeSort(){
        //given
        int[] arr = {5,4,3,2,1,0,-1,-2,-3,-4,-5};
        //when
        Solution1253.mergeSort(arr,0, arr.length - 1);
        //then
        assertThat(arr).isEqualTo(new int[]{-5,-4,-3,-2,-1,0,1,2,3,4,5});
    }

    @DisplayName("1,2,3,4,5,6,7,8,9,10을 입력했을 때 좋은 수는 8개이다.")
    @Test
    void findGOODNumberPositive(){
        //given
        int[] arr = {1,2,3,4,5,6,7,8,9,10};
        //when
        int result = Solution1253.findGOODNumber(arr);
        //then
        assertThat(result).isEqualTo(8);

    }

    @DisplayName("-10,-9,-8,-7,-6,-5,-4,-,3,-2,-1 을 입력했을 때 좋은 수는 8개이다.")
    @Test
    void findGOODNumberNegative(){
        //given
        int[] arr = {-10,-9,-8,-7,-6,-5,-4,-3,-2,-1};
        //when
        int result = Solution1253.findGOODNumber(arr);
        //then
        assertThat(result).isEqualTo(8);

    }

    @DisplayName("-5,-4,-3,-2,-1,0,1,2,3,4,5 을 입력했을 때 좋은 수는 10개이다.")
    @Test
    void findGOODNumber(){
        //given
        int[] arr = {-5,-4,-3,-2,-1,0,1,2,3,4,5};
        //when
        int result = Solution1253.findGOODNumber(arr);
        //then
        assertThat(result).isEqualTo(11);
    }
}