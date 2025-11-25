#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int x, num;
    long long aux;
    int neg, pos;
    int menorpositivo;
    cin>>x;
    while(x--){
        cin>>num;
        neg = 0; pos=0;
        menorpositivo = 1e9 + 5;
        long long t = 0;
        vector<long long> vec;
        for(int i = 0; i<num ; i++){
            cin>>aux;
            if(aux <= 0){
                neg++;
                vec.push_back(aux);
            }
            else{
                pos++;
                if(menorpositivo > aux){
                    menorpositivo = aux;
                }
            }
        }
        if(!vec.empty()){ 
            sort(vec.begin(), vec.end());
            t = -vec[0];
            for(int i = 0;i<neg-1;i++){
                if(t > vec[i+1]-vec[i]){
                    t = vec[i+1]-vec[i];
                }
            }
        }

        if(pos == 0){
            cout<<neg<<'\n';
        }
        else{
            if(t >= menorpositivo || neg == 1 || neg == 0){
                cout<<neg+1<<'\n';
            }
            else{
                cout<<neg<<'\n';
            }
        }
    }
    return 0;
}