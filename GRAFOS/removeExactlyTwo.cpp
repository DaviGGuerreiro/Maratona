#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int t, n;
    int u, v;
    cin>>t;
    while(t--){
        cin>>n;
        vector<set<int>> vec (n+1);
        vector<int> visitados (n+1,-1);
        for(int i=1;i<n;i++){
            cin>>u>>v;
            vec[u].insert(v);
            vec[v].insert(u);
        }
        int ind=0;
        int aux1=0;
        int quantidade = 0;
        for(int i=1;i<=n;i++){
            if(vec[i].size()>aux1){
                aux1 = vec[i].size();
                ind = i;
            }
        }
        for(auto x : vec[ind]){
            if(vec[x].size() == vec[ind].size()){
                quantidade++;
            }
            vec[x].erase(vec[x].find(ind));
        }
        int aux2=0;
        for(int i=1;i<=n;i++){
            if(i != ind){
                if(vec[i].size() > aux2){
                    aux2 = vec[i].size();
                }
                if(vec[i].size() == vec[ind].size()){
                    quantidade = 0;
                }
            }
        }
        if(quantidade >= 2){
            cout<<aux1+aux2<<'\n';
        }
        else{
            cout<<aux1+aux2-1<<'\n';
        }
    }

    return 0;
}