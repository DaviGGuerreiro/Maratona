#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
    int n, m; cin>>n>>m;
    map<int, set<pair<int,bool>>> mapa;
    map<int, bool> ligado;
    vector<int> indices;
    int a, b, x;
    int ativo = n;
    for(int i = 0; i<n; i++){
        cin>>a>>b;
        ligado[a] = true;
        for(int j = 0; j<b; j++){
            cin>>x;
            mapa[a].insert({x,0});
        }
        indices.push_back(a);
    }
    for(int i = 0; i<m; i++){
        cin>>a>>b;
        if(mapa[a].size() == 0){ ativo ++; indices.push_back(a); ligado[a] = true;};
        for(int j = 0; j<b; j++){
            cin>>x;
            auto it = mapa[a].find({x,0});
            if(it != mapa[a].end()){
                mapa[a].erase(it);
            }
            else{
                mapa[a].insert({x,1});
            }
        }
        if(mapa[a].size() == 0){ ativo --; ligado[a] = false;}
    }
    sort(indices.begin(),indices.end());
    if(ativo == 0){
        cout<<"GREAT WORK! NO MISTAKES FOUND!"<<'\n';
        return;
    }
    int falta = 0, mais = 0;
    for(auto it : indices){
        if(!ligado[it]) continue;
        cout<<it<<' ';
        for(auto et : mapa[it]){
            if(et.second == 0){
                falta++;
                cout<<'+'<<et.first<<' ';
            }
            else{
                mais++;
                cout<<'-'<<et.first<<' ';
            }
        }
        cout<<'\n';
    }
    cout<<"MISTAKES IN "<<ativo<<" STUDENTS: "<<mais<<" NOT REQUESTED, "<<falta<<" MISSED"<<'\n';
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    solve();
    return 0;
}