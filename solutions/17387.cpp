#include <iostream>
#include <algorithm>

using namespace std;

struct coor {
	long long x, y;

	bool operator<=(const coor& P)const {
		if (x != P.x)
			return x <= P.x;
		return y <= P.y;
	}
	bool operator>=(const coor& P)const {
		if (x != P.x)
			return x >= P.x;
		return y >= P.y;
	}
};

double ccw(coor A,coor B,coor C) {
	return (B.x - A.x) * (C.y - A.y) - (C.x - A.x) * (B.y - A.y);
}

int main() {
	coor A, B, C, D;
	cin >> A.x >> A.y >> B.x >> B.y >> C.x >> C.y >> D.x >> D.y;

	// ���� AB�� ���� CD���� A�� C�� ���� B�� D���� x �Ǵ� y ��ǥ�� �۵��� ����
	if (A >= B) {
		swap(A, B);
	}
	if (C >= D) {
		swap(C, D);
	}

	if (ccw(A, B, C) * ccw(A, B, D) <= 0 && ccw(C, D, A) * ccw(C, D, B) <= 0) {
		if (ccw(A, B, C) * ccw(A, B, D) == 0 && ccw(C, D, A) * ccw(C, D, B) == 0) {
			cout << (A <= D && C <= B);
		}
		else
			cout << 1;
	}
	else
		cout << 0;
}