#include<bits/stdc++.h>
using namespace std;
using ll = long long;
void solve(){
    int n, x; ll aux;
    cin>>n>>x;
    multiset<ll> conjunto;
    ll metade = 0; bool b = false;
    vector<ll> vec (n,0);
    if(n % 2 == 0) b = true;
    for(int i = 0; i <n; i++){
        cin>>aux;
        if(b && aux == n/2) metade++;
        else conjunto.insert(aux);
    }
    if(metade > n/2){
        cout<<'*'; return;
    }
    ll ultimo = 0;
    ll y = 0;
    for(int i = 0; i<n; i++){
        if(vec[i] == 0){
            if
            else if(*conjunto.begin() + ultimo == x){
                
            }
            else{
                vec[i] = *conjunto.begin();
                ultimo = vec[i];
            }
        }
        else{
            ultimo = 0;
        }
    }

}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    solve();
    return 0;
}