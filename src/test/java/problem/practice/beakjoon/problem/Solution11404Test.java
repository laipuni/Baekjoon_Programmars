package problem.practice.beakjoon.problem;

import org.assertj.core.api.Assertions;
import org.junit.jupiter.api.DisplayName;
import org.junit.jupiter.api.Test;

import static org.assertj.core.api.Assertions.assertThat;
import static org.junit.jupiter.api.Assertions.*;

class Solution11404Test {

    @DisplayName("도시들의 간선 배열을 입력하면 도시들의 최소비용을 반환한다")
    @Test
    void floyd(){
        //given
        int cityNum = 5;
        int[][] map = {
                {0,0,0,0,0},
                {0,0,2,3,1,10},
                {0,100001,0,100001,2,100001},
                {0,8,100001,0,1,1},
                {0,100001,100001,100001,0,3},
                {0,7,4,100001,100001,0}
        };
        //when
        Solution11404.floyd(map,cityNum);

        //then
        assertThat(map).isEqualTo(
                new int[][]{
                        {0,0,0,0,0},
                        {0,0,2,3,1,4},
                        {0,12,0,15,2,5},
                        {0,8,5,0,1,1},
                        {0,10,7,13,0,3},
                        {0,7,4,10,6,0},
                }
        );
    }

}