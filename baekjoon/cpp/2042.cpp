#include <iostream>

using namespace std;
typedef long long ll;

ll arr[1000000];
ll tree[4000001];

ll init(int node,int left,int right) {
    if (left==right) {
        return tree[node]=arr[left];
    }

    int mid=(left+right)>>1;

    return tree[node]=init(node*2,left,mid)+init(node*2+1,mid+1,right);
}

ll sum(int node,int left,int right,int queryLeft,int queryRight) {
    if (right<queryLeft||queryRight<left) return 0;

    if (queryLeft<=left&&right<=queryRight) return tree[node];

    int mid=(left+right)>>1;

    return sum(node*2,left,mid,queryLeft,queryRight)+sum(node*2+1,mid+1,right,queryLeft,queryRight);
}

void update(int node,int left,int right,int idx,ll val) {
    if (idx<left||right<idx) return;

    if (left==right) {
        arr[idx]=val;
        tree[node]=val;
        return;
    }

    int mid=(left+right)>>1;

    if (left<=idx&&idx<=mid) {
        update(node*2,left,mid,idx,val);
    }
    else {
        update(node*2+1,mid+1,right,idx,val);
    }

    tree[node]=tree[node*2]+tree[node*2+1];
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n,m,k;
    cin>>n>>m>>k;

    for (int i=0;i<n;i++) cin>>arr[i];

    init(1,0,n-1);

    for (int i=0;i<m+k;i++) {
        ll x,a,b;
        cin>>x>>a>>b;
        if (x==1) {
            update(1,0,n-1,a-1,b);
        }
        else {
            cout<<sum(1,0,n-1,a-1,b-1)<<"\n";
        }
    }
}