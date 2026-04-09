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
        cin>>ind[i]; ind[i]--;
    }
    int x = vec[ind[0]];
    vector<int> left (k+1,0);
    int q = 0, j = 0;
    bool ativo = false;
    for(int i = 0; i<n; i++){
        if(vec[i] != x && !ativo) {ativo = true; q++;}
        else if(ativo){
            if(vec[i] != vec[i-1]){
                q++;
            }
        }
        if(j != k && i == ind[j]){
            left[j] = q;
            j++;
            q = 0;
        }
    }

    if(q == 0) left[k] = 0;
    else if(q % 2 == 1) left[k] = q + 1;
    else left[k] = q;

    int soma = 0; int maximo = 0;
    for(int i = 0; i<=k; i++){
        maximo = max(maximo, left[i]);
        soma += left[i];
    }
    if(soma - maximo < maximo){
        cout<<maximo<<'\n';
    }
    else{
        soma /= 2;
        cout<<soma<<'\n';
    }
    return;
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}