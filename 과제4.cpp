#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>//calloc, free 함수 라이브러리

int main() {
	int count = 0;
	int max = 0, min = 0;
	int sum = 0;

	printf("몇 개의 원소를 할당하겠습니까?: ");
	scanf("%d", &count);

	//원소의 개수가 0개 이하일 경우 프로그램 종료
	if (count <= 0) {
		printf("올바른 원소 개수를 입력해주세요.\n");
		return 1;
	}

	//입력받은 개수만큼 int형 크기의 메모리 할당 받고 0으로 초기화
	int* arr = (int*)calloc(count,sizeof(int));

	//NULL로 체크하여 메모리가 정상적으로 할당되었는지 확인
	if (arr == NULL) {
		printf("메모리 할당 실패\n");
		return 1;
	}

	for (int i = 0; i < count; i++) {
		printf("정수형 데이터 입력:");
		scanf("%d", &arr[i]);
	}

	max = arr[0];
	min = arr[0];

	for (int j = 0; j < count; j++) {
		sum += arr[j];

		if (max < arr[j]) {
			max = arr[j];
		}

		if (min > arr[j]) {
			min = arr[j];
		}
	}

	double avg = sum / count;

	printf("최댓값: %d\n", max);
	printf("최솟값: %d\n", min);
	printf("전체합: %d\n", sum);
	printf("평균: %f\n", avg);

	// 메모리 누수 방지
	free(arr);

	return 0;
}