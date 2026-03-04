#include <iostream>
#include <algorithm>

#define SIZE 100000

using namespace std;

int arr[SIZE];
int tree[SIZE*4+1];

int init(int node,int left,int right) {
    if (left==right) return tree[node]=arr[left];

    int mid=(left+right)>>1;

    return tree[node]=min(init(node*2,left,mid),init(node*2+1,mid+1,right));
}

int query(int node,int left,int right,int queryLeft,int queryRight) {
    if (right<queryLeft||queryRight<left) return 2e9;

    if (queryLeft<=left&&right<=queryRight) return tree[node];

    int mid=(left+right)>>1;

    return min(query(node*2,left,mid,queryLeft,queryRight),query(node*2+1,mid+1,right,queryLeft,queryRight));
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n,m;
    cin>>n>>m;

    for (int i=0;i<n;i++) cin>>arr[i];

    init(1,0,SIZE-1);

    for (int i=0;i<m;i++) {
        int a,b;
        cin>>a>>b;
        cout<<query(1,0,SIZE-1,a-1,b-1)<<"\n";
    }
}