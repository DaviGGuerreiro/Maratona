#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int n, t;
    int aux;
    int resposta = 0;
    cin>>n>>t;
    vector<int> esq;
    map<int,int> mapae;
    vector<int> dir;
    map<int,int> mapad;
    for(int i=0;i<n;i++){
        cin>>aux;
        if(aux == 0){
            resposta++;
        }
        else if(aux>0){
            dir.push_back(aux);
            mapad[aux] = dir.size();
        }
        else{
            esq.push_back(-aux);
        }
    }
    int tamanho_e = esq.size();
    int tamanho_d = dir.size();
    sort(esq.begin(),esq.end());
    for(int i=0;i<tamanho_e;i++){
        mapae[esq[i]] = i+1;
    }
    aux = 0;
    int troco;
    int quantidade;
    int tamanho = tamanho_d + tamanho_e;
    for(int i=0;i<tamanho;i++){
        if(i < tamanho_e){
            troco = t - esq[tamanho_e-1-i];
            if(troco >= 0){
                quantidade = tamanho_e - i;
                troco = troco - esq[tamanho_e-1-i];
                if(troco > 0){
                    auto it = upper_bound(dir.begin(),dir.end(), troco);
                    if(it != dir.begin()){
                        --it;
                        quantidade = quantidade + mapad[*it];
                    }
                }
                if(aux < quantidade){
                    aux = quantidade;
                }
            }
        }
        else{
            troco = t - dir[i-tamanho_e];
            if(troco >= 0){
                quantidade = i - tamanho_e + 1;
                troco = troco - dir[i-tamanho_e];
                if(troco > 0){
                    auto it = upper_bound(esq.begin(),esq.end(), troco);
                    if(it != esq.begin()){
                        --it;
                        quantidade = quantidade + mapae[*it];
                    }
                }
                if(aux < quantidade){
                    aux = quantidade;
                }
            }
        }
    }
    cout<<aux+resposta<<'\n';
    return 0;
}