#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    string s;
    cin>>s;
    int tamanho = s.size();
    vector<int> vec (26,0);
    stack<int> fila;
    stack<int> tamanhos;
    int t = 0;
    int aux;
    bool b = true;
    bool ativo = false;
    for(int i=0;i<tamanho;i++){
        aux = s[i] - 97;
        if(aux >= 0 && aux < 26){
            if(ativo){
                fila.push(aux);
                t++;
            }
            vec[aux]++;
            if(vec[aux] > 1){
                cout<<"No";
                b = false;
                break;
            }
        }
        else if(s[i] == 40){
            if(!ativo){
                ativo = true;
                t = 0;
            }
            else{
                tamanhos.push(t);
                t = 0;
            }
        }
        else if(s[i] == 41){
            for(int j=0;j<t;j++){
                vec[fila.top()]--;
                fila.pop();
            }
            if(!tamanhos.empty()){
                t = tamanhos.top();
                tamanhos.pop(); 
            }
            else{
                t = 0;
                ativo = false;
            }
        }
    }

    if(b){
        cout<<"Yes";
    }
    return 0;
}