#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int n, t, q;
    cin>>n>>t>>q;
    map<int, queue<int>> mapa;
    map<int, queue<int>> mapa2;
    int d, p, x;
    for(int i=0;i<q; i++){
        cin>>d>>p>>x;
        mapa[d].push(p);
        if(x + d <= t){
            mapa2[d+x].push(p);
        }
    }
    set<int> c;
    for(int i=1;i<=n;i++){
        c.insert(i);
    }
    auto it = c.begin();
    for(int i=0;i<=t;i++){
        if(i != 0){
            if(it == c.end()){
                it = c.begin();
            }
            if(c.empty()){
                cout<<-1<<' ';
            }
            else{
                cout<<*it<<' ';
            }
            while(!mapa2[i+1].empty()){
                c.insert(mapa2[i+1].front());
                mapa2[i+1].pop();
            }
            if(it != c.end()){
                ++it;
            }
        }
        while(!mapa[i+1].empty()){
            if(it != c.end() && *it == mapa[i+1].front()){
                ++it; 
            }
            c.erase(mapa[i+1].front());
            mapa[i+1].pop();
            if(i == 0){
                it = c.begin();
            }
        }
    }
    return 0;
}