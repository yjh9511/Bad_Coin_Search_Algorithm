#include "stdio.h"
#include "balance.h"
#include "stdlib.h"

#define TRUE	1
#define FALSE	0

int compare(const void* a, const void* b);

int dummySet(int set[]);
void allNormalCoin(int set[]);
void allBadCoin(int set[]);
void compareAllCase(int result, int check);

int normal_coin[100];
int bad_coin[100];
int unsure_coin_3compare[101];
int unsure_count_3compare = 0;
int normal_count = 0, bad_count = 0;

int dum1[2] = { 0,-1 };
int dum2[2] = { 0,-1 };
int dum3[2] = { 0,-1 };

extern int coin[];

int main() {

	int a[2] = { 0, -1 };
	int b[2] = { 0, -1 };
	int c[2] = { 0, -1 };
	int d[4] = { 0,0,0,-1 };
	int e[4] = { 0,0,0,-1 };
	int f[4] = { 0,0,0,-1 };
	int a3[4] = { 0, 0, 0, -1 };
	int b3[4] = { 0, 0, 0, -1 };
	int c3[4] = { 0, 0, 0, -1 };

	int unsure[100];
	int unsure_second[100];
	int unsure_sec_count = 0;
	int unsure_count = 0;
	int i = 0, j = 0, k = 0;
	float percentage = 0;
	int bool_test = TRUE;
	float x;
	float y;
	int one_count=0;
	int three_count=0;

	//�ҷ������� �ʱ�ȭ�Ѵ�. �̶� �ҷ������� �߻� Ȯ�� = 10
	initialize(35);

	for (i = 0; i < 9; i=i + 3) {
		a[0] = i;
		b[0] = i + 1;
		c[0] = i + 2;
		switch (balance(a, b, c)) {
		case ONE:
			normal_coin[normal_count] = a[0];
			bad_coin[bad_count] = b[0];
			bad_coin[bad_count + 1] = c[0];

			normal_count++;
			bad_count = bad_count + 2;
			break;
		case TWO:
			normal_coin[normal_count] = b[0];
			bad_coin[bad_count] = a[0];
			bad_coin[bad_count + 1] = c[0];

			normal_count++;
			bad_count = bad_count + 2;
			break;
		case THREE:
			normal_coin[normal_count] = c[0];
			bad_coin[bad_count] = a[0];
			bad_coin[bad_count + 1] = b[0];

			normal_count++;
			bad_count = bad_count + 2;
			break;
		case EQUAL_ONETWO:
			normal_coin[normal_count] = a[0];
			normal_coin[normal_count + 1] = b[0];
			bad_coin[bad_count] = c[0];

			normal_count = normal_count + 2;
			bad_count++;
			break;
		case EQUAL_ONETHREE:
			normal_coin[normal_count] = a[0];
			normal_coin[normal_count + 1] = c[0];
			bad_coin[bad_count] = b[0];

			normal_count = normal_count + 2;
			bad_count++;
			break;
		case EQUAL_TWOTHREE:
			normal_coin[normal_count] = b[0];
			normal_coin[normal_count + 1] = c[0];
			bad_coin[bad_count] = a[0];

			normal_count = normal_count + 2;
			bad_count++;
			break;
		case EQUAL_ALL:
			unsure[unsure_count] = a[0];
			unsure_count++;
			break;
		default:
			printf("���ǵ��� ���� ���");
			break;
		}
	}

	while (1) {
		
		if (i == 99)
			break;
		/*
		percentage = (((float)normal_count + (float)bad_count) / (i)) * 100;
		printf("%d %d %d %f",bad_count,normal_count,i ,percentage);
		*/
		/*
		y = unsure_count + (3*unsure_count_3compare);
		if (normal_count != 0 && bad_count != 0) {
			if (normal_count >= bad_count)
				x = ((float)normal_count+y)  / (float)bad_count;
			else
				x = ((float)bad_count+y) / (float)normal_count;
		}
		else
			x = 3;
			*/
		printf("%d %d %f %d\n", normal_count, bad_count, ((float)bad_count / (float)(bad_count + normal_count) * 100), i);
		printf("%d %d \n", unsure_count, unsure_count_3compare);
		if ((((float)bad_count / (float)(bad_count + normal_count) * 100) <= 66 && ((float)bad_count / (float)(bad_count + normal_count) * 100) >= 33)&& (((float)(bad_count + normal_count) / (float)(i)) * 100) >= 65) {
			for (j = i ; j < i+9; j=j + 3) {
				a[0] = j;
				b[0] = j + 1;
				c[0] = j + 2;
				switch (balance(a, b, c)) {
				case ONE:
					normal_coin[normal_count] = a[0];
					bad_coin[bad_count] = b[0];
					bad_coin[bad_count + 1] = c[0];

					normal_count++;
					bad_count = bad_count + 2;
					break;
				case TWO:
					normal_coin[normal_count] = b[0];
					bad_coin[bad_count] = a[0];
					bad_coin[bad_count + 1] = c[0];

					normal_count++;
					bad_count = bad_count + 2;
					break;
				case THREE:
					normal_coin[normal_count] = c[0];
					bad_coin[bad_count] = a[0];
					bad_coin[bad_count + 1] = b[0];

					normal_count++;
					bad_count = bad_count + 2;
					break;
				case EQUAL_ONETWO:
					normal_coin[normal_count] = a[0];
					normal_coin[normal_count + 1] = b[0];
					bad_coin[bad_count] = c[0];

					normal_count = normal_count + 2;
					bad_count++;
					break;
				case EQUAL_ONETHREE:
					normal_coin[normal_count] = a[0];
					normal_coin[normal_count + 1] = c[0];
					bad_coin[bad_count] = b[0];

					normal_count = normal_count + 2;
					bad_count++;
					break;
				case EQUAL_TWOTHREE:
					normal_coin[normal_count] = b[0];
					normal_coin[normal_count + 1] = c[0];
					bad_coin[bad_count] = a[0];

					normal_count = normal_count + 2;
					bad_count++;
					break;
				case EQUAL_ALL:
					unsure[unsure_count] = a[0];
					unsure_count++;
					break;
				default:
					printf("���ǵ��� ���� ���");
					break;
				}
			}
			i = i + 9;
			one_count++;
		}
		else {
				for (j = 0; j < 3; j++) {
					a3[j] = i + j; //9 10 11  ...90 91 92
					b3[j] = i + 3 + j;//12 13 14  ... 93 94 95
					c3[j] = i + 6 + j;//15 16 17 ... 96 97 98
				}
				switch (balance(a3, b3, c3)) {
				case ONE:	// b�� c���� 1�� �̻��� �ҷ� ������ ����
					switch (dummySet(a3)) {
					case ONE:	// 7 5 5 // b�� c�� ��� �ҷ� ����
						compareAllCase(ONE, 0);
						allBadCoin(b3);
						allBadCoin(c3);
						break;
					case TWO:	// b�� c�� ��� �ҷ� ����
						compareAllCase(TWO, 0);
						allBadCoin(b3);
						allBadCoin(c3);
						break;
					case THREE:	// b�� c�� ��� �ҷ� ����
						compareAllCase(THREE, 0);
						allBadCoin(b3);
						allBadCoin(c3);
						break;
					case EQUAL_ONETWO:
						compareAllCase(EQUAL_ONETWO, 0);
						compareAllCase(dummySet(b3), 1);
						compareAllCase(dummySet(c3), 1);
						break;
					case EQUAL_ONETHREE:
						compareAllCase(EQUAL_ONETHREE, 0);
						compareAllCase(dummySet(b3), 1);
						compareAllCase(dummySet(c3), 1);
						break;
					case EQUAL_TWOTHREE:
						compareAllCase(EQUAL_TWOTHREE, 0);
						compareAllCase(dummySet(b3), 1);
						compareAllCase(dummySet(c3), 1);
						break;
					case EQUAL_ALL:
						allNormalCoin(a3);
						compareAllCase(dummySet(b3), 1);
						compareAllCase(dummySet(c3), 1);
						break;
					default:
						printf("���ǵ��� ���� ���");
						break;
					}
					break;
				case TWO:
					switch (dummySet(b3)) {
					case ONE:	// a�� c�� ��� �ҷ� ����
						compareAllCase(ONE, 0);
						allBadCoin(a3);
						allBadCoin(c3);
						break;
					case TWO:	// a�� c�� ��� �ҷ� ����
						compareAllCase(TWO, 0);
						allBadCoin(a3);
						allBadCoin(c3);
						break;
					case THREE:	// a�� c�� ��� �ҷ� ����
						compareAllCase(THREE, 0);
						allBadCoin(a3);
						allBadCoin(c3);
						break;
					case EQUAL_ONETWO:
						compareAllCase(EQUAL_ONETWO, 0);
						compareAllCase(dummySet(a3), 1);
						compareAllCase(dummySet(c3), 1);
						break;
					case EQUAL_ONETHREE:
						compareAllCase(EQUAL_ONETHREE, 0);
						compareAllCase(dummySet(a3), 1);
						compareAllCase(dummySet(c3), 1);
						break;
					case EQUAL_TWOTHREE:
						compareAllCase(EQUAL_TWOTHREE, 0);
						compareAllCase(dummySet(a3), 1);
						compareAllCase(dummySet(c3), 1);
						break;
					case EQUAL_ALL:
						allNormalCoin(b3);
						compareAllCase(dummySet(a3), 1);
						compareAllCase(dummySet(c3), 1);
						break;
					default:
						printf("���ǵ��� ���� ���");
						break;
					}
					break;
				case THREE:
					switch (dummySet(c3)) {
					case ONE:	// a�� b�� ��� �ҷ� ����
						compareAllCase(ONE, 0);
						allBadCoin(a3);
						allBadCoin(b3);
						break;
					case TWO:	// a�� b�� ��� �ҷ� ����
						compareAllCase(TWO, 0);
						allBadCoin(a3);
						allBadCoin(b3);
						break;
					case THREE:	// a�� b�� ��� �ҷ� ����
						compareAllCase(THREE, 0);
						allBadCoin(a3);
						allBadCoin(b3);
						break;
					case EQUAL_ONETWO:
						compareAllCase(EQUAL_ONETWO, 0);
						compareAllCase(dummySet(a3), 1);
						compareAllCase(dummySet(b3), 1);
						break;
					case EQUAL_ONETHREE:
						compareAllCase(EQUAL_ONETHREE, 0);
						compareAllCase(dummySet(a3), 1);
						compareAllCase(dummySet(b3), 1);
						break;
					case EQUAL_TWOTHREE:
						compareAllCase(EQUAL_TWOTHREE, 0);
						compareAllCase(dummySet(a3), 1);
						compareAllCase(dummySet(b3), 1);
						break;
					case EQUAL_ALL:
						allNormalCoin(c3);
						compareAllCase(dummySet(a3), 1);
						compareAllCase(dummySet(b3), 1);
						break;
					default:
						printf("���ǵ��� ���� ���");
						break;
					}
					break;
				case EQUAL_ONETWO:	 // c���� 1�� �̻��� �ҷ� ������ ����
					switch (dummySet(a3)) {
					case ONE:	// 755 // c�� ��� �ҷ�
						compareAllCase(ONE, 0);
						compareAllCase(dummySet(b3), 0);
						allBadCoin(c3);
						break;
					case TWO:	// c�� ��� �ҷ�
						compareAllCase(TWO, 0);
						compareAllCase(dummySet(b3), 0);
						allBadCoin(c3);
						break;
					case THREE:	// c�� ��� �ҷ�
						compareAllCase(THREE, 0);
						compareAllCase(dummySet(b3), 0);
						allBadCoin(c3);
						break;
					case EQUAL_ONETWO:	// 7 7 5
						compareAllCase(EQUAL_ONETWO, 0);
						compareAllCase(dummySet(b3), 0);
						compareAllCase(dummySet(c3), 1);
						break;
					case EQUAL_ONETHREE:
						compareAllCase(EQUAL_ONETHREE, 0);
						compareAllCase(dummySet(b3), 0);
						compareAllCase(dummySet(c3), 1);
						break;
					case EQUAL_TWOTHREE:
						compareAllCase(EQUAL_TWOTHREE, 0);
						compareAllCase(dummySet(b3), 0);
						compareAllCase(dummySet(c3), 1);
						break;
					case EQUAL_ALL:	// 7 7 7
						allNormalCoin(a3);
						allNormalCoin(b3);
						compareAllCase(dummySet(c3), 1);
						break;
					default:
						printf("���ǵ��� ���� ���");
						break;
					}
					break;
				case EQUAL_ONETHREE:	// b���� 1�� �̻��� �ҷ� ������ ����
					switch (dummySet(a3)) {
					case ONE:	// b�� ��� �ҷ�
						compareAllCase(ONE, 0);
						compareAllCase(dummySet(c3), 0);
						allBadCoin(b3);
						break;
					case TWO:	// b�� ��� �ҷ�
						compareAllCase(TWO, 0);
						compareAllCase(dummySet(c3), 0);
						allBadCoin(b3);
						break;
					case THREE:	// b�� ��� �ҷ�
						compareAllCase(THREE, 0);
						compareAllCase(dummySet(c3), 0);
						allBadCoin(b3);
						break;
					case EQUAL_ONETWO:	// 7 7 5
						compareAllCase(EQUAL_ONETWO, 0);
						compareAllCase(dummySet(c3), 0);
						compareAllCase(dummySet(b3), 1);
						break;
					case EQUAL_ONETHREE:
						compareAllCase(EQUAL_ONETHREE, 0);
						compareAllCase(dummySet(c3), 0);
						compareAllCase(dummySet(b3), 1);
						break;
					case EQUAL_TWOTHREE:
						compareAllCase(EQUAL_TWOTHREE, 0);
						compareAllCase(dummySet(c3), 0);
						compareAllCase(dummySet(b3), 1);
						break;
					case EQUAL_ALL:	// 7 7 7
						allNormalCoin(a3);
						allNormalCoin(c3);
						compareAllCase(dummySet(b3), 1);
						break;
					default:
						printf("���ǵ��� ���� ���");
						break;
					}
					break;
				case EQUAL_TWOTHREE:	// a���� 1�� �̻��� �ҷ� ������ ����
					switch (dummySet(b3)) {
					case ONE:	// a�� ��� �ҷ�
						compareAllCase(ONE, 0);
						compareAllCase(dummySet(c3), 0);
						allBadCoin(a3);
						break;
					case TWO:	// a�� ��� �ҷ�
						compareAllCase(TWO, 0);
						compareAllCase(dummySet(c3), 0);
						allBadCoin(a3);
						break;
					case THREE:	// a�� ��� �ҷ�
						compareAllCase(THREE, 0);
						compareAllCase(dummySet(c3), 0);
						allBadCoin(a3);
						break;
					case EQUAL_ONETWO: // 7 7 5
						compareAllCase(EQUAL_ONETWO, 0);
						compareAllCase(dummySet(c3), 0);
						compareAllCase(dummySet(a3), 1);
						break;
					case EQUAL_ONETHREE:
						compareAllCase(EQUAL_ONETHREE, 0);
						compareAllCase(dummySet(c3), 0);
						compareAllCase(dummySet(a3), 1);
						break;
					case EQUAL_TWOTHREE:
						compareAllCase(EQUAL_TWOTHREE, 0);
						compareAllCase(dummySet(c3), 0);
						compareAllCase(dummySet(a3), 1);
						break;
					case EQUAL_ALL:	// 7 7 7
						allNormalCoin(b3);
						allNormalCoin(c3);
						compareAllCase(dummySet(a3), 1);
						break;
					default:
						printf("���ǵ��� ���� ���");
						break;
					}
					break;
				case EQUAL_ALL:
					switch (dummySet(a3)) {
					case ONE:
						compareAllCase(ONE, 0);
						compareAllCase(dummySet(b3), 0);
						compareAllCase(dummySet(c3), 0);
						break;
					case TWO:
						compareAllCase(TWO, 0);
						compareAllCase(dummySet(b3), 0);
						compareAllCase(dummySet(c3), 0);
						break;
					case THREE:
						compareAllCase(THREE, 0);
						compareAllCase(dummySet(b3), 0);
						compareAllCase(dummySet(c3), 0);
						break;
					case EQUAL_ONETWO:
						compareAllCase(EQUAL_ONETWO, 0);
						compareAllCase(dummySet(b3), 0);
						compareAllCase(dummySet(c3), 0);
						break;
					case EQUAL_ONETHREE:
						compareAllCase(EQUAL_ONETHREE, 0);
						compareAllCase(dummySet(b3), 0);
						compareAllCase(dummySet(c3), 0);
						break;
					case EQUAL_TWOTHREE:
						compareAllCase(EQUAL_TWOTHREE, 0);
						compareAllCase(dummySet(b3), 0);
						compareAllCase(dummySet(c3), 0);
						break;
					case EQUAL_ALL:
						unsure_coin_3compare[unsure_count_3compare] = a3[0];
						unsure_count_3compare = unsure_count_3compare + 1;
						break;
					default:
						printf("���ǵ��� ���� ���");
						break;
					}
					break;
				default:
					printf("���ǵ��� ���� ���");
					break;
				}
				i = i + 9;
				three_count++;
		}

	}

	printf("%d %d \n", one_count, three_count);
	percentage = ((float)bad_count / ((float)bad_count + (float)normal_count)) * 100;
	printf("%f\n", percentage);

	if (percentage <= 25 && bool_test == TRUE) {
		for (i = 0; i < unsure_count; i++) {
			for (j = 0; j < 3; j++) {
				normal_coin[normal_count] = unsure[i] + j;
				normal_count++;
			}
		}
	}

	else if (percentage >= 75 && bool_test == TRUE) {
		for (i = 0; i < unsure_count; i++) {
			for (j = 0; j < 3; j++) {
				bad_coin[bad_count] = unsure[i] + j;
				bad_count++;
			}
		}
	}

	else {	// �߰� Ȯ�� ���
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
			case EQUAL_ALL:	// �׻� 3�� ����� ����
				unsure_second[unsure_sec_count] = a[0];
				unsure_second[unsure_sec_count + 1] = b[0];
				unsure_second[unsure_sec_count + 2] = c[0];
				unsure_sec_count = unsure_sec_count + 3;
				break;
			default:
				printf("���ǵ��� ���� ���");
				break;
			}
		}
		// 3���� ���� �������� ���� ��
		if ((unsure_count % 3) == 1) {	// 1�� ����  99��° �ε�����?
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
				printf("���ǵ��� ���� ���");
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

					normal_count = normal_count + 2;
				}
				break;
			default:
				printf("���ǵ��� ���� ���");
				break;
			}
		}

		if (unsure_sec_count != 0) {
			if (percentage >= 60) {
				e[0] = bad_coin[0];
				e[1] = bad_coin[1];\


				e[2] = bad_coin[2];
				f[0] = bad_coin[3];
				f[1] = bad_coin[4];
				f[2] = bad_coin[5];

				for (k = 0; k < unsure_sec_count; k = k + 3) {
					d[0] = unsure_second[k];
					d[1] = unsure_second[k + 1];
					d[2] = unsure_second[k + 2];

					switch (balance(e, f, d)) {
					case THREE:
						for (j = 0; j < 3; j++) {
							normal_coin[normal_count] = d[0] + j;
							normal_coin[normal_count + 1] = d[1] + j;
							normal_coin[normal_count + 2] = d[2] + j;
							normal_count = normal_count + 3;
						}
						break;
					case EQUAL_ALL:
						for (j = 0; j < 3; j++) {
							bad_coin[bad_count] = d[0] + j;
							bad_coin[bad_count + 1] = d[1] + j;
							bad_coin[bad_count + 2] = d[2] + j;
							bad_count = bad_count + 3;
						}
						break;
					default:
						printf("���ǵ��� ���� ���");
						break;
					}
				}
			}
			else {
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
							bad_coin[bad_count + 1] = d[1] + j;
							bad_coin[bad_count + 2] = d[2] + j;
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
						printf("���ǵ��� ���� ���");
						break;
					}
				}
			}
		}
	}

	a3[0] = normal_coin[0];
	if (unsure_count_3compare != 0 && unsure_count_3compare % 2 == 0) {	// unsure_count_3compare�� ¦��
		for (i = 0; i < unsure_count_3compare; i = i + 2) {		// ����� �� : ONE, EQUAL_ONETWO, EQUAL_ONETHREE, EQUAL_ALL
			a3[1] = unsure_coin_3compare[i];
			a3[2] = unsure_coin_3compare[i + 1];

			switch (dummySet(a3)) {
			case ONE:
				for (j = 0; j < 9; j++) {
					bad_coin[bad_count] = unsure_coin_3compare[i] + j;
					bad_coin[bad_count + 1] = unsure_coin_3compare[i + 1] + j;
					bad_count = bad_count + 2;
				}
				break;
			case EQUAL_ONETWO:
				for (j = 0; j < 9; j++) {
					normal_coin[normal_count] = unsure_coin_3compare[i] + j;
					bad_coin[bad_count + 1] = unsure_coin_3compare[i + 1] + j;
					normal_count = normal_count + 1;
					bad_count = bad_count + 1;
				}
				break;
			case EQUAL_ONETHREE:
				for (j = 0; j < 9; j++) {
					normal_coin[normal_count] = unsure_coin_3compare[i + 1] + j;
					bad_coin[bad_count + 1] = unsure_coin_3compare[i] + j;
					normal_count = normal_count + 1;
					bad_count = bad_count + 1;
				}
				break;
			case EQUAL_ALL:
				for (j = 0; j < 9; j++) {
					normal_coin[normal_count] = unsure_coin_3compare[i] + j;
					normal_coin[normal_count + 1] = unsure_coin_3compare[i + 1] + j;
					normal_count = normal_count + 2;
				}
				break;
			default:
				printf("���ǵ��� ���� ���");
				break;
			}
		}
		a3[1] = normal_coin[1];
		a3[2] = 99;

		switch (dummySet(a3)) {	// ����� �� : EQUAL_ONETWO, EQUAL_ALL
		case EQUAL_ONETWO:
			bad_coin[bad_count] = 99;
			bad_count = bad_count + 1;
			break;
		case EQUAL_ALL:
			normal_coin[normal_count] = 99;
			normal_count = normal_count + 1;
			break;
		default:
			printf("���ǵ��� ���� ���\n");
			break;
		}
	}
	else if (unsure_count_3compare != 0 && unsure_count_3compare % 2 == 1) {
		unsure_coin_3compare[unsure_count_3compare] = 99;
		unsure_count_3compare = unsure_count_3compare + 1;

		for (i = 0; i < unsure_count_3compare; i = i + 2) {/***************************************************/
			a3[1] = unsure_coin_3compare[i];
			a3[2] = unsure_coin_3compare[i + 1];

			if ((i + 2) >= unsure_count_3compare) {		// ����� �� ONE, EQUAL_ONETWO, EQUAL_ONETHREE EQUALL_ALL
				a3[2] = 99;

				switch (dummySet(a3)) {
				case ONE:
					for (j = 0; j < 9; j++) {
						bad_coin[bad_count] = unsure_coin_3compare[i] + j;
						bad_count = bad_count + 1;
					}
					bad_coin[bad_count] = 99;
					bad_count = bad_count + 1;
					break;
				case EQUAL_ONETWO:
					for (j = 0; j < 9; j++) {
						normal_coin[normal_count] = unsure_coin_3compare[i] + j;
						normal_count = normal_count + 1;
					}
					bad_coin[bad_count] = 99;
					bad_count = bad_count + 1;
					break;
				case EQUAL_ONETHREE:
					for (j = 0; j < 9; j++) {
						bad_coin[bad_count] = unsure_coin_3compare[i] + j;
						bad_count = bad_count + 1;
					}
					normal_coin[normal_count] = 99;
					normal_count = normal_count + 1;
					break;
				case EQUAL_ALL:
					for (j = 0; j < 9; j++) {
						normal_coin[normal_count] = unsure_coin_3compare[i] + j;
						normal_count = normal_count + 1;
					}
					normal_coin[normal_count] = 99;
					normal_count = normal_count + 1;
					break;
				default:
					printf("���ǵ��� ���� ���");
					break;
				}
			}
			else {
				switch (dummySet(a3)) {
				case ONE:
					for (j = 0; j < 9; j++) {
						bad_coin[bad_count] = unsure_coin_3compare[i] + j;
						bad_coin[bad_count + 1] = unsure_coin_3compare[i + 1] + j;
						bad_count = bad_count + 2;
					}
					break;
				case EQUAL_ONETWO:
					for (j = 0; j < 9; j++) {
						normal_coin[normal_count] = unsure_coin_3compare[i] + j;
						bad_coin[bad_count + 1] = unsure_coin_3compare[i + 1] + j;
						normal_count = normal_count + 1;
						bad_count = bad_count + 1;
					}
					break;
				case EQUAL_ONETHREE:
					for (j = 0; j < 9; j++) {
						normal_coin[normal_count] = unsure_coin_3compare[i + 1] + j;
						bad_coin[bad_count + 1] = unsure_coin_3compare[i] + j;
						normal_count = normal_count + 1;
						bad_count = bad_count + 1;
					}
					break;
				case EQUAL_ALL:
					for (j = 0; j < 9; j++) {
						normal_coin[normal_count] = unsure_coin_3compare[i] + j;
						normal_coin[normal_count + 1] = unsure_coin_3compare[i + 1] + j;
						normal_count = normal_count + 2;
					}
					break;
				default:
					printf("���ǵ��� ���� ���");
					break;
				}
			}
		}
	}
	else {	// unsure_count_3compare�� 0�� �� 99��° �ε����� Ž��
		a3[0] = normal_coin[0];
		a3[1] = normal_coin[1];
		a3[2] = 99;

		switch (dummySet(a3)) {	// ����� �� : EQUAL_ONETWO, EQUAL_ALL	
		case EQUAL_ONETWO:
			bad_coin[bad_count] = 99;
			bad_count = bad_count + 1;
			break;
		case EQUAL_ALL:
			normal_coin[normal_count] = 99;
			normal_count = normal_count + 1;
			break;
		default:
			printf("���ǵ��� ���� ���");
			break;
		}
	}

	qsort(bad_coin, bad_count, sizeof(int), compare);
	qsort(normal_coin, normal_count, sizeof(int), compare);

	bad_coin[bad_count] = -1;
	b[0] = -1;
	c[0] = -1;

	balance(bad_coin, b, c);

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

