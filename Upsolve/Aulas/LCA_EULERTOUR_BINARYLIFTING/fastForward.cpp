#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int n, c;

void solve(){
    cin>>n>>c;
    vector<ll> vec (n);
    vector<ll> up (n);
    for(int i = 0; i<n; i++){
        cin>>vec[i];
    }
    vector<ll> psum (n,0); psum[0] = vec[0];
    for(int i = 1; i<n; i++){
        psum[i] = psum[i-1] + vec[i];
    }
    ll sub = 0;
    vector<ll> resposta (n, 0);
    vector<vector<ll>> soma (n, vector<ll> (21,0));
    for(int i = 0; i<n; i++){
        int x = lower_bound(psum.begin() + i, psum.end(), c + sub) - psum.begin();
        if(x == (int)psum.size()){
            soma[i][0] = n;
        }
        x++; x = x % n;
        sub += vec[i];
        psum.push_back(vec[i] + psum.back());
        if(soma[i][0] == 0){
            if(x > i) soma[i][0] = x - i;
            else soma[i][0] = n + x - i;
        }
        up[i] = x;
    }
    vector<vector<ll>> quantidade (n, vector<ll> (21));
    for(int i = 0; i<n; i++){
        quantidade[i][0] = up[i];
    }
    for(int j = 1; j <=20; j++){
        for(int i = 0; i<n; i++){
            quantidade[i][j] = quantidade[quantidade[i][j-1]][j-1];
            soma[i][j] = soma[i][j-1] + soma[quantidade[i][j-1]][j-1];
        }
    }
    ll local; int y; int ind;
    for(int i = 0; i<n; i++){
        local = 0; y = n; ind = i;
        for(int j = 20; j>=0; j--){
            if(soma[ind][j] >= y) continue;
            local += (1<<j);
            y -= soma[ind][j];
            ind = quantidade[ind][j];
        }
        resposta[i] = local;
    }
    for(int i = 0; i<n; i++){
        cout<<resposta[i]<<' ';
    }
    return;
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    solve();
    return 0;
}