#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int t, n, k, i;
    cin>>t;
    while(t--){
        cin>>n>>k;
        vector<int> num (n+2,0);
        int aux;
        for(i=0;i<n;i++){
            cin>>aux;
            num[aux]++;
        }
        pair<int,int> par {-1,0};
        int qntp=n, qntb=n;
        int buraco;
        int sb=0, sm;
        int resposta = 0;
        for(i = 0; i<n+2; i++){
            if(num[i] == 0){
                buraco = i;
                break;
            }
            else if(num[i] > 1){
                sm = sb;
                par = make_pair(i,sm);
                qntp = qntb;
            }
            else{
                qntb--;
                sb = sb + i;
            }
        }
        if(par.first != -1){
            if(k==1){
                resposta = sb + (qntb)*buraco;
            }
            else if(k%2==0){
                resposta = par.second + (qntp)*par.first;
            }
            else{
                if(qntp>1){
                    resposta = par.second + (qntp)*(par.first+1);
                }
                else{
                    resposta = par.second + (qntp)*par.first;
                }
            }
        }
        else{
            if(k%2==0){
                if(qntb>1){
                    resposta = sb + (qntb)*(buraco+1);
                }
                else{
                    resposta = sb + (qntb)*buraco;
                }
            }
            else{
                resposta = sb + (qntb)*buraco;
            }
            
        }
        cout<<resposta<<'\n';
    }
    return 0;
}