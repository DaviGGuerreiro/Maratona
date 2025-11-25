#include<bits/stdc++.h>
using namespace std;
int n;

vector<char> topo(vector<vector<char>>& vec, vector<int>& deg){
    queue<int> fila;
    for(int i=0;i<26;i++){
        if(deg[i]==0){
            fila.push(i);
        }
    }
    vector<char> t;
    while(!fila.empty()){
        int aux = fila.front();
        fila.pop();
        t.push_back((char)('a'+aux));
        for(auto x : vec[aux]){
            deg[x-'a']--;
            if(deg[x-'a'] == 0){
                fila.push(x-'a');
            }
        }
    }
    return t;
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    cin>>n;
    string s;
    vector<vector<char>> vec (26);
    vector<int> deg (26, 0);
    while(n--){
        cin>>s;
        for(size_t i=0;i<s.size()-1;i++){
            if(s[i]!=s[i+1]){
                vec[s[i]-'a'].push_back(s[i+1]);
                deg[s[i+1]-'a']++;
            }
        }
    }
    auto v = topo(vec, deg);
    if(v.size() != 26){
        cout<<"NAO";
    }
    else{
        cout<<"SIM\n";
        for(auto x : v){
            cout<<x;
        }
    }
    return 0;
}