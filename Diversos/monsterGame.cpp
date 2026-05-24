#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int t;
    cin>>t;
    int n;
    int m;
    ll resp;
    while(t--){
        cin>>n;
        vector<int> a (n);
        vector<int> b (n);
        for(int i=0;i<n; i++){
            cin>>a[i];
        }
        sort(a.begin(),a.end());
        for(int i=0;i<n; i++){
            cin>>b[i];
        }
        for(int i=1;i<n;i++){
            b[i] = b[i] + b[i-1];
        }
        resp = 0;
        for(int i=0;i<n;i++){
            if(b[i]<=n){
                m = a[n - b[i]];
                resp = max(resp, 1LL * (i+1) * m);
            }
            else{
                break;
            }
        }
        cout<<resp<<'\n';
    }
    return 0;
}