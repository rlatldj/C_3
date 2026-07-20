#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char input[1000];
    printf("입력 : ");
    scanf("%s", input);

    // 500 크기의 메모리 할당(0으로 초기화는 없음)
    int* stack = (int*)malloc(sizeof(int) * 500);
    if (stack == NULL) {
        printf("메모리 할당 실패\n");
        return 1;
    }

    int top = 0; // 스택 인덱스이자 들여쓰기 깊이
    int i = 0;   // 탐색 인덱스

    printf("출력 :\n");

    while (input[i] != '\0')
    {
        int j = i;
        int close = (input[i] == '<' && input[i + 1] == '/');
        int open = (input[i] == '<' && input[i + 1] != '/');

        // 현재 텍스트가 끝나는 지점을 먼저 찾기
        if (input[i] == '<') {
            while (input[j] != '>' && input[j] != '\0') {
                j++;
            }

            if (input[j] == '\0') {
                printf("\n잘못된 태그 구조입니다. ('>' 누락)\n");
                free(stack); return 1;
            }
        }
        else {
            while (input[j] != '<' && input[j] != '\0') {
                j++;
            }
        }

        // 닫는 태그라면 출력 전에 미리 검사하고 데이터 꺼내기 수행
        if (close) {
            if (top == 0) {
                printf("\n잘못된 태그 구조입니다. (열린 태그 없음)\n");
                free(stack); return 1;
            }
            //pop(데이터 꺼내기)
            top--;
            int open_start = stack[top];
            int close_start = i + 2;

            int m = 0;
            while (input[open_start + m] != '>' && input[close_start + m] != '>') {
                if (input[open_start + m] != input[close_start + m]) 
                    break;
                m++;
            }
            if (input[open_start + m] != '>' || input[close_start + m] != '>') {
                printf("\n잘못된 태그 구조입니다. (태그 미스매치)\n");
                free(stack); return 1;
            }
        }

        // 들여쓰기 공백 출력
        for (int s = 0; s < top; s++) printf("  ");

        // 글자 화면 출력 (태그면 j까지, 텍스트면 j 바로 전까지)
        int end_bound = (input[i] == '<') ? j : j - 1;
        for (int m = i; m <= end_bound; m++) {
            printf("%c", input[m]);
        }
        printf("\n");

        // 여는 태그였다면 출력을 마친 뒤 스택에 데이터 집어넣기 수행
        if (open) {
            //push(데이터 집어넣기)
            stack[top] = i + 1;
            top++;
        }

        // 다음 덩어리가 시작되는 위치로 이동
        i = (input[i] == '<') ? j + 1 : j;
    }

    // 최종 검사: 닫히지 않은 태그가 남았는지 확인
    if (top != 0) {
        printf("\n잘못된 태그 구조입니다. (닫히지 않은 태그 존재)\n");
        free(stack);
        return 1;
    }

    free(stack);
    return 0;
}