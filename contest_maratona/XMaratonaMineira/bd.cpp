#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
    int n; cin>>n;
    vector<int> vec (n);
    vector<int> tipos (n + 1, 0);
    vector<vector<int>> pontos (n+1);
    bool cinco = false;
    for(int i = 0; i<n; i++){
        cin>>vec[i];
        pontos[vec[i]].push_back(i);
        tipos[vec[i]]++;
        if(tipos[vec[i]] == 5) cinco = true;
    }
    if(cinco){cout<<"N"<<'\n'; return;}
    int k = 0;
    int aux;
    int distancia;
    int q;
    vector<int> quantidade;
    for(int i = 1; i <= n; i++){
        if(tipos[i] == 0 || tipos[i] == 1) continue;
        for(int j = 0; j < (int)pontos[i].size(); j++){
            for(int w = j+1; w < (int)pontos[i].size(); w++){
                quantidade = vector<int> (n+1, 0);
                distancia = pontos[i][w] - pontos[i][j];
                if(distancia == 1 || distancia == n-1) continue;
                for(int z = 0; z < distancia; z++){
                    aux = (pontos[i][j] + z) % n;
                    quantidade[vec[aux]]++;
                }
                quantidade[pontos[i][j]]--;
                q = 0;
                for(int z = 1; z<=n; z++){
                    if(quantidade[z] != 0 && quantidade[z] < pontos[z].size()){
                        q++;
                    }
                }
                if(q > 1) k++;
                if(k > 1){
                    cout<<"N"<<"\n";
                    return;
                }
            }
        }
    }
    cout<<"S"<<'\n';
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    solve();
    return 0;
}