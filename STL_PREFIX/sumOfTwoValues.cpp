#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int n, x;
    int r = 0;
    int aux;
    cin>>n>>x;
    map<int, int> mapa;
    for(int i=0;i<n;i++){
        cin>>aux;
        if(aux < x){
            if(mapa[x-aux] == 0){
                mapa[aux] = i + 1;
            }
            else if(r == 0){
                cout<<mapa[x-aux]<<' '<<i+1;
                r++;
            }
        }
    }
    if(r == 0){
        cout<<"IMPOSSIBLE";
    }
    return 0;
}