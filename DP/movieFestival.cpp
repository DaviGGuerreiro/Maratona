#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int n, k;
    cin>>n>>k;
    vector<pair<int,int>> filme (n);
    vector<int> v;
    for(int i=0;i<n;i++){
        cin>>filme[i].first;
        cin>>filme[i].second;
        v.push_back(filme[i].first);
        v.push_back(filme[i].second);
    }
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
    int tamanho = v.size();
    vector<int> contador (tamanho, 0);
    vector<int> quando (tamanho,0);
    vector<int> psum (tamanho+1, 0);
    for(auto it: filme){
        int pos1 = lower_bound(v.begin(),v.end(), it.first) - v.begin();
        int pos2 = lower_bound(v.begin(),v.end(), it.second) - v.begin();
        contador[pos1]++;
        contador[pos2]--;
    }
    psum[0] = 0;
    for(int i=1; i<=tamanho; i++){
        psum[i] = psum[0] + contador[i-1];
    }

    return 0;
}