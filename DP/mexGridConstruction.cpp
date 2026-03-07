#include<bits/stdc++.h>
using namespace std;

int n;

void solve(vector<vector<int>>& grid, int i, int j){
    map<int,int> mapa;
    for(int linha = 0; linha < i; linha++){
        mapa[grid[linha][j]] = 1;
    }
    for(int coluna = 0; coluna < j; coluna++){
        mapa[grid[i][coluna]] = 1;
    }
    int aux = 0;
    while(true){
        if(mapa[aux] == 0){
            grid[i][j] = aux;
            if(j == n-1){
                if(i == n-1){
                    return;
                }
                else{
                    solve(grid, i+1, 0);
                }
            }
            else{
                solve(grid, i, j+1);
            }
        }
        else{
            aux++;
        }
    }
    return;
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    cin>>n;
    vector<vector<int>> grid (n,vector<int> (n,0));
    solve(grid, 0, 0);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<grid[i][j]<<" ";
        }
        cout<<'\n';
    }
    return 0;
}