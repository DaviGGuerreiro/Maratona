#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int t, aux;
    cin>>t;
    while(t--){
        cin>>aux;
        if(aux%2 == 1){
            cout<<"Alice\n";
        }
        else{
            if(aux%4 == 0){
                cout<<"Bob\n";
            }
            else{
                cout<<"Alice\n";
            }
        }
    }
    return 0;
}