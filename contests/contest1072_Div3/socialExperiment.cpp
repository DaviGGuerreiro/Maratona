#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int t;
    cin>>t;
    int n;
    while(t--){
        cin>>n;
        if(n<=3){
            cout<<n<<'\n';
        }
        else{
            if(n%2==0){
                cout<<0<<'\n';
            }
            else{
                cout<<1<<'\n';
            }
        }
    }

    return 0;
}