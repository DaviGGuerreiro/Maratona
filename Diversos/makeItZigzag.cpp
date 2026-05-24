#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
    int n; cin>>n;
    vector<int> vec (n);
    for(int i = 0; i<n ;i++){
        cin>>vec[i];
    }
    int resposta = 0;
    int maximo = -1;
    for(int i = 0; i<n; i++){
        maximo = max(maximo, vec[i]);
        if(i%2 == 1){
            vec[i] = maximo;

            if(vec[i] <= vec[i-1]){
                resposta += vec[i-1] - vec[i] + 1;
                vec[i-1] -= vec[i-1] - vec[i] + 1;
            }

            if(i!= n-1 && vec[i] <= vec[i+1]){
                resposta += (vec[i+1] - vec[i]) + 1;
                maximo = max(maximo, vec[i+1]);
                vec[i+1] -= (vec[i+1] - vec[i]) + 1;
            }
        }
    }
    cout<<resposta<<'\n';
}


int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int t; cin>>t;
    while(t--){
        solve();
    }
    return 0;
}