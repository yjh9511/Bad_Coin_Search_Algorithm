#include "stdio.h"
#include "balance.h"
#include "stdlib.h"

#define TRUE 1
#define FALSE 0

int d1[2] = { 0,-1 };
int d2[2] = { 0,-1 };
int d3[2] = { 0,-1 };

int normal_coin[101];
int bad_coin[101];
int unsure_coin[101];

int normal_count = 0;
int bad_count = 0;
int unsure_count = 0;

int dummySet(int set[]);
void allNormalCoin(int set[]);
void allBadCoin(int set[]);
void compareAllCase(int result, int check);
int compare(const void* a, const void* b);

int main(){
	int a[4] = { 0, 0, 0, -1 };
	int b[4] = { 0, 0, 0, -1 };
	int c[4] = { 0, 0, 0, -1 };

	int last_index_bool = FALSE;
	int i = 0, j = 0, k = 0;


	//불량동전을 초기화한다. 이때 불량동전의 발생 확률 = 10
	initialize(2);
	
	for (i = 0; i < 99; i=i+9) {
	/* 0~8, 9~17 ... 89~98 까지 11개의 덩어리 */
		for (j = 0; j < 3; j++) {
			a[j] = i + j;
			b[j] = i + 3 + j;
			c[j] = i + 6 + j;
		}

		switch (balance(a, b, c)) {
		case ONE:	// b와 c에는 1개 이상의 불량 동전이 존재
			switch (dummySet(a)) {
			case ONE:	// 7 5 5 // b와 c는 모두 불량 동전
				compareAllCase(ONE, 0);
				allBadCoin(b);
				allBadCoin(c);
				break;
			case TWO:	// b와 c는 모두 불량 동전
				compareAllCase(TWO, 0);
				allBadCoin(b);
				allBadCoin(c);
				break;
			case THREE:	// b와 c는 모두 불량 동전
				compareAllCase(THREE, 0);
				allBadCoin(b);
				allBadCoin(c);
				break;
			case EQUAL_ONETWO:
				compareAllCase(EQUAL_ONETWO, 0);
				compareAllCase(dummySet(b), 1);
				compareAllCase(dummySet(c), 1);
				break;
			case EQUAL_ONETHREE:
				compareAllCase(EQUAL_ONETHREE, 0);
				compareAllCase(dummySet(b), 1);
				compareAllCase(dummySet(c), 1);
				break;
			case EQUAL_TWOTHREE:
				compareAllCase(EQUAL_TWOTHREE, 0);
				compareAllCase(dummySet(b), 1);
				compareAllCase(dummySet(c), 1);
				break;
			case EQUAL_ALL:
				allNormalCoin(a);
				compareAllCase(dummySet(b), 1);
				compareAllCase(dummySet(c), 1);
				break;
			default:
				printf("정의되지 않은 결과");
				break;
			}
			break;
		case TWO:
			switch (dummySet(b)) {
			case ONE:	// a와 c는 모두 불량 동전
				compareAllCase(ONE, 0);
				allBadCoin(a);
				allBadCoin(c);
				break;
			case TWO:	// a와 c는 모두 불량 동전
				compareAllCase(TWO, 0);
				allBadCoin(a);
				allBadCoin(c);
				break;
			case THREE:	// a와 c는 모두 불량 동전
				compareAllCase(THREE, 0);
				allBadCoin(a);
				allBadCoin(c);
				break;
			case EQUAL_ONETWO:
				compareAllCase(EQUAL_ONETWO, 0);
				compareAllCase(dummySet(a), 1);
				compareAllCase(dummySet(c), 1);
				break;
			case EQUAL_ONETHREE:
				compareAllCase(EQUAL_ONETHREE, 0);
				compareAllCase(dummySet(a), 1);
				compareAllCase(dummySet(c), 1);
				break;
			case EQUAL_TWOTHREE:
				compareAllCase(EQUAL_TWOTHREE, 0);
				compareAllCase(dummySet(a), 1);
				compareAllCase(dummySet(c), 1);
				break;
			case EQUAL_ALL:
				allNormalCoin(b);
				compareAllCase(dummySet(a), 1);
				compareAllCase(dummySet(c), 1);
				break;
			default:
				printf("정의되지 않은 결과");
				break;
			}
			break;
		case THREE:
			switch (dummySet(c)) {
			case ONE:	// a와 b는 모두 불량 동전
				compareAllCase(ONE, 0);
				allBadCoin(a);
				allBadCoin(b);
				break;
			case TWO:	// a와 b는 모두 불량 동전
				compareAllCase(TWO, 0);
				allBadCoin(a);
				allBadCoin(b);
				break;
			case THREE:	// a와 b는 모두 불량 동전
				compareAllCase(THREE, 0);
				allBadCoin(a);
				allBadCoin(b);
				break;
			case EQUAL_ONETWO:
				compareAllCase(EQUAL_ONETWO, 0);
				compareAllCase(dummySet(a), 1);
				compareAllCase(dummySet(b), 1);
				break;
			case EQUAL_ONETHREE:
				compareAllCase(EQUAL_ONETHREE, 0);
				compareAllCase(dummySet(a), 1);
				compareAllCase(dummySet(b), 1);
				break;
			case EQUAL_TWOTHREE:
				compareAllCase(EQUAL_TWOTHREE, 0);
				compareAllCase(dummySet(a), 1);
				compareAllCase(dummySet(b), 1);
				break;
			case EQUAL_ALL:
				allNormalCoin(c);
				compareAllCase(dummySet(a), 1);
				compareAllCase(dummySet(b), 1);
				break;
			default:
				printf("정의되지 않은 결과");
				break;
			}
			break;
		case EQUAL_ONETWO:	 // c에는 1개 이상의 불량 동전이 존재
			switch (dummySet(a)) {
			case ONE:	// 755 // c는 모두 불량
				compareAllCase(ONE, 0);
				compareAllCase(dummySet(b), 0);
				allBadCoin(c);
				break;
			case TWO:	// c는 모두 불량
				compareAllCase(TWO, 0);
				compareAllCase(dummySet(b), 0);
				allBadCoin(c);
				break;
			case THREE:	// c는 모두 불량
				compareAllCase(THREE, 0);
				compareAllCase(dummySet(b), 0);
				allBadCoin(c);
				break;
			case EQUAL_ONETWO:	// 7 7 5
				compareAllCase(EQUAL_ONETWO, 0);
				compareAllCase(dummySet(b), 0);
				compareAllCase(dummySet(c), 1);
				break;
			case EQUAL_ONETHREE:
				compareAllCase(EQUAL_ONETHREE, 0);
				compareAllCase(dummySet(b), 0);
				compareAllCase(dummySet(c), 1);
				break;
			case EQUAL_TWOTHREE:
				compareAllCase(EQUAL_TWOTHREE, 0);
				compareAllCase(dummySet(b), 0);
				compareAllCase(dummySet(c), 1);
				break;
			case EQUAL_ALL:	// 7 7 7
				allNormalCoin(a);
				allNormalCoin(b);
				compareAllCase(dummySet(c), 1);
				break;
			default:
				printf("정의되지 않은 결과");
				break;
			}
			break;
		case EQUAL_ONETHREE:	// b에는 1개 이상의 불량 동전이 존재
			switch (dummySet(a)) {
			case ONE:	// b는 모두 불량
				compareAllCase(ONE, 0);
				compareAllCase(dummySet(c), 0);
				allBadCoin(b);
				break;
			case TWO:	// b는 모두 불량
				compareAllCase(TWO, 0);
				compareAllCase(dummySet(c), 0);
				allBadCoin(b);
				break;
			case THREE:	// b는 모두 불량
				compareAllCase(THREE, 0);
				compareAllCase(dummySet(c), 0);
				allBadCoin(b);
				break;
			case EQUAL_ONETWO:	// 7 7 5
				compareAllCase(EQUAL_ONETWO, 0);
				compareAllCase(dummySet(c), 0);
				compareAllCase(dummySet(b), 1);
				break;
			case EQUAL_ONETHREE:
				compareAllCase(EQUAL_ONETHREE, 0);
				compareAllCase(dummySet(c), 0);
				compareAllCase(dummySet(b), 1);
				break;
			case EQUAL_TWOTHREE:
				compareAllCase(EQUAL_TWOTHREE, 0);
				compareAllCase(dummySet(c), 0);
				compareAllCase(dummySet(b), 1);
				break;
			case EQUAL_ALL:	// 7 7 7
				allNormalCoin(a);
				allNormalCoin(c);
				compareAllCase(dummySet(b), 1);
				break;
			default:
				printf("정의되지 않은 결과");
				break;
			}
			break;
		case EQUAL_TWOTHREE:	// a에는 1개 이상의 불량 동전이 존재
			switch (dummySet(b)) {
			case ONE:	// a는 모두 불량
				compareAllCase(ONE, 0);
				compareAllCase(dummySet(c), 0);
				allBadCoin(a);
				break;
			case TWO:	// a는 모두 불량
				compareAllCase(TWO, 0);
				compareAllCase(dummySet(c), 0);
				allBadCoin(a);
				break;
			case THREE:	// a는 모두 불량
				compareAllCase(THREE, 0);
				compareAllCase(dummySet(c), 0);
				allBadCoin(a);
				break;
			case EQUAL_ONETWO: // 7 7 5
				compareAllCase(EQUAL_ONETWO, 0);
				compareAllCase(dummySet(c), 0);
				compareAllCase(dummySet(a), 1);
				break;
			case EQUAL_ONETHREE:
				compareAllCase(EQUAL_ONETHREE, 0);
				compareAllCase(dummySet(c), 0);
				compareAllCase(dummySet(a), 1);
				break;
			case EQUAL_TWOTHREE:
				compareAllCase(EQUAL_TWOTHREE, 0);
				compareAllCase(dummySet(c), 0);
				compareAllCase(dummySet(a), 1);
				break;
			case EQUAL_ALL:	// 7 7 7
				allNormalCoin(b);
				allNormalCoin(c);
				compareAllCase(dummySet(a), 1);
				break;
			default:
				printf("정의되지 않은 결과");
				break;
			}
			break;
		case EQUAL_ALL:
			switch (dummySet(a)) {
			case ONE:
				compareAllCase(ONE, 0);
				compareAllCase(dummySet(b), 0);
				compareAllCase(dummySet(c), 0);
				break;
			case TWO:
				compareAllCase(TWO, 0);
				compareAllCase(dummySet(b), 0);
				compareAllCase(dummySet(c), 0);
				break;
			case THREE:
				compareAllCase(THREE, 0);
				compareAllCase(dummySet(b), 0);
				compareAllCase(dummySet(c), 0);
				break;
			case EQUAL_ONETWO:
				compareAllCase(EQUAL_ONETWO, 0);
				compareAllCase(dummySet(b), 0);
				compareAllCase(dummySet(c), 0);
				break;
			case EQUAL_ONETHREE:
				compareAllCase(EQUAL_ONETHREE, 0);
				compareAllCase(dummySet(b), 0);
				compareAllCase(dummySet(c), 0);
				break;
			case EQUAL_TWOTHREE:
				compareAllCase(EQUAL_TWOTHREE, 0);
				compareAllCase(dummySet(b), 0);
				compareAllCase(dummySet(c), 0);
				break;
			case EQUAL_ALL:	
				unsure_coin[unsure_count] = a[0];
				unsure_count = unsure_count + 1;
				break;
			default:
				printf("정의되지 않은 결과");
				break;
			}
			break;
		default:
			printf("정의되지 않은 결과!\n");
			break;
		}
	}

	// 상황 1 : 모두 unsure에 해당된 경우 + unsure은 모두 정상 99만 불량, unsure => 11개 
	// 상황 2 : 적절히 분배가 된 경우
	// 상황 3 : unsure이 없는 경우

	/*unsure의 마지막 공간에 99인덱스 삽입
	  경우의 수 : 
	 		1. unsure 원소 12개(모두 unsure)
	 			1. unsure 내의 0~2, 3~5, 6~8, 9~11로 구분
	 			2. 0,3,6 비교
					1. 모두 같은 경우
					2. 하나라도 다른 경우
				3. 9, 10, 11 비교
					1. 1-2에서 정해진 규칙에 따라 비교
	 		2. normal과 bad중 하나라도 정해진 것이 있는 경우
	 */

	qsort(bad_coin, bad_count, sizeof(int), compare);
	qsort(normal_coin, normal_count, sizeof(int), compare);

	
	/*
	bad_coin[bad_count] = -1;
	d2[0] = -1;
	d3[0] = -1;
	balance(bad_coin, d2, d3);
	*/
	
	printf("\n\nINDEX : ");
	for (i = 0; i < bad_count; i++) {
		printf("%d,  ", bad_coin[i]);
	}
	printf("\n\n");

	printf("\n불량동전 = %d 개\n\n", bad_count);
	
	printf("정상 동전 : %d 개\n ", normal_count);
	for (i = 0; i < normal_count; i++) {
		printf("%d ", normal_coin[i]);
	}
	printf("\n\n");

	printf("Unsure Index: ");
	for (i = 0; i < unsure_count; i++) {
		printf("%d ", unsure_coin[i]);
	}
	printf("\n\n");


	printf("\n\n");
	return 0;
}

