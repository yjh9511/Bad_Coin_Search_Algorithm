#include "stdio.h"
#include "balance.h"
#include "windows.h"

#define TURE 1
#define FALSE 0

/*
	항상 51 회 탐색으로 불량동전을 탐색하는 알고리즘

	* 조건
	최소 1개 이상의 동전이 불량이다.
	모든 동전이 불량이거나, 정상인 경우는 제외한다

	* 동작 방법
	1. 동전 세트의 0번 인덱스를 pivot으로 잡는다.
	2. pivot위치의 동전은 dummyA 배열의 0번 인덱스에 저장한다.
	3. pivot과 i(초기 i는 1), i+1번 인덱스의 무게를 비교한다.
	4. pivot과 무게가 같으면 dummyA, 다르면 dummyB에 들어간다.
	5. i값이 2씩 증가하므로 마지막 인덱스 99의 경우는 피봇, 인덱스 99, dummyA와 dummyB중 길이가 긴 배열의 인덱스 1값과 비교한다.
	6. 무게 비교 과정에서 pivot 위치의 동전이 확실하게 불량이라고 판단되면 pivot_bool_test 값을 FALSE로 세팅한다.
	7. pivot_bool_test 값으로 dummyA와 dummyB중 어떤 것이 불량동전으로 이루어진 배열인지 판단하여 마지막 balance를 수행한다.
*/

int main(){
	int a[2] = { 0, -1 };
	int b[2] = { NULL, -1 };
	int c[2] = { NULL, -1 };
	int dummyA[100];
	int dummyB[100];
	int i,j=1,k=0;
	int pivot_bool_test = TRUE;

	initialize(10);	// 불량동전을 초기화
	
	dummyA[0] = 0;	// dummyA[0]에는 항상 pivot 인덱스인 0이 들어감

	for (i = 1; i < 98; i=i+2) {
		b[0] = i;
		c[0] = i+1;
		
		// 무게가 같은 인덱스 끼리 분류
		switch (balance(a, b, c)) {
		case ONE:				// 7 5 5
			dummyB[k] = b[0];
			dummyB[k + 1] = c[0];
			k = k + 2;
			break;
		case TWO:				// 5 7 5
			pivot_bool_test = FALSE;
			dummyA[j] = c[0];
			j = j + 1;
			dummyB[k] = b[0];
			k = k + 1;
			break;
		case THREE:				// 5 5 7
			pivot_bool_test = FALSE;
			dummyA[j] = b[0];
			j = j + 1;
			dummyB[k] = c[0];
			k = k + 1;
			break;
		case EQUAL_ONETWO:		// 7 7 5
			dummyA[j] = b[0];
			j = j + 1;
			dummyB[k] = c[0];
			k = k + 1;
			break;
		case EQUAL_TWOTHREE:	// 5 7 7
			pivot_bool_test = FALSE;
			dummyB[k] = b[0];
			dummyB[k + 1] = c[0];
			k = k + 2;
			break;
		case EQUAL_ONETHREE:	// 7 5 7
			dummyA[j] = c[0];
			j = j + 1;
			dummyB[k] = b[0];
			k = k + 1;
			break;
		case EQUAL_ALL:			// 5 5 5 or 7 7 7
			dummyA[j] = b[0];
			dummyA[j + 1] = c[0];
			j = j + 2;
			break;
		default:
			printf("정의되지 않은 결과\n");
			break;
		}
	}

	// 99번째 인덱스 테스트
	c[0] = 99;
	if (j >= k) {
		b[0] = dummyA[1];

		switch (balance(a, b, c)) {
		case EQUAL_ALL:		// 5 5 5 or 7 7 7
			dummyA[j] = 99;
			j = j + 1;
			break;
		case EQUAL_ONETWO:	// 7 7 5
			dummyB[k] = 99;
			k = k + 1;
			break;
		case THREE:			// 5 5 7
			dummyB[j] = 99;
			k = k + 1;
			pivot_bool_test = FALSE;
			break;
		default:
			printf("정의되지 않은 결과\n");
			break;
		}
	}
	else {
		b[0] = dummyB[1];
		switch (balance(a, b, c)) {
		case ONE: // 7 5 5
			dummyB[k] = 99;
			k = k + 1;
			break;
		case TWO: // 5 7 5
			dummyA[j] = 99;
			j = j + 1;
			pivot_bool_test = FALSE;
			break;
		case EQUAL_ONETHREE:	// 7 5 7
			dummyA[j] = 99;
			j = j + 1;
			break;
		case EQUAL_TWOTHREE: // 5 7 7
			dummyB[k] = 99;
			k = k + 1;
			pivot_bool_test = FALSE;
			break;
		default:
			printf("정의되지 않은 결과\n");
			break;
		}
	}

	b[0] = -1;
	c[0] = -1;
	dummyA[j] = -1;
	dummyB[k] = -1;

	if (pivot_bool_test == TRUE)	// 인덱스 0의 동전의 무게가 7
		balance(dummyB, b, c);
	else
		balance(dummyA, b, c);

	system("pause");
	return 0;
}