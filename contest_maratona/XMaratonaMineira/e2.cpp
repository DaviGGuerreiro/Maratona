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
    vector<int> percurso;
    if(n == 1){ cout<<1<<' '<<'\n'; return;}
    if(estado[0] == 'e' && estado[n-1] == 'd'){
        if(min(vec[0].first, vec[0].second) + vec[n-1].first > min(vec[n-1].first, vec[n-1].second) + vec[0].second){
            for(int i = n-1; i>=0; i--){
                if(estado[i] == 'e' || estado[i] == 't'){
                    percurso.push_back(i+1);
                }
            }
            for(int i = 0; i < n; i++){
                if(estado[i] == 'd'){
                    percurso.push_back(i+1);
                }
            }
        }
        else{
            for(int i = 0; i < n; i++){
                if(estado[i] == 't' || estado[i] == 'd'){
                    percurso.push_back(i+1);
                }
            }
            for(int i = n-1; i>=0; i--){
                if(estado[i] == 'e'){
                    percurso.push_back(i+1);
                }
            }
        }
    }
    else{
        if(estado[0] == 'd'){
            for(int i = n-1; i>=0; i--){
                if(estado[i] == 'e' || estado[i] == 't'){
                    percurso.push_back(i+1);
                }
            }
            for(int i = 0; i < n; i++){
                if(estado[i] == 'd'){
                    percurso.push_back(i+1);
                }
            }
        }
        else{
            for(int i = 0; i < n; i++){
                if(estado[i] == 'd' || estado[i] == 't'){
                    percurso.push_back(i+1);
                }
            }
            for(int i = n-1; i>=0; i--){
                if(estado[i] == 'e'){
                    percurso.push_back(i+1);
                }
            }
        }
    }
    for(auto it : percurso){
        cout<<it<<' ';
    }
    cout<<'\n';
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    solve();
    return 0;
}