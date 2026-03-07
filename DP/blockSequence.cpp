#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int t, n;

int solve(){}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    cin>>t;
    int aux;
    while(t--){
        cin>>n;
        vector<int> dp (n);
        vector<int> esq (n,-1);
        vector<int> dir (n,-1);
        for(int i=0;i<n;i++){
            cin>>dp[i];
        }
        aux = 0;
        for(int i=n-1;i>=0;i--){
            if(n - 1 - i >= dp[i]){
                dir[i] = n - 1 - i - dp[i];
                aux = dir[i];
            }
            else if(aux != 0){
                aux++;
                dir[i] = aux;
            }
        }
    }
    return 0;
}