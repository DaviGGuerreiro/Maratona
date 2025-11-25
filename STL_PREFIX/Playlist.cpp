#include <bits/stdc++.h>
using namespace std;

int main(){

    ios::sync_with_stdio(false);cin.tie(0);
    int n;
    cin>>n;
    int som;
    map<int, int> mapa;
    int atual=0;
    int max=0;
    int corte=-1;
    for(int i=0; i<n; i++){
        cin>>som;
        if(mapa.find(som) != mapa.end() && (corte == -1 || corte<mapa[som])){
            corte = mapa[som];
            atual = i - corte;
            mapa[som] = i;
        }
        else{
            atual++;
            mapa[som] = i;
            if(max<atual){
                max = atual;
            }
        }
    }
    cout<<max;

    return 0;
}