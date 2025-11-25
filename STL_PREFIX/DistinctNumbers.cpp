#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int t, aux;
    cin>>t;
    vector<int> vec;
    while(t--){
        cin>>aux;
        vec.push_back(aux);
    }
    sort(vec.begin(),vec.end());
    int n = vec.size();
    int ant = -1;
    int resposta = 0;
    for(int i=0;i<n;i++){
        if(ant != vec[i]){
            ant = vec[i];
            resposta++;
        }
    }
    cout<<resposta;

    return 0;
}