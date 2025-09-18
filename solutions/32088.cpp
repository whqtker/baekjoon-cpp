#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
long long arr[200000];

// k���� �ﰢ���� ���� �� �ִ���
// �� ������ min(arr[i], k)���� ������ ���Ѵ�.
bool check(long long k) {
    long long sum = 0;
    for (int i = 0; i < n; i++) {
        sum += min(arr[i], 2 * k);
    }
    return sum >= 3 * k; // �ﰢ�� k���� ����� �� �ʿ��� ���� ���� �ּ� 3k��
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    long long total = 0; // �� ���� ��

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        total += arr[i];
    }

    long long low = 0, high = total / 3, answer = 0;
    while (low <= high) {
        long long mid = (low + high) / 2;
        if (check(mid)) {
            answer = mid;
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    cout << answer;
}
