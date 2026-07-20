#include <stdio.h>

int main() {
    // 2차원 5*5 배열 선언 array[행][열]
    int array[5][5] = { 0 };
    int num = 1; 

    for (int i = 0; i < 5; i++) {
        int start, end;

        // (0 ~ 2행) 행이 증가하면서 반복문의 반복이 감소 / 0행 5, 1행 3, 2행 1
        if (i <= 2) {
            start = i;
            end = 4 - i;
        }
        // (3 ~ 4행) 행이 증가하면서 반복문의 반복이 다시 증가 / 3행 3, 4행 5
        else {
            start = 4 - i;
            end = i;
        }

        // 위의 조건들에 따라 5*5 배열에 1씩 증가하는 num을 대입
        for (int j = start; j <= end; j++) {
            array[i][j] = num++;
        }
    }

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            // \t(tab)를 이용해 배열을 정리함/ "%d "로 출력하면 10의 자리 수에 의해 5*5 배열의 형태가 무너짐
            printf("%d\t", array[i][j]);
        }
        printf("\n"); 
    }

    return 0;
}