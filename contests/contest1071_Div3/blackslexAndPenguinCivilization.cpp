#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int t;
    cin>>t;
    int n;
    while(t--){
        cin>>n;
        int x = (1<<n) - 1;
        cout<<x<<" ";
        int y;
        while(x != 0){
            x ^= (1<<(__builtin_popcount(x)-1));
            y = x;
            
        }
        cout<<'\n';
    }
    return 0;
}