#include<bits/stdc++.h>
using namespace std;

void solve(){
    string s;
    cin>>s;
    int t = (int)s.size();
    vector<int> count (t,0);
    vector<int> psum (t+1);
    psum[0] = 0;
    for(int i=0;i<t;i++){
        if(s[i] == '+'){
            count[i] = 1;
        }
        else{
            count[i] = -1;
        }
    }
    int maior = -1e9; int ind = 0;
    for(int i = 1;i<=t;i++){
        psum[i] = psum[i-1]+count[i-1];
        if(maior<psum[i]){
            maior = psum[i];
            ind = i;
        }
    }
    cout<<ind;
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    solve();
    return 0;
}