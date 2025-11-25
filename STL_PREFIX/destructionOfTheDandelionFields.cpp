#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        vector<int> dan;
        int aux;
        ll soma = 0;
        for(int i=0;i<n;i++){
            cin>>aux;
            if(aux%2==0){
                soma = soma + aux;
            }
            else{
                dan.push_back(aux);
            }
        }
        sort(dan.begin(), dan.end());
        int tamanho = dan.size();
        if(!dan.empty()){
            for(int i=tamanho/2;i<tamanho;i++){
                soma = soma + dan[i];
            }
            cout<<soma<<'\n';
        }
        else{
            cout<<"0\n";
        }
    }
    return 0;
}