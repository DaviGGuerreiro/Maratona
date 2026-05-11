#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
    int n; cin>>n;
    vector<int> vec (n);
    for(int i = 0; i<n; i++){
        cin>>vec[i];
    }
    int maior; int menor; int quantidade;
    for(int i = 0; i<n; i++){
        quantidade = 0;
        maior = 0;
        menor = 0;
        for(int j = i+1; j<n; j++){
            if(vec[i] > vec[j]){
                menor++;
            }
            else if(vec[i] < vec[j]){
                maior++;
            }
        }
        quantidade = max(maior, menor);
        cout<<quantidade<<' ';
    }
    cout<<'\n';
    return;
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}