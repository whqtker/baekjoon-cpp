#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

char arr[10][10];
int visited[10][10][10][10];
int n, m, tx, ty;
bool swapped, first_moved, second_moved, first_goal, second_goal;
int A, B, C, D;

void init() {
	swapped = false;
	first_moved = false;
	second_moved = false;
	first_goal = false;
	second_goal = false;
}

void swap(int* x, int* y) {
	int tmp = *y;
	*y = *x;
	*x = tmp;
}

bool kiss(int a, int b, int c, int d) {
	return a == c && b == d;
}

tuple<int, int, int, int> ret(int a, int b, int c, int d) {
	// ���� ������ �� ���� ���
	if (!first_moved && !second_moved)
		return { A,B,C,D };
	// R, B ��� ���ۿ� ���� ���
	else if (first_goal && second_goal)
		return { A,B,C,D };
	// R -> B, B ����
	else if (!swapped && second_goal)
		return { A,B,C,D };
	// B -> R, B ����
	else if (swapped && first_goal)
		return { A,B,C,D };

	// R -> B, R ����
	else if (!swapped && first_goal)
		return{ tx,ty,c,d };
	// B -> R, R ����
	else if (swapped && second_goal)
		return { tx, ty, a, b };

	// R -> B �̵�
	else if (!swapped)
		return { a,b,c,d };
	// B -> R �̵�
	else
		return { c,d,a,b };
}

tuple<int, int, int, int> left(int a, int b, int c, int d) {
	A = a, B = b, C = c, D = d; // �ʱ� ��ǥ
	init();

	// ���� �������� �������� ��.
	if (b > d) {
		swap(d, b);
		swap(a, c);
		swapped = true;
	}

	// ����, �� üũ
	while (b - 1 >= 0 && arr[a][b - 1] != '#') {
		b--;
		first_moved = true;
		// ���ۿ� ����, �ڿ� ���� ���� �� ���� ���� ����
		if (a == tx && b == ty) {
			a = -1;
			b = -1;
			first_goal = true;
		}
		// ������ ����, �ǵ��ư���
		if (kiss(a, b, c, d)) {
			b++;
			break;
		}
	}

	// ����, �� üũ
	while (d - 1 >= 0 && arr[c][d - 1] != '#') {
		d--;
		second_moved = true;
		// ���ۿ� ����, �ڿ� ���� ���� �� ���� ���� ����
		if (c == tx && d == ty) {
			c = -1;
			d = -1;
			second_goal = true;
		}
		// ������ ����, �ǵ��ư���
		if (kiss(a, b, c, d)) {
			d++;
			break;
		}
	}

	return ret(a, b, c, d);
}

tuple<int, int, int, int> right(int a, int b, int c, int d) {
	A = a, B = b, C = c, D = d; // �ʱ� ��ǥ
	init();

	// ���� �������� �������� ��.
	if (b < d) {
		swap(d, b);
		swap(a, c);
		swapped = true;
	}

	// ����, �� üũ
	while (b + 1 < m && arr[a][b + 1] != '#') {
		b++;
		first_moved = true;
		// ���ۿ� ����, �ڿ� ���� ���� �� ���� ���� ����
		if (a == tx && b == ty) {
			a = -1;
			b = -1;
			first_goal = true;
		}
		// ������ ����, �ǵ��ư���
		if (kiss(a, b, c, d)) {
			b--;
			break;
		}
	}

	// ����, �� üũ
	while (d + 1 < m && arr[c][d + 1] != '#') {
		d++;
		second_moved = true;
		// ���ۿ� ����, �ڿ� ���� ���� �� ���� ���� ����
		if (c == tx && d == ty) {
			c = -1;
			d = -1;
			second_goal = true;
		}
		// ������ ����, �ǵ��ư���
		if (kiss(a, b, c, d)) {
			d--;
			break;
		}
	}

	return ret(a, b, c, d);
}

