#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

struct Tree {
    int x, y, value;

    bool operator<(const Tree& other) const {
        if (x != other.x) {
            return x < other.x;
        }
        return y < other.y;
    }
};

// �������� �� ��ġ ���� �Ǻ�
int cross_product(const Tree& a, const Tree& b, const Tree& c) {
    return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<Tree> trees(n);
    int tot = 0;
    for (int i = 0; i < n; i++) {
        cin >> trees[i].x >> trees[i].y >> trees[i].value;
        tot += trees[i].value;
    }

    // ���ʿ� ��� ������ �򸮴� ���
    int min_value = tot;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {

            int leftValue = 0;
            vector<Tree> linear; // ���� ���� ������

            for (int k = 0; k < n; k++) {
                int cp = cross_product(trees[i], trees[j], trees[k]);
                if (cp > 0) {
                    leftValue += trees[k].value;
                }
                else if (cp == 0) {
                    linear.push_back(trees[k]);
                }
            }

            // ��ǥ �������� ����
            sort(linear.begin(), linear.end());

            // ���� ���� ���鿡 ���� ���� �� ���
            vector<int> prefixSum(linear.size() + 1, 0);
            for (int i = 0; i < linear.size(); i++) {
                prefixSum[i + 1] = prefixSum[i] + linear[i].value;
            }

            // ���� ���� ������ ������ ��� ����� �� Ž��
            for (int i = 0; i <= linear.size(); i++) {
                // A: ���� �׷� + ���� �� ������ �Ϻ�
                int a_val = leftValue + prefixSum[i];

                // B: tot - a_val
                min_value = min(min_value, abs(2 * a_val - tot));
            }
        }
    }

    cout << min_value;
}