int dummySet(int set[]) {
	dum1[0] = set[0];
	dum2[0] = set[1];
	dum3[0] = set[2];

	return balance(dum1, dum2, dum3);
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
		normal_coin[normal_count] = dum1[0];
		bad_coin[bad_count] = dum2[0];
		bad_coin[bad_count + 1] = dum3[0];

		normal_count = normal_count + 1;
		bad_count = bad_count + 2;
		break;
	case TWO:
		normal_coin[normal_count] = dum2[0];
		bad_coin[bad_count] = dum1[0];
		bad_coin[bad_count + 1] = dum3[0];

		normal_count = normal_count + 1;
		bad_count = bad_count + 2;
		break;
	case THREE:
		normal_coin[normal_count] = dum3[0];
		bad_coin[bad_count] = dum1[0];
		bad_coin[bad_count + 1] = dum2[0];

		normal_count = normal_count + 1;
		bad_count = bad_count + 2;
		break;
	case EQUAL_ONETWO:
		normal_coin[normal_count] = dum1[0];
		normal_coin[normal_count + 1] = dum2[0];
		bad_coin[bad_count] = dum3[0];

		normal_count = normal_count + 2;
		bad_count = bad_count + 1;
		break;
	case EQUAL_ONETHREE:
		normal_coin[normal_count] = dum1[0];
		normal_coin[normal_count + 1] = dum3[0];
		bad_coin[bad_count] = dum2[0];

		normal_count = normal_count + 2;
		bad_count = bad_count + 1;
		break;
	case EQUAL_TWOTHREE:
		normal_coin[normal_count] = dum2[0];
		normal_coin[normal_count + 1] = dum3[0];
		bad_coin[bad_count] = dum1[0];

		normal_count = normal_count + 2;
		bad_count = bad_count + 1;
		break;
	case EQUAL_ALL:
		if (check == 0) {
			normal_coin[normal_count] = dum1[0];
			normal_coin[normal_count + 1] = dum2[0];
			normal_coin[normal_count + 2] = dum3[0];

			normal_count = normal_count + 3;
		}
		else if (check == 1) {
			bad_coin[bad_count] = dum1[0];
			bad_coin[bad_count + 1] = dum2[0];
			bad_coin[bad_count + 2] = dum3[0];

			bad_count = bad_count + 3;
		}
		else
			printf("���ǵ��� ���� ���");
		break;
	default:
		printf("���ǵ��� ���� ���");
		break;
	}
}