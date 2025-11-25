#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int t, aux;
    bool resposta;
    while(true){
        cin>>t;
        if(t == 0){
            break;
        }
        else{
            while(true){
                cin>>aux;
                if(aux==0){
                    break;
                }
                else{
                    stack<int> pilha;
                    vector<int> vec (t+1,0);
                    vec[aux]++;
                    resposta = true;

                    pilha.push(-1);
                    pilha.push(aux-1);
                    for(int i=1;i<t;i++){
                        cin>>aux;
                        if(aux > pilha.top()){
                            if(vec[aux-1] == 0){
                                pilha.push(aux-1);
                            }
                            vec[aux]++;
                        }
                        else if(aux == pilha.top()){
                            pilha.pop();
                            if(vec[aux-1] == 0){
                                pilha.push(aux-1);
                            }
                            vec[aux]++;
                        }
                        else{
                            resposta = false;
                        }
                    }
                    if(resposta){
                        cout<<"Yes\n";
                    }
                    else{
                        cout<<"No\n";
                    }
                }
            }
            cout<<'\n';
        }
    }
    return 0;
}