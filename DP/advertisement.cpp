#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll maior = 0;
int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int n;
    cin>>n;
    vector<int> vec (n+1);
    vec[n] = -1;
    for(int i=0; i<n; i++){
        cin>>vec[i];
    }
    vector<int> dp (n);
    stack<int> pilha;
    ll ans = 0;
    for(int i=0;i<=n;i++){
        while(!pilha.empty() && vec[i] <= vec[pilha.top()]){
            int aux = vec[pilha.top()];
            pilha.pop();
            int l;
            if(pilha.empty()){
                l = -1;
            }
            else{
                l = pilha.top();
            }
            ans = max(ans, 1LL * (i - l - 1) * aux);
        }
        pilha.push(i);
    }
    cout<<ans;
    return 0;
}