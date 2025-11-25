#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int t, n;
    cin>>t;
    while(t--){
        cin>>n;
        string s;
        cin>>s;
        string r = {};
        r += s[0];
        int t = 0;
        for(int i = 1;i<n;i++){
            if(r[i-1] > s[i]){
                r += s[i];
                t++;
            }
            else if(r[i-1] == s[i]){
                if(t == 0){
                    break;
                }
                else{
                    r += s[i];
                }
            }
            else{
                break;
            }
        }
        int tamanho = r.size();
        for(int i=0;i<tamanho;i++){
            r += r[tamanho-1-i];
        }
        cout<<r<<'\n';
    }
    return 0;
}