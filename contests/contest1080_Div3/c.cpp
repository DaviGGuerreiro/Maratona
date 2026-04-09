#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin>>n;
    vector<int> vec (n);
    vector<bool> vis (n-1); 
    for(int i = 0; i<n; i++){
        cin>>vec[i];
        if(i > 0){
            if(vec[i] == vec[i-1] || vec[i] + vec[i-1] == 7){
                vis[i-1] = false;
            }
            else{
                vis[i-1] = true;
            }
        }
    }
    int resposta = 0;
    for(int i = 0; i< n- 1; i++){
        
    }

    return;
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int t; cin>>t;
    while(t--){
        solve();
    }
    return 0;
}