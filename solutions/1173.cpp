#include <iostream>

using namespace std;

int main() {
	int N, m, M, T, R; // N: ��� �ؾ� �ϴ� �ð�, m: �ʱ�ƹ�/�ּҸƹ�, M: �ִ�ƹ�, T: ��� �ϰ� �߰��Ǵ� �ƹ�, R: �޽��� �ϰ� �پ��� �ƹ�
	cin >> N >> m >> M >> T >> R;

	int t = 0; // ��ü �ð�
	int e = 0; // ������ ��� �ð�
	int c = m; // ���� �ƹ�

	// 1. ��� �� �� ���� �� �ؾ� ��. c + T <= M �̶�� ��� �ؾ� ��.
	// 2. ��� �� �� ���ٸ� �޽��� �ؾ� ��. 
	// 3. c - R < m �̶�� c = m�̴�.
	// 4. ��� �� �� ���� ���� m + T > M �� �����.
	if (m + T > M)
		cout << -1;
	else {
		while (e != N) {
			if (c + T <= M) {
				c += T;
				t++;
				e++;
			}
			else {
				if (c - R < m) {
					c = m;
					t++;
				}
				else {
					c -= R;
					t++;
				}
			}
		}

		cout << t;
	}

}