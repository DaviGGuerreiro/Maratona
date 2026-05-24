#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
    int n, m; cin>>n>>m;
    vector<vector<int>> vec (n, vector<int> (m));
    for(int i = 0 ; i<n; i++){
        for(int j = 0; j<m; j++){
            cin>>vec[i][j];
        }
    }
    int maior = 1;
    int local;
    int valor;
    for(int i = 0 ; i<n; i++){
        local = 1;
        valor = vec[i][0];
        for(int j = 1; j<m; j++){
            if(abs(valor - vec[i][j]) <= 1){
                local++;
                if(local > maior){
                    maior = local;
                }
            }
            else{
                local = 1;
            }
            valor = vec[i][j];
        }
    }
    for(int i = 0 ; i<m; i++){
        local = 1;
        valor = vec[0][i];
        for(int j = 1; j<n; j++){
            if(abs(valor - vec[j][i]) <= 1){
                local++;
                if(local > maior){
                    maior = local;
                }
            }
            else{
                local = 1;
            }
            valor = vec[j][i];
        }
    }
    cout<<maior<<'\n';
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    solve();
    return 0;
}