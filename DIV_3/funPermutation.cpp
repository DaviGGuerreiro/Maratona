#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int t;
    cin>>t;
    int n;
    int elemento;
    while(t--){
        cin>>n;
        int aux = n + 1;
        int aux2;
        while(n--){
            cin>>elemento;
            aux2 = aux - elemento;
            cout<<aux2<<' ';
        }
        cout<<'\n';
    }

    return 0;
}
