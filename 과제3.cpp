#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> // malloc, free 함수 사용을 위한 라이브러리 추가

int main(void)
{
    int n1, n2;

    printf("행렬의 크기 N1과 N2를 입력하세요: ");
    scanf("%d %d", &n1, &n2);

    // 행과 열의 입력값이 0 이하일 경우 프로그램 종료
    if (n1 <= 0 || n2 <= 0)
    {
        printf("올바른 크기를 입력해주세요.\n");
        return 1;
    }

    // n1 * n2 크기의 메모리 할당받고 0으로 초기화
    int* arr = (int*)calloc(n1 * n2, sizeof(int));

    // 메모리가 정상적으로 할당되지 않았을 경우
    if (arr == NULL)
    {
        printf("malloc error\n");
        return 0;
    }

    // 달팽이 모양 배열 탐색 및 숫자 채우기
    int line = 0;        // 시작 행 (0행)
    int row = 0;         // 시작 열 (0열)
    int num = 1;
    int total = n1 * n2; // 채워야 할 총 원소 개수

    // 모든 칸에 숫자가 채워질 때까지 우->하->좌->상 순서대로 반복
    while (num <= total)
    {
        // 1. 우측 이동: 열을 증가시키며 벽을 만나거나 이미 숫자가 채워진 칸 직전까지 전진
        //arr[line * n2 + row] -> line * n2: 행 위치, row: 열 위치로 2차원 배열처럼 쓰기 위해 사용한 계산공식([행 * 가로크기 + 열])
        while (row < n2 && num <= total && arr[line * n2 + row] == 0)
        {
            arr[line * n2 + row] = num++;
            row++;
        }
        // 원래대로라면 벽을 뚫었거나 숫자가 있는 칸 위에 서 있으므로, 
        // 안전하게 한 칸 왼쪽으로 이동한 뒤 다음 단계인 아래 행으로 이동
        row--;
        line++;

        // 하단 이동: 행을 증가시키며 전진
        while (line < n1 && num <= total && arr[line * n2 + row] == 0)
        {
            arr[line * n2 + row] = num++;
            line++;
        }
        // 범위를 벗어났으므로 한 칸 위로 올라가고, 왼쪽 열로 이동
        line--;
        row--;

        // 좌측 이동: 열을 감소시키며 전진
        while (row >= 0 && num <= total && arr[line * n2 + row] == 0)
        {
            arr[line * n2 + row] = num++;
            row--;
        }
        // 범위를 벗어났으므로 한 칸 오른쪽으로 이동하고, 위쪽 행으로 이동
        row++;
        line--;

        // 4. 행을 감소시키며 전진
        while (line >= 0 && num <= total && arr[line * n2 + row] == 0)
        {
            arr[line * n2 + row] = num++;
            line--;
        }
        // 범위를 벗어났으므로 한 칸 아래로 이동하고 오른쪽 열로 이동하여 다음 사이클을 준비
        line++;
        row++;
    }

    for (int i = 0; i < n1; i++)
    {
        for (int j = 0; j < n2; j++)
        {
            // 숫자가 예쁘게 정렬되도록 \t를 사용
            printf("%d\t ", arr[i * n2 + j]);
        }
        printf("\n");
    }

    // 동적할당으로 생성된 메모리는 사용 후 반드시 해제하여 메모리 누수 방지
    free(arr);

    return 0;
}