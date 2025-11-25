#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int n,m,aux;
    cin>>n>>m;
    multiset<int> mt;
    for(int i = 0;i<n;i++){
        cin>>aux;
        mt.insert(aux);
    }
    for(int i = 0;i<m;i++){
        cin>>aux;
        auto it = mt.upper_bound(aux);
        if(it == mt.begin()){
            cout<<-1<<'\n';
        }
        else{
            it--;
            cout<<*it<<'\n';
            mt.erase(it);
        }
    }

    return 0;
}