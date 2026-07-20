#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> // 동적할당 라이브러리

int main(void)
{
    int n1, n2;

    printf("N1(행)과 N2(열)의 크기를 입력하세요(홀수만 가능): ");
    scanf("%d %d", &n1, &n2);

    // N1 또는 N2가 0 이하이거나 짝수인 경우 프로그램 종료
    if (n1 <= 0 || n1 % 2 == 0 || n2 <= 0 || n2 % 2 == 0)
    {
        printf("올바른 홀수 크기를 입력해주세요.\n");
        return 1;
    }

    // n1*n2만큼의 메모리를 0으로 초기화 하며 할당한다.
    int* arr = (int*)calloc(n1 * n2, sizeof(int));

    // 메모리가 정상적으로 할당되었는지 확인
    if (arr == NULL)
    {
        printf("malloc error\n");
        return 1;
    }

    int line = n1 / 2; // 시작 행: 배열의 정중앙 행
    int row = n2 / 2; // 시작 열: 배열의 정중앙 열
    int num = 1;

    // 최초의 중앙 위치에 숫자 1을 먼저 채워넣음
    arr[line * n2 + row] = num++;

    int R = 1; // 마름모의 반지름을 나타내는 변수

    // 모든 칸에 숫자가 다 채워질 때까지 마름모를 확장하며 반복
    while (num <= n1 * n2)
    {
        // 1. 아래로 1칸 이동하며 새로운 마름모 레이어에 진입
        line++;
        /* 4가지의 조건식
        line >= 0
        line < n1
        row >= 0
        row < n2
        이 조건식을 만족하지 못하면 배열 범위를 벗어나 가상의 메모리에 강제로 숫자를 쓰려고 시도해 프로그램이 강제 종료가 발생하는 상황 발생
        */
        if (line >= 0 && line < n1 && row >= 0 && row < n2)
        {
            arr[line * n2 + row] = num++;
        }

        // 2. 대각선 우측 아래 방향으로 R - 1번 이동
        // 이유: 진입할 때 이미 아래로 1칸 내려왔으므로, 균형을 맞추기 위해 첫 대각선은 R-1번 이동
        for (int i = 0; i < R - 1; i++)
        {
            line++; row++; // 행 증가, 열 증가
            if (line >= 0 && line < n1 && row >= 0 && row < n2)
            {
                arr[line * n2 + row] = num++;
            }
        }

        // 3. 대각선 우측 위 방향으로 R번 이동
        for (int i = 0; i < R; i++)
        {
            line--; row++; // 행 감소, 열 증가
            if (line >= 0 && line < n1 && row >= 0 && row < n2)
            {
                arr[line * n2 + row] = num++;
            }
        }

        // 4. 대각선 좌측 위 방향으로 R번 이동
        for (int i = 0; i < R; i++)
        {
            line--; row--; // 행 감소, 열 감소
            if (line >= 0 && line < n1 && row >= 0 && row < n2)
            {
                arr[line * n2 + row] = num++;
            }
        }

        // 5. 대각선 좌측 아래 방향으로 R번 이동
        for (int i = 0; i < R; i++)
        {
            line++; row--; // 행 증가, 열 감소
            if (line >= 0 && line < n1 && row >= 0 && row < n2)
            {
                arr[line * n2 + row] = num++;
            }
        }

        // 한 바퀴 돌아서 규칙 끝나면 반지름을 1 키워서 다음 마름모를 준비
        R++;
    }

    for (int i = 0; i < n1; i++)
    {
        for (int j = 0; j < n2; j++)
        {
            printf("%d\t ", arr[i * n2 + j]);
        }
        printf("\n");
    }

    // 메모리 누수 방지
    free(arr);

    return 0;
}