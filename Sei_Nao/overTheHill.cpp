#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int n;

void solve(){
    cin>>n;
    vector<vector<int>> vec (n, vector<int> (n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>vec[i][j];
        }
    }
    string s;
    getline(cin, s); getline(cin, s);
    if(s.size() == 0){
        return;
    }
    vector<vector<int>> v;
    vector<int> frase;
    v.push_back({});
    int l = 0;
    for(auto it: s){
        if((int)v[l].size() == n){
            v.push_back({});
            l++;
        }
        if(it == ' '){
            v[l].push_back(36);
        }
        else if(it>=65){
            v[l].push_back(it - 65);
        }
        else{
            v[l].push_back(it - 22);
        }
    }
    while((int)v[l].size()<n){
        v[l].push_back(36);
    }
    for(auto it : v){
        int k;
        for(int i=0;i<n;i++){
            k = 0;
            for(int j=0;j<n;j++){
                k += vec[i][j] * it[j];
            }
            k = k%37;
            frase.push_back(k);
        }
    }
    char aux;
    for(int i = 0; i<(int)frase.size();i++){
        if(frase[i] == 36){
            cout<<' ';
        }
        else if(frase[i] >=26 && frase[i]<=35){
            aux = frase[i] + 22;
            cout<<aux;
        }
        else if(frase[i]>=0 && frase[i]<=25){
            aux = frase[i] + 65;
            cout<<aux;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    solve();
    return 0;
}