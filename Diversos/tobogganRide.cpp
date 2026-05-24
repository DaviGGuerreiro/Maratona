#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll l, n, t;
vector<int> pos;

bool check(double valor){
    double velocidade = 0;
    double tempo = 0;
    double t_aux;
    for(int i=0;i<n;i++){
        velocidade += valor;
        if(i != n-1){
            if((velocidade*velocidade)/2.0 >= pos[i+1] - pos[i]){
                t_aux = velocidade - sqrt((velocidade*velocidade) - 2*(pos[i+1]-pos[i]));
                velocidade -= t_aux;
                tempo += t_aux;
            }
            else{
                return false;
            }
        }
        else{
            if((velocidade*velocidade)/2.0 >= l - pos[i]){
                t_aux = velocidade - sqrt((velocidade*velocidade) - 2*(l - pos[i]));
                velocidade -= t_aux;
                tempo += t_aux;
            }
            else{
                return false;
            }
        }
        if(tempo > t){
            return false;
        }
    }
    return true;
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    cin>>l>>n>>t;
    pos = vector<int> (n);
    for(int i=0;i<n;i++){
        cin>>pos[i];
        pos[i] = pos[i];
    }
    double l = 0;
    double r = 1e9;
    double mid;
    while(r-l > 1e-5){
        mid = (r+l)/2.0;
        if(check(mid)){
            r = mid;
        }
        else{
            l = mid;
        }
    }
    cout<<fixed<<setprecision(4)<<l;
    
    return 0;
}