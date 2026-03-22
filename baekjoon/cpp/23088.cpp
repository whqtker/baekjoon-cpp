#include <iostream>
#include <tuple>
#include <queue>
#include <vector>

using namespace std;
typedef tuple<int,int,int> tii;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n;
    cin>>n;

    // 실행 순위: 우선순위 높음 > 실행 시간 짧음 > 먼저 등장
    vector<tii> v; // 실행 요청 시점, 초기 우선순위, 실행 시간
    for (int i=0;i<n;i++) {
        int a,b,c; // 실행 요청 시점, 초기 우선순위, 실행 시간
        cin>>a>>b>>c;
        v.push_back({a,b,c});
    }

    int curTime=0;
    int idx=0;
    priority_queue<tii> pq; // 보정된 우선순위, -실행시간, -등장 번호
    while (idx<n||!pq.empty()) {
        // 현재 시간까지 도착한 작업 pq에 삽입
        while (idx<n&&get<0>(v[idx])<=curTime) {
            pq.push({get<1>(v[idx])-get<0>(v[idx]),-get<2>(v[idx]),-(idx+1)});
            idx++;
        }

        // 처리할 작업 없는 경우
        if (pq.empty()) {
            curTime=get<0>(v[idx]);
        }
        else {
            int num=-get<2>(pq.top());
            cout<<num<<" ";
            curTime-=get<1>(pq.top());
            pq.pop();
        }
    }
}