#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);cin.tie(0);

    int t;
    int n;
    int aux;
    int resposta;
    cin>>t;
    while(t--){
        resposta = 0;
        cin>>n;
        vector<int> vec;
        for(int i=0;i<2*n;i++){
            cin>>aux;
            vec.push_back(aux);
        }
        sort(vec.begin(), vec.end());
        for(int i=0;i<2*n;i=i+2){
            resposta = resposta + vec[i];
        }
        cout<<resposta<<'\n';
    }

    return 0;
}