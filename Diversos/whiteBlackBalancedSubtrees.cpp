#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int n;

void solve(){
    cin>>n;
    vector<pair<int,int>> quantidade (n, {0,0});
    vector<int> vec (n-1);
    vector<int> grau (n-1, 0);
    for(int i=0;i<n-1;i++){
        cin>>vec[i];
        grau[vec[i]-1]++;
    }
    string s; cin>>s;
    for(int i=0;i<n;i++){
        if(s[i] == 'W'){
            quantidade[i].first++;
        }
        else{
            quantidade[i].second++;
        }
    }
    int k = 0;
    for(int i=n-2;i>=0;i--){
        quantidade[vec[i]-1].first = quantidade[vec[i]-1].first + quantidade[i+1].first;
        quantidade[vec[i]-1].second = quantidade[vec[i]-1].second + quantidade[i+1].second;
        grau[vec[i]-1]--;
        if(quantidade[vec[i]-1].first == quantidade[vec[i]-1].second && grau[vec[i]-1] == 0){
            k++;
        }
    }
    cout<<k<<'\n';
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int t; cin>>t;
    while(t--){
       solve(); 
    }
    return 0;
}