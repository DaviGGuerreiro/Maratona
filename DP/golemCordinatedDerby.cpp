#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int n;
    cin>>n;
    vector<int> vec (20,0);
    vector<vector<int>> dp (1<<20, vector<int> (20,0));

    int aux;
    for(int i=0;i<n;i++){
        cin>>aux;
        vec[aux-1]++;
    }
    for(int i = 1; i<(1<<20); i++){
        for(int j = 0; j<20; j++) if((i & (1<<j)) && vec[j]>0){
            for(int k = 0; k<20; k++) if(!(i & (1<<k)) && vec[k] > 0){
                dp[i | (1<<k)][k] = max(dp[i | (1<<k)][k], dp[i][j] + gcd(j+1,k+1));
            }
        }
    }    

    int resposta = 0;
    int maior = 0;
    for(int i = 0;i<20;i++){
        if(vec[i]!=0){
            maior = max(maior, dp[(1<<20)-1][i]);
            if(vec[i]>1){
                resposta += (i+1)*(vec[i]-1);
            }
        }
    }
    resposta += maior;
    cout<<resposta;
    return 0;
}