#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int t;
    cin>>t;
    int n;
    while(t--){
        cin>>n;
        vector<int> vec (n);
        for(int i=0;i<n;i++){
            cin>>vec[i];
        }
        sort(vec.begin(),vec.end());
        int resposta = vec[0];
        for(int i=1;i<n;i++){
            if(vec[i] > vec[0]){
                if(vec[i]-resposta > resposta){
                    resposta = vec[i] - resposta;
                }
                break;
            } 
        }
        cout<<resposta<<'\n';
    }
    return 0;
}