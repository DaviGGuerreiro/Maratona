#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<long,long>;

#define FOR(i,n) for(int i=0;i<n;i++)
#define FOR1(i,n) for(int i=1;i<=n;i++)
#define dbg(x) cerr << #x << " = " << x << '\n'

int n, k;
int resposta = 0;
string s, aux;

void solve(){
    cin>>s>>aux;
    bool sobrou_x;
    if(aux[0] == aux[1]){
        int r = 0;
        for(int i=0;i<n;i++){
            if(s[i] == aux[0]){
                r++;
            }
        }
        resposta = min(n, r+k);
        resposta = resposta*(resposta-1);
        resposta = resposta/2;
        cout<<resposta;
        return;
    }
    for(int i = 0; i <= k ; i++){
        int e = k - i;
        sobrou_x = true;
        for(int j = 0; j <= i && sobrou_x; j++){
            for(int l = 0; l <= e; l++){
                int comeco = i;
                int final = e;
                int apaga_comeco = j;
                int apaga_final = l;
                string s_nova = s;
                for(int w = 0;w<n && comeco;w++){
                    if(s[w] == aux[0]){}
                    else if(s[w] != aux[1]){
                        comeco--;
                        s_nova[w] = aux[0];
                    }
                    else if(apaga_comeco > 0){
                        apaga_comeco--;
                        comeco--;
                        s_nova[w] = aux[0];
                    }
                }
                for(int w = n-1; w >=0 && final; w--){
                    if(s[w] == aux[1]){}
                    else if(s[w] != aux[0]){
                        final--;
                        s_nova[w] = aux[1];
                    }
                    else if(apaga_final>0){
                        apaga_final--;
                        final--;
                        s_nova[w] = aux[1];
                    }
                }
                int tipo1 = 0, tipo2 = 0;
                for(int w=0;w<n;w++){
                    if(s_nova[w] == aux[1]){
                        tipo1 += tipo2;
                    }
                    else if(s_nova[w] == aux[0]){
                        tipo2++;
                    }
                }
                resposta = max(resposta, tipo1);
                if(apaga_comeco>0){
                    sobrou_x = false;
                    break;
                }
                if(apaga_final>0){
                    break;
                }
            }
        }
    }
    cout<<resposta;
    return;
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    cin>>n>>k;
    solve();
    return 0;
}