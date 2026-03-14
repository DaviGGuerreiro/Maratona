#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
    int h, w, n;
    cin>>h>>w>>n;
    vector<pair<int, int>> blocoh (n);
    vector<pair<int, int>> blocow (n);
    map<pair<int,int>, int> mapa;
    map<pair<int,int>, int> times;
    vector<pair<int,int>> v (n);
    for(int i=0;i<n;i++){
        cin>>blocoh[i].first>>blocoh[i].second;
        blocow[i].first = blocoh[i].second; v[i].first = blocoh[i].first;
        blocow[i].second = blocoh[i].first; v[i].second = blocoh[i].second;
        mapa[blocoh[i]]++;
        times[blocoh[i]]++;
    }
    sort(blocoh.begin(),blocoh.end());
    sort(blocow.begin(),blocow.end());
    int x = 1; int y = 1;
    int aux_h = h; int aux_w = w;
    int l = n-1, r = n-1;
    map<tuple<int,int,int>, pair<int,int>> resposta;
    while(aux_h != 0 && aux_w != 0){
        while(mapa[blocoh[l]] == 0){
            l--;
        }
        while(mapa[{blocow[r].second,blocow[r].first}] == 0){
            r--;
        }

        if(l >= 0 && blocoh[l].first == aux_h){
            mapa[blocoh[l]]--;
            aux_w -= blocoh[l].second;
            resposta[{blocoh[l].first,blocoh[l].second,mapa[blocoh[l]]}] = {y,x};
            x += blocoh[l].second;
            l--;
        }
        else if (r>=0){
            mapa[{blocow[r].second,blocow[r].first}]--;
            aux_h -= blocow[r].second;
            resposta[{blocow[r].second, blocow[r].first, mapa[{blocow[r].second,blocow[r].first}]}] = {y,x};
            y += blocow[r].second;
            r--;
        }
    }
    pair<int,int> res;
    for(int i = 0; i<n; i++){
        times[v[i]]--;
        res = resposta[{v[i].first, v[i].second, times[v[i]]}];
        cout<<res.first<<" "<<res.second<<'\n';
    }
    return;
}


int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    solve();
    return 0;
}