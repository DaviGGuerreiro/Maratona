#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int n, m;
vector<int> vec;
queue<int> fila;

void pvec(){
    for(int i = 0;i<n;i++){
        fila.push(vec[i]);
    }
}

void solve(){
    vec = vector<int> (n);
    int r = 0;
    vec[0] = 1;
    for(int i=1;i<n;i++){ 
        vec[i] = vec[i-1]+10;
        if(vec[i]>m){
            cout<<0;
            return;
        }
    }
    int j = 0;
    while(true){
        r++;
        pvec();
        j = n-1;
        while(vec[j] + ((n-j-1)*10) == m){
            j--;
        }
        if(j<0){
            break;
        }
        vec[j]++;
        while(j != n-1){
            vec[j+1] = vec[j] + 10;
            j++;
        }
    }
    cout<<r<<'\n';
    while(!fila.empty()){
        for(int i = 0; i<n; i++){
            cout<<fila.front();
            if(i != n-1) cout<<' ';
            fila.pop();
        }
        cout<<'\n';
    }
    
}


int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    cin>>n>>m;
    solve();
    return 0;
}