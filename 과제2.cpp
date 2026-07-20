#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
    // [] 안에는 숫자만 가능하므로 50*50(2500)으로 공간 확보
    int arrayA[50][50] = { 0 };
    int arrayB[50][50] = { 0 };

    int n1, n2;
    int num = 1;

    printf("행의 개수(N1)를 입력하세요 (최대 50): ");
    scanf("%d", &n1);
    printf("열의 개수(N2)를 입력하세요 (최대 50): ");
    scanf("%d", &n2);

    // 입력 받은 배열의 크기가 초반에 확보한 배열 크기를 넘어서면 프로그램 안전 종료(return 1; 사용)
    if (n1 > 50 || n2 > 50 || n1 <= 0 || n2 <= 0) {
        printf("오류: 1부터 100 사이의 숫자를 입력해주세요.\n");
        return 1;
    }

    // 입력받은 n1, n2 크기만큼 배열A에 순서대로 값 채우기
    for (int i = 0; i < n1; i++) {
        for (int j = 0; j < n2; j++) {
            arrayA[i][j] = num++;
        }
    }

    // 행(i)과 열(j)을 뒤바꾸어 배열B에 저장
    for (int i = 0; i < n1; i++) {
        for (int j = 0; j < n2; j++) {
            arrayB[j][i] = arrayA[i][j];
        }
    }

    // 원본 배열A 출력 (n1행 n2열)
    printf("\n배열A (%d x %d)\n", n1, n2);
    for (int i = 0; i < n1; i++) {
        for (int j = 0; j < n2; j++) {
            printf("%d\t", arrayA[i][j]);
        }
        printf("\n");
    }

    // 행과 열이 바뀐 배열B 출력 (n2행 n1열)
    printf("\n배열B (%d x %d)\n", n2, n1);
    for (int i = 0; i < n2; i++) {
        for (int j = 0; j < n1; j++) {
            printf("%d\t", arrayB[i][j]);
        }
        printf("\n");
    }

    return 0;
}