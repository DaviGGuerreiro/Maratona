#include<bits/stdc++.h>
using namespace std;
using ll = long long;
struct tipo{
    int x;
    int y;
    ll z;
    tipo(int _x, int _y, ll _z) : x(_x), y(_y), z(_z) {}
};

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int n, m;
    cin>>n>>m;
    int a, b;
    ll c;
    vector<pair<ll,int>> vec (n, {0,0});
    for(int i = 0; i<n; i++){
        vec[i].second = i;
    }
    for(int i=0;i<m;i++){
        cin>>a>>b>>c;
        a--;
        b--;
        vec[b].first = vec[b].first + c;
        vec[a].first = vec[a].first - c;
    }
    sort(vec.begin(),vec.end());
    queue<tipo> fila;
    int l = 0;
    int r = n-1;
    int quantidade = 0;
    while(vec[r].first>0){
        vec[l].first = vec[l].first + vec[r].first;
        fila.emplace(vec[r].second+1,vec[l].second+1,vec[r].first);
        vec[r].first = 0;
        quantidade++;
        if(vec[l].first < 0){
            r--;
        }
        else if(vec[l].first == 0){
            l++;
            r--;
        }
        else{
            r--;
            while(vec[l].first > 0){
                vec[l+1].first = vec[l+1].first + vec[l].first;
                fila.emplace(vec[l].second+1,vec[l+1].second+1,vec[l].first);
                vec[l].first = 0;
                l++;
                quantidade++;
            }
        }
    }
    cout<<quantidade<<'\n';
    while(!fila.empty()){
        auto it = fila.front();
        cout<<it.x<<" "<<it.y<<" "<<it.z<<'\n';
        fila.pop();
    }

    return 0;
}