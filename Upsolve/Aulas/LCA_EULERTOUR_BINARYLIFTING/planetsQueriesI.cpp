#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int n, q;
vector<vector<int>> up;

int kth_anc(int node, int k){
    int cur = node;
    for(int i = 0; (1<<i)<=k; i++){
        if((1<<i) & k) cur = up[cur][i];
    }
    return cur;
}

void solve(){
    cin>>n>>q; int a, b;
    up = vector<vector<int>> (n+1, vector<int> (31));
    for(int i = 1; i<=n; i++){
        cin>>up[i][0];
    }
    for(int j = 1; j <= 30; j++){
        for(int i = 1; i<=n; i++){
            up[i][j] = up[up[i][j-1]][j-1];
        }
    }
    while(q--){
        cin>>a>>b;
        cout<<kth_anc(a,b)<<'\n';
    }
    return;
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    solve();
    return 0;
}