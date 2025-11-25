#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int n,k,q;
    cin>>n>>k>>q;
    int r = k-q;
    vector<int> players (n,0);
    int aux;
    while(q--){
        cin>>aux;
        players[aux-1]++;
    }
    for(int i=0;i<n;i++){
        if(r+players[i] > 0){
            cout<<"Yes\n";
        }
        else{
            cout<<"No\n";
        }
    }
    return 0;
}