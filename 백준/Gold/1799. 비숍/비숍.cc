#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<math.h>
#define MAX(a,b)a>b?a:b
int map[11][11];
int setting[51][2];//y,x
char mode;
int n;

bool is_set(int depth,int y, int x) {
	/*비숍을 놓을 수 있는지 판별하는 함수*/

	for (int i = 0;i < depth;i++) {
		if (abs(setting[i][0] - y) == abs(setting[i][1] - x)) {
			return false;
		}
	}

	return true;
}
int back(int depth,int y) {
	int idx;
	int res = depth;

	for (int i = y;i < n;i++) {
		if (mode == 'W') {
			/*보드판 흰색만 할 때*/
			idx = (i % 2 == 0) ? 0 : 1;
		}
		else if (mode == 'B') {
			/*보드판 검은색만 할 때*/
			idx = (i % 2 == 0) ? 1 : 0;
		}

		for (;idx < n;idx += 2) {
			if (is_set(depth,i, idx) && (map[i][idx] == 1)) {
				setting[depth][0] = i;
				setting[depth][1] = idx;
				res = MAX(res, back(depth + 1,i));
			}
		}
	}

	return res;
}
void inputMap() {
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < n;j++) {
			scanf("%d", &map[i][j]);
		}
	}
}
int main() {
	int sum=0;
	scanf("%d", &n);

	inputMap();

	mode = 'W';
	sum += back(0,0);
	mode = 'B';
	sum += back(0,0);

	printf("%d", sum);
}