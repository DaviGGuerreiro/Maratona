#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int t;
    int n;
    int max;
    int resp;
    int vazio;
    int j;
    int r;
    cin>>t;
    while(t--){
        vazio = 0;
        r=0;
        max = 1;
        bool var = true;
        cin>>n;
        map<int, int> mapa;
        vector<int> aux (n);
        vector<int> vec (n+2,0);
        for(int i=0;i<n;i++){
            cin>>aux[i];
        }
        sort(aux.begin(),aux.end());
        for(j=0;j<n && var == true;j++){
            if(vazio == aux[j]){
                mapa[aux[j]]++;
                vec[mapa[aux[j]]]++;
                vazio++;
            }
            else if(vazio > aux[j]){
                mapa[aux[j]]++;
                vec[mapa[aux[j]]]++;
                if(max<mapa[aux[j]]){
                    max = mapa[aux[j]];
                }
                r++;
            }
            else{
                var = false;
            }
        }
        resp = 0;
        cout<<1<<' ';
        for(int i=1;i<=n;i++){
            if(i <= max){
                resp = resp + vec[i] - vec[i+1];
                if(i == max && r == max-1 && r + vazio == n){
                    resp--;
                }
                cout<<resp+1<<' ';
            }
            else{
                if(i <= n - vazio){
                    cout<<resp+1<<' ';
                }
                else{
                    resp--;
                    cout<<resp+1<<' ';
                }
            }
        }
        cout<<'\n';
    }
    return 0;
}