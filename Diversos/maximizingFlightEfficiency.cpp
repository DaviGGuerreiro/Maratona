#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int n;
vector<vector<int>> vec;
vector<vector<bool>> cor;
int resposta = 0;
bool verificar(){
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            for(int k = j+1; k<n; k++){
                if(i == k || i == j || j == k) continue;
                if(vec[j][k] > vec[j][i] + vec[i][k]){
                    return false;
                }
                else if (vec[j][k] == vec[j][i] + vec[i][k]){
                    if(!cor[j][k]) resposta++;
                    cor[j][k] = true;
                }
            }
        }
    }
    return true;
}

void solve(){
    cin>>n;
    vec = vector<vector<int>> (n, vector<int> (n));
    cor = vector<vector<bool>> (n,vector<bool> (n,false));
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            cin>>vec[i][j];
        }
    }
    if(verificar()){
        cout<<resposta<<'\n';
    }
    else{
        cout<<-1<<'\n';
    }
    return;
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    solve(); 
    return 0;
}