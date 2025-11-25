#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    string T;
    string U;
    bool r = false;
    size_t aux;
    cin>>T;
    cin>>U;
    for(size_t i=0; i < T.size() - U.size() + 1; i++){
        aux = 0;
        for(size_t j=0; j< U.size(); j++){
            if(U[j] == T[j+i]){
                aux++;
            }
            else if(T[j+i] == '?'){
                aux++;
            }
        }
        if(aux == U.size()){
            r = true;
        }
    }
    if(r){
        cout<<"Yes"<<'\n';
    }
    else{
        cout<<"No"<<'\n';
    }

    return 0;
}