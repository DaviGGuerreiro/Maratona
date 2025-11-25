#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int k, n;
    cin>>n>>k;
    int estranho = 0;
    int aux1, aux2;
    if(k%2==0){
        for(int i=0;i<k;i = i+2){
            cin>>aux1;
            cin>>aux2;
            estranho = estranho + aux2 - aux1;
        } 
    }
    else if(k == 1){
        cin>>aux1;
        estranho = 0;
    }
    else{
        vector<int> vec (k-1);
        vector<int> somap ((k-1)/2);
        vector<int> somai ((k-1)/2);
        int t1 = 0;
        int t2 = 0;
        int soma = 0;
        cin>>aux1;
        for(int i=0;i<k-1;i++){
            cin>>aux2;
            vec[i] = aux2 - aux1;
            aux1 = aux2;
            if(i%2==0){
                somai[t1] = vec[i];
                t1++;
            }
            else{
                somap[t2] = vec[i];
                soma = soma + somap[t2];
                t2++;
            }
        }
        int tamanho = (k-1)/2;
        estranho = soma;
        for(int i=0;i<tamanho;i++){
            soma = soma - somap[i] + somai[i];
            if(soma < estranho){
                estranho = soma;
            }
        }
    }
    cout<<estranho;

    return 0;
}