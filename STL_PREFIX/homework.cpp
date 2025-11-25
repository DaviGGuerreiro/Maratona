#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int t;
    cin>>t;
    string meio, b;
    string aux;
    int tam_a,tam_b;
    while(t--){
        int r=0;
        string final;
        cin>>tam_a;
        cin>>meio;
        cin>>tam_b;
        cin>>b;
        cin>>aux;
        for(int i=0;i<tam_b;i++){
            if(aux[i]== 'V'){
                r++;
                final.insert(final.begin(), b[i]);
            }
            else{
                final.push_back(b[i]);
            }
        }
        final.insert(r, meio);
        cout<<final<<'\n';
    }
    return 0;
}