#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int resposta = 0;

void solve(){
    int n; cin>>n;
    bool b = false;
    for(int i = 1; i<=n-1; i++){
        cout<<"? "<<i<<' '<<i+n<<'\n';
        cout.flush();
        cin>>resposta;
        if(resposta == -1){
            exit(0);
        }
        else if(resposta == 1){
            cout<<"! "<<i<<'\n';
            cout.flush();
            b= true;
            break;
        }
    }
    if(!b){
        cout<<"? "<<n<<' '<<1<<'\n';
        cout.flush();
        cin>>resposta;
        if(resposta == -1){
            exit(0);
        }
        else if(resposta == 1){
            cout<<"! "<<1<<'\n';
            cout.flush();
        }
        else if(resposta == 0){
            cout<<"? "<<n<<' '<<n+1<<'\n';
            cout.flush();
            cin>>resposta;
            if(resposta == -1){
                exit(0);
            }
            else if(resposta == 1){
                cout<<"! "<<n<<'\n';
                cout.flush();
            }
            else if(resposta== 0){
                cout<<"! "<<2*n<<'\n';
                cout.flush();
            }
        }
    }
    return;
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int t; cin>>t;
    while(t--){
        solve();
    }
    return 0;
}