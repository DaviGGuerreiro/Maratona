#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int n, aux;
    int repet = 0;
    map<int,int> mapa;
    cin>>n;
    for(int i = 0;i<n;i++){
        cin>>aux;
        mapa[aux]++;
        if(repet < mapa[aux]){
            repet = mapa[aux];
        }
    }
    cout<<repet;
    return 0;
}