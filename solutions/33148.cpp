#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> v(n * n);
	for (int i = 0;i < n * n;i++) {
		cin >> v[i];
	}

	// v에 등장한 원소가 A에 존재하지 않을 수 있다. 4=2*2
	// A={2,3,4}라면 M={4,6,8,6,9,12,8,12,16}
	// M의 가장 작거나 큰 원소의 제곱근은 A에 반드시 포함된다.
	// A={2,2,3}라면 M={4,4,6,4,4,6,6,6,9}
}