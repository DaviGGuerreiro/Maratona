#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int t;
    cin>>t;
    int n, k;
    while(t--){
        cin>>n>>k;
        vector<int> frutas (n);
        for(int i=0;i<n;i++){
            cin>>frutas[i];
        }
        vector<int> tamanhos (n);
        for(int i=0;i<n;i++){
            cin>>tamanhos[i];
        }
        int l = 0;
        int quantidade = 0;
        int ant = tamanhos[0];
        int resposta = 0;
        for(int r=0;r<n;r++){
            if(ant%tamanhos[r] != 0){
                l = r;
                quantidade = frutas[r];
            }
            else{
                quantidade += frutas[r];
            }

            while(quantidade > k){
                quantidade -= frutas[l];
                l++;
            }

            if(quantidade == 0){
                if(r!=n-1){
                    ant = tamanhos[r+1];
                }
            }
            else{
                resposta = max(resposta, r-l+1);
                ant = tamanhos[r];
            }
        }
        cout<<resposta<<'\n';
    }
    return 0;
}