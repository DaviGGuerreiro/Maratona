#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int t;
    int n, d;
    cin>>t;
    while(t--){
        cin>>n>>d;
        vector<int> pos (n);
        for(int i=0;i<n;i++){
            cin>>pos[i];
        }
        vector<pair<int,int>> pratos (n);
        for(int i=0;i<n;i++){
            pratos[i].first = pos[i];
            cin>>pratos[i].second;
        }
        sort(pratos.begin(),pratos.end());
        priority_queue<int> pq;
        int quantidade = 0;
        int maior = 0;
        int gasto = 0;
        int livre;
        for(int i=0;i<n;i++){
            livre = d - pratos[i].first;
            if(livre > 0){
                while(livre < gasto){
                    quantidade--;
                    livre += pq.top();
                    gasto -= pq.top();
                    pq.pop();
                }
                if(livre - gasto >= pratos[i].second){
                    pq.push(pratos[i].second);
                    gasto += pratos[i].second;
                    quantidade++;
                    maior = max(maior,quantidade);
                }
                else if(!pq.empty() && pratos[i].second < pq.top()){
                    gasto -= pq.top();
                    gasto += pratos[i].second;
                    pq.pop();
                    pq.push(pratos[i].second);
                }
            }
            else{
                break;
            }
        }
        cout<<maior<<'\n';
    }

    return 0;
}