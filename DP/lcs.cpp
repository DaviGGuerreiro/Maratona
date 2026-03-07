#include<bits/stdc++.h>
using namespace std;
using ll = long long;
string s, t;
vector<vector<int>> dp;
vector<vector<int>> rec;

int best(int i, int j){
    if(i < 0 || j < 0) return 0;
    if(dp[i][j] != -1) return dp[i][j];
    dp[i][j] = 0;
    if(s[i] == t[j]){
        rec[i][j] = 0;
        dp[i][j] = 1 + (best(i-1, j-1));
    }
    else{
        int a = best(i-1,j);
        int b = best(i,j-1);
        if(a>b){
            rec[i][j] = 1;
            dp[i][j] = a;
        }
        else{
            rec[i][j] = 2;
            dp[i][j] = b;
        }
    }
    return dp[i][j];
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    cin>>s>>t;
    int n = s.size();
    int m = t.size();
    dp = vector<vector<int>>(n, vector<int> (m,-1));
    rec = vector<vector<int>>(n, vector<int> (m,-1));
    int resposta = best(n-1,m-1);
    int a = n-1;
    int b = m-1;
    int aux;
    stack<int> pilha;
    while(a >= 0 && b >= 0 && aux != -1){
        aux = rec[a][b];
        if(aux == 0){
            pilha.push(a);
            a--;
            b--;
        }
        else if(aux == 1){
            a--;
        }
        else if (aux == 2){
            b--;
        }
    }
    while(!pilha.empty()){
        cout<<s[pilha.top()];
        pilha.pop();
    }
    return 0;
}