package problem.practice.beakjoon.problem;

import org.assertj.core.api.Assertions;
import org.junit.jupiter.api.DisplayName;
import org.junit.jupiter.api.DynamicTest;
import org.junit.jupiter.api.Test;
import org.junit.jupiter.api.TestFactory;
import problem.practice.beakjoon.problem.Solution5430.Direction;
import problem.practice.beakjoon.problem.Solution5430.Numbers;

import java.util.List;
import java.util.stream.Stream;

import static org.assertj.core.api.Assertions.*;
import static org.assertj.core.api.Assertions.assertThat;
import static org.junit.jupiter.api.Assertions.*;
import static org.junit.jupiter.api.DynamicTest.dynamicTest;

class Solution5430Test {

    @DisplayName("[1,2,3]을 입력하면 {1,2,3}를 원소로 가지는 리스트를 만든다.")
    @Test
    void createNumbers(){
        //given
        Numbers numbers = Numbers.of("[1,2,3]",Direction.ASC);

        //when
        List<Integer> resultNumbers = numbers.copyNumbers();

        //then
        assertThat(resultNumbers).hasSize(3)
                .isEqualTo(List.of(1,2,3));
    }

    @DisplayName("방향이 순방향 일 경우 맨 앞에 원소를 뺀다.")
    @Test
    void deleteASC(){
        //given
        Numbers numbers = Numbers.of("[1,2,3]",Direction.ASC);
        //when
        boolean deleteResult = numbers.delete();

        //then
        assertThat(deleteResult).isTrue();
        assertThat(numbers.copyNumbers()).hasSize(2)
                .isEqualTo(List.of(2,3));
    }

    @DisplayName("방향이 역방향 일 경우 맨 뒤에 원소를 뺀다.")
    @Test
    void deleteDESC(){
        //given
        Numbers numbers = Numbers.of("[1,2,3]",Direction.DESC);
        //when
        boolean deleteResult = numbers.delete();

        //then
        assertThat(deleteResult).isTrue();
        assertThat(numbers.copyNumbers()).hasSize(2)
                .isEqualTo(List.of(1,2));
    }

    @TestFactory
    Stream<DynamicTest> delete(){
        Numbers numbers = Numbers.of("[1]",Direction.ASC);

        return Stream.of(
                dynamicTest("리스트에서 원소하나를 뺀다.",() ->{
                    //when
                    boolean deleteResult = numbers.delete();

                    //then
                    assertThat(deleteResult).isTrue();
                    assertThat(numbers.copyNumbers()).isEmpty();
                }),
                dynamicTest("리스트가 원소가 없는 경우 삭제할 시 false를 반환한다.",()->{
                    //when
                    boolean deleteResult = numbers.delete();

                    //then
                    assertThat(deleteResult).isFalse();
                })
        );
    }

    @DisplayName("순방향일 경우 역방향으로,역방향일 경우 순방향으로 바꾼다.")
    @TestFactory
    Stream<DynamicTest> reverse(){

        Numbers numbers = Numbers.of("[1,2,3]",Direction.ASC);

        return Stream.of(
                dynamicTest("순방향일 경우 역방향으로 바꾼다",() -> {
                    //when
                    numbers.reversDirection();

                    //then
                    assertThat(numbers.getDirection()).isEqualTo(Direction.DESC);
                }),
                dynamicTest("역방향일 경우 순방향으로 바꾼다",() -> {
                    //when
                    numbers.reversDirection();

                    //then
                    assertThat(numbers.getDirection()).isEqualTo(Direction.ASC);
                })
        );
    }
}