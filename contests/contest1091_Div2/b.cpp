#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n, k;
    cin>>n>>k;
    vector<int> vec (n);
    vector<int> ind (k);
    for(int i = 0; i<n; i++){
        cin>>vec[i];
    }
    for(int i = 0; i<k; i++){
        cin>>ind[i];
    }
    int x = vec[ind[0]-1];
    int l = 0, r= 0;
    bool flip = false;
    for(int i = 0; i <= ind[0]-1; i++){
        if((vec[i] == x && flip) || (vec[i] != x && !flip)){
            l++;
            flip = !flip;
        }
    }
    flip = false;
    for(int i = n-1; i >= ind[0] - 1; i--){
        if((vec[i] == x && flip) || (vec[i] != x && !flip)){
            r++;
            flip = !flip;
        }
    }
    int maximo = max(r, l);
    cout<<maximo<<'\n';
    return;
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}