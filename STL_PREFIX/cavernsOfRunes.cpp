#include<bits/stdc++.h>
using namespace std;
long long euclides(long long a, long long b){
    while(a!=0 && b!=0){
        if(a>b){
            a = a%b;
        }
        else{
           b = b%a;
        }
    }
    if(a == 0){
        return b;
    }
    else{
        return a;
    }
}
long long mmc(long long a, long b){
    long long c;
    c = a/euclides(a,b);
    c = c*b;
    return c;
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int n, a, aux;
    cin>>n;
    vector<int> cav;
    int x=0;
    for(int i=0;i<n;i++){
        cin>>a;
        vector<int> util (43, 0);
        for(int j=0;j<a;j++){
            cin>>aux;
            util[aux]++;
        }
        aux = 0;
        vector<int> vec;
        for(int j=1;j<43;j++){
            if(util[j] > 1){
                if(aux == 0){
                    aux = j;
                }
                else{
                    aux = euclides(aux, j);
                }
            }
            else if(util[j] == 1){
                vec.push_back(j);
            }
        }
        int tamanho = vec.size();
        vector<int> pre (tamanho);
        vector<int> pos (tamanho);
        for(int j=0;j<tamanho;j++){
            if(j == 0){
                pre[j] = vec[j];
                pos[tamanho-1-j] = vec[tamanho-1-j];
            }
            else{
                pre[j] = euclides(pre[j-1], vec[j]);
                pos[tamanho -1 -j] = euclides(pos[tamanho - j], vec[tamanho-j-1]);
            }
        }
        int maior = -1;
        int aux2;
        if(tamanho != 1){
            for(int k=0;k<tamanho;k++){
                if(k == 0){
                    aux2 = pos[k+1]; 
                }
                else if(k == tamanho-1){
                    aux2 = pre[k-1];
                }
                else{
                aux2 = euclides(pre[k-1], pos[k+1]); 
                }
                if(aux != 0){
                    aux2 = euclides(aux2, aux); 
                }
                if(maior < aux2){
                    maior = aux2;
                }
            }
        }
        else{
            maior = vec[0];
            if(aux != 0){
                maior = aux;
            }
        }
        if(tamanho == 0){
            maior = aux;
        }
        cav.push_back(maior);
        if(maior > x){
            x = maior;
        }
    }
    long long resposta=1;
    bool b = true;
    for(int p : cav){
        if(b && p == x){
            b = false;
        }
        else{
            resposta = mmc(resposta, p);
        }
    }
    cout<<resposta;
    return 0;
}