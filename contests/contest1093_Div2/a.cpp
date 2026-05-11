#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
    int n; cin>>n;
    int aux = 0;
    if(n == 1){cin>>aux; cout<<aux<<'\n'; return;}
    vector<int> vec (n);
    for(int i = 0; i<n; i++){
        cin>>vec[i]; 
    }
    bool b = true;
    sort(vec.begin(), vec.end());
    for(int i = n-2; i>=0; i--){
        if(vec[i] == vec[i+1]){
            b = false; break;
        }
    }
    if(b){
        for(int i = n-1; i>=0; i--){
            cout<<vec[i]<<' ';
        }
        cout<<'\n';
    }
    else{
        cout<<-1<<'\n';
    }

}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}