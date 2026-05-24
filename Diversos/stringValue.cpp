#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int n;
    string s;
    cin>>n;
    cin>>s;
    int maximo = 1;
    int aux = 1;
    char b = s[0];
    for(int i=1;i<(int)s.size();i++){
        if(s[i] == b){
            aux++;
        }
        else{
            aux = 1;
        }
        maximo = max(maximo, aux);
        b = s[i];
    }
    cout<<maximo;
    return 0;
}