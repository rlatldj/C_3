#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> // 동적할당 라이브러리 추가

int main() {
	int N;
	int num = 1;

	printf("정사각형 배열의 크기를 입력하세요: ");
	scanf("%d", &N);

	//배열의 크기를 잘못 입력했을 때
	if (N <= 0) {
		printf("잘못 입력하셨습니다.");
		return 1;
	}

	//동적할당 calloc이용해 정사각형 넓이 N*N크기의 메모리 할당
	int* arr = (int*)calloc(N * N, sizeof(int));
	// 메모리가 정상적으로 할당되었는지 확인
	if (arr == NULL) {
		printf("메모리 할당 실패");
		return 1;
	}

	// 대각선의 합 규칙을 이용해 숫자 채우기
	// 대각선의 합은 0 ~ (2 * N -2)까지 증가
	//행과 열을 더한 값이 같은 칸들을 모으면 대각선 라인이 만들어지는 규칙을 이용
	for (int i = 0; i <= 2 * N - 2; i++) {
		for (int j = 0; j < N; j++) {
			int k = i - j;
			
			// 계산된 값이 배열의 유효한 법위에 있는지 확인
			if (k >= 0 && k < N) {
				// j*N은 행 k는 열의 위치를 포함하고 있음
				arr[j * N + k] = num++;
			}
		}
	}

	// 배열 출력
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			// i*N 행/ j 열
			printf("%d\t", arr[i * N + j]);
		}
		printf("\n");
	}

	free(arr);

	return 0;
}