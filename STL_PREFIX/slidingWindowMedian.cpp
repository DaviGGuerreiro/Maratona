#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int n, k;
    int aux, mediana;
    cin>>n>>k;
    multiset<int> menor;
    multiset<int> maior;
    queue<int> fila;
    for(int i=0;i<n;i++){
        if(i == 0){
            cin>>mediana;
            fila.push(mediana);
        }
        else{
            cin>>aux;
            fila.push(aux);
            if(mediana >= aux){
                if(menor.size() == maior.size()){
                    menor.insert(aux);
                }
                else{
                    maior.insert(mediana);
                    menor.insert(aux);
                    auto it = menor.end();
                    --it;
                    mediana = *it;
                    menor.erase(it);
                }
            }
            else{
                if(maior.size() == menor.size()){
                    menor.insert(mediana);
                    maior.insert(aux);
                    auto it = maior.begin();
                    mediana = *it;
                    maior.erase(it);
                }
                else{
                    maior.insert(aux);
                }
            }
        }
        if(i >= k-1){
            if(i > k-1){
                if(fila.front() > mediana){
                    if(maior.size() == menor.size()){
                        maior.erase(maior.find(fila.front()));
                    }
                    else{
                        maior.erase(maior.find(fila.front()));
                        maior.insert(mediana);
                        auto it = menor.end();
                        --it;
                        mediana = *it;
                        menor.erase(it);
                    }
                }
                else if(fila.front() < mediana){
                    if(menor.size() == maior.size()){
                        menor.erase(menor.find(fila.front()));
                        menor.insert(mediana);
                        auto it = maior.begin();
                        mediana = *it;
                        maior.erase(it);
                    }
                    else{
                        menor.erase(menor.find(fila.front()));
                    }
                }
                else{
                    if(menor.size() == maior.size()){
                        auto it = maior.begin();
                        mediana = *it;
                        maior.erase(it);
                    }
                    else{
                        auto it = menor.end();
                        --it;
                        mediana = *it;
                        menor.erase(it);
                    }
                }
                fila.pop();
            }
            if(maior.size() != menor.size()){
                auto it = menor.end();
                --it;
                cout<<*it<<' ';
            }
            else{
               cout<<mediana<<' '; 
            }
        }
    }
}