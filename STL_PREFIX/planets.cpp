#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int t, aux;
    int n, c;
    int r;
    cin>>t;
    while(t--){
        cin>>n>>c;
        map<int, int> mapa;
        r = 0;
        while(n--){
            cin>>aux;
            mapa[aux]++;
        }
        for(auto p : mapa){
            if(p.second < c){
                r = r + p.second;
            }
            else{
                r = r + c;
            }
        }
        cout<<r<<'\n';
    }
    return 0;
}