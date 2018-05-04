#include "stdio.h"
#include "balance.h"
#include "stdlib.h"

int compare(const void* a, const void* b);

extern int coin[];

int main(){
	int a[2] = { 0, -1 };
	int b[2] = { 0, -1 };
	int c[2] = { 0, -1 };
	int d[4] = { 0,0,0,-1 };
	int e[4] = { 0,0,0,-1 };
	int f[4] = { 0,0,0,-1 };
	int normal_coin[100];
	int bad_coin[100];
	int unsure[100];
	int unsure_second[100];
	int unsure_sec_count = 0;
	int normal_count = 0, bad_count = 0, unsure_count = 0;
	int i = 0, j = 0, k = 0;
	float percentage=0;


	//불량동전을 초기화한다. 이때 불량동전의 발생 확률 = 10
	initialize(25);

	for (i = 0; i < 99; i=i+3) {
		a[0] = i;
		b[0] = i + 1;
		c[0] = i + 2;

		switch (balance(a, b, c)) {
		case ONE:
			normal_coin[normal_count] = a[0];
			bad_coin[bad_count] = b[0];
			bad_coin[bad_count+1] = c[0];

			normal_count++;
			bad_count = bad_count + 2;
			break;
		case TWO:
			normal_coin[normal_count] = b[0];
			bad_coin[bad_count] = a[0];
			bad_coin[bad_count+1] = c[0];

			normal_count++;
			bad_count = bad_count + 2;
			break;
		case THREE:
			normal_coin[normal_count] = c[0];
			bad_coin[bad_count] = a[0];
			bad_coin[bad_count+1] = b[0];

			normal_count++;
			bad_count = bad_count + 2;
			break;
		case EQUAL_ONETWO:
			normal_coin[normal_count] = a[0];
			normal_coin[normal_count+1] = b[0];
			bad_coin[bad_count] = c[0];

			normal_count = normal_count + 2;
			bad_count++;
			break;
		case EQUAL_ONETHREE:
			normal_coin[normal_count] = a[0];
			normal_coin[normal_count+1] = c[0];
			bad_coin[bad_count] = b[0];

			normal_count = normal_count + 2;
			bad_count++;
			break;
		case EQUAL_TWOTHREE:
			normal_coin[normal_count] = b[0];
			normal_coin[normal_count+1] = c[0];
			bad_coin[bad_count] = a[0];

			normal_count = normal_count + 2;
			bad_count++;
			break;
		case EQUAL_ALL:
			unsure[unsure_count] = a[0];
			unsure_count++;
			break;
		default:
			printf("정의되지 않은 결과88");
			break;
		}

		if (i % 30==0) {
			percentage = ((float)bad_count / (float)(bad_count + normal_count)) * 100;
			printf("\npercent : %f %% \n", percentage);
			printf("\n 불량 : %d 개\n", bad_count);
			printf("\n 정상 : %d 개\n", normal_count);
			printf("\n 모름 : %d 개\n", unsure_count);
			printf("\n 많이 모름 : %d 개\n", unsure_sec_count);
		}
	}

	percentage = ((float)bad_count / (float)(bad_count + normal_count))*100;
	printf("percent : %f %% \n\n", percentage);

	if (percentage <= 40) {
		for (i = 0; i < unsure_count; i++) {
			for (j = 0; j < 3; j++) {
				normal_coin[normal_count] = unsure[i] + j;
				normal_count++;
			}
		}
	}
	else if (percentage >= 60) {
		for (i = 0; i < unsure_count; i++) {
			for (j = 0; j < 3; j++) {
				bad_coin[bad_count] = unsure[i] + j;
				bad_count++;
			}
		}
	}
	else {	// 중간 확률 경우
		for (j = 0; j < unsure_count; j = j + 3) {
			if ((j + 3) > unsure_count)
				break;

			a[0] = unsure[j];
			b[0] = unsure[j + 1];
			c[0] = unsure[j + 2];
			switch (balance(a, b, c)) {
			case ONE:
				for (k = 0; k < 3; k++) {
					normal_coin[normal_count] = a[0] + k;
					bad_coin[bad_count] = b[0] + k;
					bad_coin[bad_count + 1] = c[0] + k;

					normal_count++;
					bad_count = bad_count + 2;
				}
				break;
			case TWO:
				for (k = 0; k < 3; k++) {
					normal_coin[normal_count] = b[0] + k;
					bad_coin[bad_count] = a[0] + k;
					bad_coin[bad_count + 1] = c[0] + k;

					normal_count++;
					bad_count = bad_count + 2;
				}
				break;
			case THREE:
				for (k = 0; k < 3; k++) {
					normal_coin[normal_count] = c[0] + k;
					bad_coin[bad_count] = a[0] + k;
					bad_coin[bad_count + 1] = b[0] + k;

					normal_count++;
					bad_count = bad_count + 2;
				}
				break;
			case EQUAL_ONETWO:
				for (k = 0; k < 3; k++) {
					normal_coin[normal_count] = a[0] + k;
					normal_coin[normal_count + 1] = b[0] + k;
					bad_coin[bad_count] = c[0] + k;

					normal_count = normal_count + 2;
					bad_count++;
				}
				break;
			case EQUAL_ONETHREE:
				for (k = 0; k < 3; k++) {
					normal_coin[normal_count] = a[0] + k;
					normal_coin[normal_count + 1] = c[0] + k;
					bad_coin[bad_count] = b[0] + k;

					normal_count = normal_count + 2;
					bad_count++;
				}
				break;
			case EQUAL_TWOTHREE:
				for (k = 0; k < 3; k++) {
					normal_coin[normal_count] = b[0] + k;
					normal_coin[normal_count + 1] = c[0] + k;
					bad_coin[bad_count] = a[0] + k;

					normal_count = normal_count + 2;
					bad_count++;
				}
				break;
			case EQUAL_ALL:	// 항상 3의 배수로 존재
				unsure_second[unsure_sec_count] = a[0];
				unsure_second[unsure_sec_count + 1] = b[0];
				unsure_second[unsure_sec_count + 2] = c[0];
				unsure_sec_count = unsure_sec_count + 3;
				break;
			default:
				printf("정의되지 않은 결과196");
				break;
			}
		}

		// 3으로 나눠 떨어지지 않을 때
		if ((unsure_count % 3) == 1) {	// 1개 남음
			a[0] = normal_coin[0];
			b[0] = normal_coin[1];
			c[0] = unsure[unsure_count - 1];

			switch (balance(a, b, c)) {
			case EQUAL_ONETWO:
				for (k = 0; k < 3; k++) {
					bad_coin[bad_count] = c[0] + k;
					bad_count++;
				}
				break;
			case EQUAL_ALL:
				for (k = 0; k < 3; k++) {
					normal_coin[normal_count] = c[0] + k;
					normal_count++;
				}
				break;
			default:
				printf("정의되지 않은 결과221");
				break;
			}
		}
		else if ((unsure_count % 3) == 2) {
			a[0] = normal_coin[0];
			b[0] = unsure[unsure_count - 2];
			c[0] = unsure[unsure_count - 1];

			switch (balance(a, b, c)) {
			case ONE:
				for (k = 0; k < 3; k++) {
					bad_coin[bad_count] = b[0] + k;
					bad_coin[bad_count + 1] = c[0] + k;
					bad_count = bad_count + 2;
				}
				break;
			case EQUAL_ONETWO:
				for (k = 0; k < 3; k++) {
					normal_coin[normal_count] = b[0] + k;
					bad_coin[bad_count] = c[0] + k;

					normal_count++;
					bad_count++;
				}
				break;
			case EQUAL_ONETHREE:
				for (k = 0; k < 3; k++) {
					normal_coin[normal_count] = c[0] + k;
					bad_coin[bad_count] = b[0] + k;

					normal_count++;
					bad_count++;
				}
				break;
			case EQUAL_ALL:
				for (k = 0; k < 3; k++) {
					normal_coin[normal_count] = b[0] + k;
					normal_coin[normal_count + 1] = c[0] + k;

					normal_count=normal_count+2;
				}
				break;
			default:
				printf("정의되지 않은 결과265");
				break;
			}
		}

		if (unsure_sec_count !=0) {
			e[0] = normal_coin[0];
			e[1] = normal_coin[1];
			e[2] = normal_coin[2];
			f[0] = normal_coin[3];
			f[1] = normal_coin[4];
			f[2] = normal_coin[5];
			
			for (k = 0; k < unsure_sec_count; k = k + 3) {
				d[0] = unsure_second[k];
				d[1] = unsure_second[k + 1];
				d[2] = unsure_second[k + 2];

				switch (balance(e, f, d)) {
				case EQUAL_ONETWO:
					for (j = 0; j < 3; j++) {
						bad_coin[bad_count] = d[0] + j;
						bad_coin[bad_count+1] = d[1] + j;
						bad_coin[bad_count+2] = d[2] + j;
						bad_count = bad_count + 3;
					}
					break;
				case EQUAL_ALL:
					for (j = 0; j < 3; j++) {
						normal_coin[normal_count] = d[0] + j;
						normal_coin[normal_count + 1] = d[1] + j;
						normal_coin[normal_count + 2] = d[2] + j;
						normal_count = normal_count + 3;
					}
					break;
				default:
					printf("정의되지 않은 결과301");
					break;
				}
			}
		}
	}

	a[0] = normal_coin[0];
	b[0] = normal_coin[1];
	c[0] = 99;

	switch (balance(a, b, c)) {
	case EQUAL_ONETWO:
		bad_coin[bad_count] = c[0];
		bad_count++;
		break;
	case EQUAL_ALL:
		normal_coin[normal_count] = c[0];
		normal_count++;
		break;
	default:
		printf("정의되지 않은 결과322");
		break;
	}

	qsort(bad_coin, bad_count, sizeof(int), compare);
	qsort(normal_coin, normal_count, sizeof(int), compare);
	
	printf("\n\n 불량 동전 : \n");
	for (i = 0; i < bad_count; i++) {
		printf("%d  ,", bad_coin[i]);
	}

	printf("\n\n 정상 동전 : \n");
	for (i = 0; i < normal_count; i++) {
		printf("%d  ,", normal_coin[i]);
	}
	printf("\n\n 불량 : %d 개\n\n", bad_count);
	printf("\n\n 정상 : %d 개\n\n", normal_count);
	printf("\n\n 모름 : %d 개\n\n", unsure_count);
	printf("\n\n 많이 모름 : %d 개\n\n", unsure_sec_count);

	bad_coin[bad_count] = -1;
	b[0] = -1;
	c[0] = -1;

	balance(bad_coin,b,c);

	return 0;
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