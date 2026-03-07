#include<bits/stdc++.h>
using namespace std;
using ll = long long;


void solve(){
    vector<vector<char>> vec (3, vector<char> (3));
    for(int i =0;i<3;i++){
        for(int j=0;j<3;j++){
            cin>>vec[i][j];
        }
    }
    if(vec[1][1] != '.'){
        if((vec[1][1] == vec[2][2] && vec[2][2] == vec[0][0]) || (vec[1][1] == vec[0][2] && vec[0][2] == vec[2][0])){
            cout<<vec[1][1]<<'\n';
            return;
        }
    }
    bool flg1;
    bool flg2;
    for(int i =0;i<3;i++){
        flg1 = true; flg2 = true;
        for(int j=0;j<3;j++){
            if(vec[i][j] != vec[i][i]){
                flg1 = false;
            }
            if(vec[j][i] != vec[i][i]){
                flg2 = false;
            }
        }
        if((flg1 || flg2) && vec[i][i] != '.'){
            cout<<vec[i][i]<<'\n';
            return;
        }
    }
    cout<<"DRAW"<<'\n';
    return;
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}