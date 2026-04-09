#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

void solve(){
    int c, p; cin>>c>>p;
    map<string, tuple<int,int,int>> mapa;
    string aux;
    int s, m, l;
    int d = 100/p;
    for(int i = 0; i <c; i++){
        cin>>aux; cin>>s>>m>>l;
        mapa[aux] = {s,m,l};
    }
    string cafe, tamanho;
    int k;
    for(int i = 0; i < p; i++){
        cin>>aux>>tamanho>>cafe;
        if(tamanho[0] == 's') k = get<0>(mapa[cafe]);
        else if(tamanho[0] == 'm') k = get<1>(mapa[cafe]);
        else k = get<2>(mapa[cafe]);
        k += d;
        if(k % 5 == 1) k--;
        else if(k % 5 == 4) k++;
        cout<<aux<<' '<<k<<'\n';
    }
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    cout<<fixed<<setprecision(5);
    freopen("coffee.in","r",stdin);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}