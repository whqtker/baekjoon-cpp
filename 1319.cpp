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

// 외적으로 점 위치 관계 판별
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

    // 한쪽에 모든 나무가 쏠리는 경우
    int min_value = tot;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {

            int leftValue = 0;
            vector<Tree> linear; // 직선 위의 나무들

            for (int k = 0; k < n; k++) {
                int cp = cross_product(trees[i], trees[j], trees[k]);
                if (cp > 0) {
                    leftValue += trees[k].value;
                }
                else if (cp == 0) {
                    linear.push_back(trees[k]);
                }
            }

            // 좌표 기준으로 정렬
            sort(linear.begin(), linear.end());

            // 직선 위의 점들에 대해 누적 합 계산
            vector<int> prefixSum(linear.size() + 1, 0);
            for (int i = 0; i < linear.size(); i++) {
                prefixSum[i + 1] = prefixSum[i] + linear[i].value;
            }

            // 직선 위의 점들을 나누는 모든 경우의 수 탐색
            for (int i = 0; i <= linear.size(); i++) {
                // A: 왼쪽 그룹 + 직선 위 나무의 일부
                int a_val = leftValue + prefixSum[i];

                // B: tot - a_val
                min_value = min(min_value, abs(2 * a_val - tot));
            }
        }
    }

    cout << min_value;
}
