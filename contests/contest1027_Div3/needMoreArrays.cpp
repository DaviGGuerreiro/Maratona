#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int t;
    cin>>t;
    int n;
    int x , aux;
    int r;
    while(t--){
        cin>>n;
        r = 0; x = -2;
        for(int i=0;i<n;i++){
            cin>>aux;
            if(x + 1 < aux){
                r++;
                x = aux;
            }
        }
        cout<<r<<'\n';
    }

    return 0;
}