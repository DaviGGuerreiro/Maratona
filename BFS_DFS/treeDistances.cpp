#include <bits/stdc++.h>
using namespace std;
int n;

vector<int> bfs(int z,vector<vector<int>>& vec){
    queue<int> fila;
    fila.push(z);
    vector<int> distancia (n+1, -1);
    distancia[z] = 0;
    while(!fila.empty()){
        int aux = fila.front();
        fila.pop();
        for(auto x : vec[aux]){
            if(distancia[x] == -1){
                fila.push(x);
                distancia[x] = distancia[aux] + 1;
            }
        }
    }
    return distancia;
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    cin>>n;
    int a, b;
    vector<vector<int>> vec (n+1);
    for(int i=1;i<n;i++){
        cin>>a>>b;
        if(a != b){
            vec[a].push_back(b);
            vec[b].push_back(a);
        }
    }
    vector<int> b1 = bfs(1, vec);
    int m1 = max_element(b1.begin(), b1.end())-b1.begin();
    vector<int> A = bfs(m1, vec);
    int m2 = max_element(A.begin(), A.end())-A.begin();
    vector<int> B = bfs(m2, vec);
    for(int i=1;i<=n;i++){
        if(A[i]>B[i]){
            cout<<A[i]<<" ";
        }
        else{
            cout<<B[i]<<" ";
        }
    }

    return 0;
}