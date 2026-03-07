#include<bits/stdc++.h>
using namespace std;
using ll = long long;

bool solve(pair<int,int>& a, pair<int,int>& b){
    if(a.second < b.second){
        return true;
    }
    return false;
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int n, k;
    cin>>n>>k;
    vector<pair<int,int>> filme (n);
    for(int i=0;i<n;i++){
        cin>>filme[i].first;
        cin>>filme[i].second;
    }
    sort(filme.begin(),filme.end(), solve);
    multiset<int> livre;
    for(int i=0; i<k; i++){
        livre.insert(0);
    }
    int f = 0;
    for(int i=0;i<n;i++){
        auto it = livre.upper_bound(filme[i].first);
        if(it != livre.begin()){
            it--;
            livre.erase(it);
            livre.insert(filme[i].second);
            f++;
        }
        else{
            if(filme[i].first == *livre.begin()){
                livre.erase(it);
                livre.insert(filme[i].second);
                f++;
            }
        }
    }
    cout<<f;
    return 0;
}