#include<bits/stdc++.h>
using namespace std;

bool solve(pair<int,int>& a, pair<int,int>& b){
    if(a.second<b.second){
        return true;
    }
    else{
        return false;
    }
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int t;
    cin>>t;
    int n;
    while(t--){
        cin>>n;
        vector<pair<int,int>> vec (n);
        for(int i = 0; i<n; i++){
            cin>>vec[i].first;
            cin>>vec[i].second;
        }
        sort(vec.begin(),vec.end(), solve);
        int k = -1;
        int resposta = 0;
        for(int i=0;i<n; i++){
            if(k <= vec[i].first){
                resposta++;
                k = vec[i].second;
            }
        }
        cout<<resposta<<'\n';
    }


    return 0;
}