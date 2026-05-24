#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
    int n; cin>>n;
    vector<pair<int,int>> vec (n);
    vector<char> estado (n);
    for(int i = 0; i<n; i++){
        cin>>vec[i].first>>vec[i].second;
        if(vec[i].first == vec[i].second){
            estado[i] = 't';
        }
        else if(vec[i].first > vec[i].second){
            estado[i] = 'd';
        }
        else{
            estado[i] = 'e';
        }
    }
    ll soma1 = 0;
    ll soma2 = 0;
    int visitados = 0;
    vector<int> percurso1;
    vector<int> percurso2;
    for(int i = 0; i<n; i++){
        if(estado[i] == 't' || estado[i] == 'd'){
            if(i == n-1){
                if(visitados == n-1) soma1 += min(vec[i].first, vec[i].second);
                else soma1 += vec[i].first;
            } 
            else{
                soma1 += vec[i].second;
            }
            visitados++;
            percurso1.push_back(i+1);
        }
    }
    if(visitados != n){
        for(int i = n-1; i>=0; i--){
            if(estado[i] == 'e'){
                if(i == 0){
                    soma1 += min(vec[i].first, vec[i].second);
                } 
                else{
                    soma1 += vec[i].first;
                }
                percurso1.push_back(i+1);
            }
        }
    }
    visitados = 0;
    for(int i = n-1; i>=0; i--){
        if(estado[i] == 't' || estado[i] == 'e'){
            if(i == 0){
                if(visitados == n-1) soma2 += min(vec[i].first, vec[i].second);
                else soma2 += vec[i].second;
            } 
            else{
                soma2 += vec[i].first;
            }
            visitados++;
            percurso2.push_back(i+1);
        }
    }
    if(visitados != n){
        for(int i = 0; i < n; i++){
            if(estado[i] == 'd'){
                if(i == n-1){
                    soma2 += min(vec[i].first, vec[i].second);
                } 
                else{
                    soma2 += vec[i].second;
                }
                percurso2.push_back(i+1);
            }
        }
    }
    if(soma1 > soma2){
        for(auto it : percurso2){
            cout<<it<<' ';
        }
    }
    else{
        for(auto it : percurso1){
            cout<<it<<' ';
        }
    }
    cout<<'\n';
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    solve();
    return 0;
}