int dummySet(int set[]) {
	d1[0] = set[0];
	d2[0] = set[1];
	d3[0] = set[2];

	return balance(d1, d2, d3);
}

void allNormalCoin(int set[]) {
	int i = 0;

	for (i = 0; i < 3; i++) {
		normal_coin[normal_count] = set[i];
		normal_count = normal_count + 1;
	}
}

void allBadCoin(int set[]) {
	int i = 0;

	for (i = 0; i < 3; i++) {
		bad_coin[bad_count] = set[i];
		bad_count = bad_count + 1;
	}
}

void compareAllCase(int result, int check) {
	switch (result) {
	case ONE:
		normal_coin[normal_count] = d1[0];
		bad_coin[bad_count] = d2[0];
		bad_coin[bad_count + 1] = d3[0];

		normal_count = normal_count + 1;
		bad_count = bad_count + 2;
		break;
	case TWO:
		normal_coin[normal_count] = d2[0];
		bad_coin[bad_count] = d1[0];
		bad_coin[bad_count + 1] = d3[0];

		normal_count = normal_count + 1;
		bad_count = bad_count + 2;
		break;
	case THREE:
		normal_coin[normal_count] = d3[0];
		bad_coin[bad_count] = d1[0];
		bad_coin[bad_count + 1] = d2[0];

		normal_count = normal_count + 1;
		bad_count = bad_count + 2;
		break;
	case EQUAL_ONETWO:
		normal_coin[normal_count] = d1[0];
		normal_coin[normal_count + 1] = d2[0];
		bad_coin[bad_count] = d3[0];

		normal_count = normal_count + 2;
		bad_count = bad_count + 1;
		break;
	case EQUAL_ONETHREE:
		normal_coin[normal_count] = d1[0];
		normal_coin[normal_count + 1] = d3[0];
		bad_coin[bad_count] = d2[0];

		normal_count = normal_count + 2;
		bad_count = bad_count + 1;
		break;
	case EQUAL_TWOTHREE:
		normal_coin[normal_count] = d2[0];
		normal_coin[normal_count + 1] = d3[0];
		bad_coin[bad_count] = d1[0];

		normal_count = normal_count + 2;
		bad_count = bad_count + 1;
		break;
	case EQUAL_ALL:
		if (check == 0) {
			normal_coin[normal_count] = d1[0];
			normal_coin[normal_count + 1] = d2[0];
			normal_coin[normal_count + 2] = d3[0];

			normal_count = normal_count + 3;
		}
		else if (check == 1) {
			bad_coin[bad_count] = d1[0];
			bad_coin[bad_count + 1] = d2[0];
			bad_coin[bad_count + 2] = d3[0];

			bad_count = bad_count + 3;
		}
		else 
			printf("정의되지 않은 결과");
		break;
	default:
		printf("정의되지 않은 결과");
		break;
	}
}

int compare(const void* a, const void* b)
{
	if (*(int *)a > *(int *)b)
		return 1;
	else if (*(int *)a < *(int *)b)
		return -1;
	else
		return 0;
}