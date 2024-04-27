package problem.practice.beakjoon.problem;

import org.assertj.core.api.Assertions;
import org.junit.jupiter.api.DisplayName;
import org.junit.jupiter.api.Test;

import static org.assertj.core.api.Assertions.assertThat;
import static org.junit.jupiter.api.Assertions.*;

class Solution4811Test {

    @DisplayName("약 6개를 받을 경우 132개의 경우의 수가 나온다")
    @Test
    void dfs1(){
        //given// when//then
        assertThat(Solution4811.DFS(6,0)).isEqualTo(132);
    }

    @DisplayName("약 1개를 받을 경우 1개의 경우의 수가 나온다")
    @Test
    void DFS2(){
        //given// when//then
        assertThat(Solution4811.DFS(1,0)).isEqualTo(1);
    }

    @DisplayName("약 4개를 받을 경우 14개의 경우의 수가 나온다")
    @Test
    void DFS3(){
        //given// when//then
        assertThat(Solution4811.DFS(4,0)).isEqualTo(14);
    }

    @DisplayName("약 2개를 받을 경우 2개의 경우의 수가 나온다")
    @Test
    void cas4(){
        //given// when//then
        assertThat(Solution4811.DFS(2,0)).isEqualTo(2);
    }

    @DisplayName("약 3개를 받을 경우 5개의 경우의 수가 나온다")
    @Test
    void cas5(){
        //given// when//then
        assertThat(Solution4811.DFS(3,0)).isEqualTo(5);
    }

    @DisplayName("약 30개를 받을 경우 개의 3814986502092304경우의 수가 나온다")
    @Test
    void cas6(){
        //given// when//then
        assertThat(Solution4811.DFS(30,0)).isEqualTo(3814986502092304L);
    }
}