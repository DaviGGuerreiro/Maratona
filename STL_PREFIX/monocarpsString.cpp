#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int t;
    cin>>t;
    int n;
    string s;
    while(t--){
        cin>>n;
        cin>>s;
        int a=0;
        int b=0;
        for(int i=0;i<(int)s.size();i++){
            if(s[i] == 'a'){
                a++;
            }
            else{
                b++;
            }
        }
        int r = a - b;
        int x = 0;
        int resposta = 1e9;
        map<int,int> mapa;
        mapa[0] = 0;
        set<int> conj;
        conj.insert(0);
        for(int i=0;i<(int)s.size();i++){
            if(s[i] == 'a'){
                x++;
            }
            else{
                x--;
            }
            mapa[x] = i+1;

            if(conj.find(x) == conj.end()){
                conj.insert(x);
            }

            if(conj.find(x-r) != conj.end()){
                if(!(x-r == 0 && mapa[x-r] == 0 && i+1 == (int)s.size())){
                    resposta = min(resposta, i+1 - mapa[x-r]);
                }
            }
        }
        if(resposta == 1e9){
            cout<<"-1"<<'\n';
        }
        else{
            cout<<resposta<<'\n';
        }
    }
    return 0;
}