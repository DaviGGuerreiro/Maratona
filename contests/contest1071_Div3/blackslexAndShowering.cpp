#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int t;
    int n;
    cin>>t;
    while(t--){
        cin>>n;
        vector<int> vec (n);
        for(int i=0;i<n;i++){
            cin>>vec[i];
        }
        vector<int> v (n);
        v[0] = abs(vec[1]-vec[0]);
        for(int i=1;i<n;i++){
            v[i] = abs(vec[i]-vec[i-1]);
            if(i!=n-1){
                v[i] += abs(vec[i+1]-vec[i]);
            }
        }
        int maior = 0;
        int ind = -1;
        int aux;
        for(int i=0;i<n;i++){
            if(i == 0 || i == n-1){
                aux = v[i];
            }
            else{
                aux = v[i] - abs(vec[i-1] - vec[i+1]);
            }
            if(maior < aux){
                maior = aux;
                ind = i;
            }
        }
        int resposta = 0;
        for(int i=0;i<n;i++){
            if(i != n-1){
                resposta += abs(vec[i]-vec[i+1]);
            }
            if(ind == i){
                resposta = resposta - maior;
            }
        }
        cout<<resposta<<'\n';
    }
    return 0;
}