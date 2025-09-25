#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int t;
    cin>>t;
    int a,b,c,m;
    int zero;
    int max;
    while(t--){
        zero=0;
        max = -1;
        cin>>a>>b>>c;
        if(a == 0){
            zero++;
        }if(b==0){
            zero++;
        }if(c==0){
            zero++;
        }
        if(a>b){
            if(a>c){
                max = a;
            }else{
                max = c;
            }
        } else{
            if(b>c){
                max = b;
            }else{
                max = c;
            }
        }
        cin>>m;
        if(m<=a+b+c-3+zero){
            max = 2*max - (a+b+c);
            if(max > 0){
                if(m>=max-1){
                    cout<<"YES\n";
                } else{
                    cout<<"NO\n";
                }
            }
            else{
                cout<<"YES\n";
            }
        }
        else{
            cout<<"NO\n";
        }
    }
    return 0;
}