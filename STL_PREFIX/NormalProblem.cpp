#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int t;
    int tamanho;
    cin>>t;
    string str;
    char aux;
    while(t--){
        cin>>str;
        for(int i=0;i<str.size();i++){
            if(str[i] == 'p'){
                str[i] = 'q';
            }
            else if(str[i] == 'q'){
                str[i] = 'p';
            }
        }
        reverse(str.begin(), str.end());
        cout<<str<<'\n';
    }
    return 0;
}