tuple<int, int, int, int> up(int a, int b, int c, int d) {
	A = a, B = b, C = c, D = d; // �ʱ� ��ǥ
	init();

	// ���� �������� �������� ��.
	if (a > c) {
		swap(d, b);
		swap(a, c);
		swapped = true;
	}

	// ����, �� üũ
	while (a - 1 >= 0 && arr[a - 1][b] != '#') {
		a--;
		first_moved = true;
		// ���ۿ� ����, �ڿ� ���� ���� �� ���� ���� ����
		if (a == tx && b == ty) {
			a = -1;
			b = -1;
			first_goal = true;
		}
		// ������ ����, �ǵ��ư���
		if (kiss(a, b, c, d)) {
			a++;
			break;
		}
	}

	// ����, �� üũ
	while (c - 1 >= 0 && arr[c - 1][d] != '#') {
		c--;
		second_moved = true;
		// ���ۿ� ����, �ڿ� ���� ���� �� ���� ���� ����
		if (c == tx && d == ty) {
			c = -1;
			d = -1;
			second_goal = true;
		}
		// ������ ����, �ǵ��ư���
		if (kiss(a, b, c, d)) {
			c++;
			break;
		}
	}

	return ret(a, b, c, d);
}

tuple<int, int, int, int> down(int a, int b, int c, int d) {
	A = a, B = b, C = c, D = d; // �ʱ� ��ǥ
	init();

	// �Ʒ��� �������� �������� ��.
	if (a < c) {
		swap(d, b);
		swap(a, c);
		swapped = true;
	}

	// ����, �� üũ
	while (a + 1 < n && arr[a + 1][b] != '#') {
		a++;
		first_moved = true;
		// ���ۿ� ����, �ڿ� ���� ���� �� ���� ���� ����
		if (a == tx && b == ty) {
			a = -1;
			b = -1;
			first_goal = true;
		}
		// ������ ����, �ǵ��ư���
		if (kiss(a, b, c, d)) {
			a--;
			break;
		}
	}

	// ����, �� üũ
	while (c + 1 < n && arr[c + 1][d] != '#') {
		c++;
		second_moved = true;
		// ���ۿ� ����, �ڿ� ���� ���� �� ���� ���� ����
		if (c == tx && d == ty) {
			c = -1;
			d = -1;
			second_goal = true;
		}
		// ������ ����, �ǵ��ư���
		if (kiss(a, b, c, d)) {
			c--;
			break;
		}
	}

	return ret(a, b, c, d);
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	cin >> n >> m;

	queue<tuple<int, int, int, int>> q;
	int a, b, c, d;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 'R') {
				a = i;
				b = j;
			}
			else if (arr[i][j] == 'B') {
				c = i;
				d = j;
			}
			else if (arr[i][j] == 'O') {
				tx = i;
				ty = j;
			}
		}
	}

	q.push({ a,b,c,d });
	visited[a][b][c][d] = 1;
	while (!q.empty()) {
		int a = get<0>(q.front());
		int b = get<1>(q.front());
		int c = get<2>(q.front());
		int d = get<3>(q.front());
		int cnt = visited[a][b][c][d];
		q.pop();

		if (arr[a][b] == 'O') {
			if (cnt - 1 > 10)
				break;

			cout << cnt - 1;
			return 0;
		}

		tuple<int, int, int, int> L = left(a, b, c, d);
		tuple<int, int, int, int> R = right(a, b, c, d);
		tuple<int, int, int, int> U = up(a, b, c, d);
		tuple<int, int, int, int> D = down(a, b, c, d);

		if (!visited[get<0>(L)][get<1>(L)][get<2>(L)][get<3>(L)]) {
			visited[get<0>(L)][get<1>(L)][get<2>(L)][get<3>(L)] = cnt + 1;
			q.push({ get<0>(L) ,get<1>(L) ,get<2>(L) ,get<3>(L) });
		}
		if (!visited[get<0>(R)][get<1>(R)][get<2>(R)][get<3>(R)]) {
			visited[get<0>(R)][get<1>(R)][get<2>(R)][get<3>(R)] = cnt + 1;
			q.push({ get<0>(R) ,get<1>(R) ,get<2>(R) ,get<3>(R) });
		}
		if (!visited[get<0>(U)][get<1>(U)][get<2>(U)][get<3>(U)]) {
			visited[get<0>(U)][get<1>(U)][get<2>(U)][get<3>(U)] = cnt + 1;
			q.push({ get<0>(U) ,get<1>(U) ,get<2>(U) ,get<3>(U) });
		}
		if (!visited[get<0>(D)][get<1>(D)][get<2>(D)][get<3>(D)]) {
			visited[get<0>(D)][get<1>(D)][get<2>(D)][get<3>(D)] = cnt + 1;
			q.push({ get<0>(D) ,get<1>(D) ,get<2>(D) ,get<3>(D) });
		}
	}

	cout << -1;
}