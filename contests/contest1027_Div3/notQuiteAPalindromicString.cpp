#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int t;
    cin>>t;
    int n, k;
    int x, y;
    char aux;
    int minimo, maximo;
    while(t--){
        cin>>n>>k;
        x = 0; y = 0;
        for(int i=0;i<n;i++){
            cin>>aux;
            if(aux == '0'){
                x++;
            }
            else{
                y++;
            }
        }
        minimo = (n/2) - min(x,y);
        maximo = (x/2) + (y/2);
        if(k<=maximo && k>=minimo && (k-minimo)%2 == 0){
            cout<<"YES";
        }
        else{
            cout<<"NO";
        }
        cout<<'\n';
    }

    return 0;
}