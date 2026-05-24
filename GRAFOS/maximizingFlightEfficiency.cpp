#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
    int n; cin>>n;
    vector<vector<int>> vec (n+1, vector<int> (n+1));
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            cin>>vec[i][j];
        }
    }
    ll resposta = 0;
    map<pair<int,int>, bool> mapa;
    for(int k = 0; k <n; k++){
        for(int i = 0; i < n; i++){
            for(int j = 0; j<n; j++){
                if(i == j || i == k || k == j) continue;
                if(vec[i][k] + vec[k][j] < vec[i][j]){
                    cout<<"-1"<<'\n';
                    return;
                }
                else if(vec[i][k] + vec[k][j] == vec[i][j]){
                    if(mapa[{i,j}] == false){
                        resposta++;
                        mapa[{i,j}] = true;
                        mapa[{j,i}] = true;
                    }
                }
            }
        }
    }
    cout<<resposta<<'\n';
    return;
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    solve();
    return 0;
}