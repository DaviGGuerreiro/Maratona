#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int t;
    int n, m;
    int aux;
    cin>>t;
    while(t--){
        cin>>n>>m;
        vector<vector<int>> vec (n);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>aux;
                vec[i].push_back(aux);
            }
        }
        map<int,int> diagonal_1;
        map<int,int> diagonal_2;
        aux = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                diagonal_1[i-j] = diagonal_1[i-j] + vec[i][j];
                diagonal_2[i+j] = diagonal_2[i+j] + vec[i][j];
            }
        }
        int maximo = -1;
        int valor;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                valor = diagonal_1[i-j]+diagonal_2[i+j]-vec[i][j];
                if(maximo < valor){
                    maximo = valor;
                }
            }
        }
        cout<<maximo<<'\n';
    }
    return 0;
}