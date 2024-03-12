#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int ans[1000001];

int main() {
	int n;
	cin >> n;
	vector<int> v;

	stack<int> s;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		v.push_back(x);
	}

	ans[n - 1] = -1;
	for (int i = 0; i < n - 1; i++) {
		s.push(v[i]);

		if (v[i] < v[i + 1]) {
			ans[i] = v[i + 1];

			while (s.top() < v[i + 1]) {

			}
		}
	}
}