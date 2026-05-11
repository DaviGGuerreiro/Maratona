#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int n;
vector<int> vec;

bool func(int tamanho){
    bool resposta = false;
    for(int i = 1; i<=n; i++){
        int k = 0; resposta = true;
        if(i + 2 * tamanho - 2 > n) return false;
        for(int j = 0; j < tamanho; j++){
            k++;
            if(vec[i + j] < k){ resposta = false; break;}
        }
        if(!resposta) continue;
        for(int j = tamanho; j <= 2 * tamanho - 2; j++){
            k--;
            if(vec[i+j] < k){resposta = false; break;}
        }
        if(resposta) return true;
    }
    return resposta;
}

void solve(){
    cin>>n;
    vec = vector<int> (n+1);
    for(int i = 1; i<=n; i++) cin>>vec[i];
    int l = 1; int r = 50000;
    int resposta;
    while(r >= l){
        int mid = l + ((r-l)/2);
        if(func(mid)){
            l = mid + 1;
            resposta = mid;
        }
        else{
            r = mid - 1;
        }
    }
    cout<<resposta<<'\n';
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    solve();
    return 0;
}