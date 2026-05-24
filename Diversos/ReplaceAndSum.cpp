#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int t;
    cin>>t;
    int n, q;
    while(t--){
        cin>>n>>q;
        vector<int> a (n);
        vector<int> b (n);
        for(int i=0; i<n;i++){
            cin>>a[i];
        }
        for(int i=0; i<n;i++){
            cin>>b[i];
        }
        for(int i=0;i<n;i++){
            if(a[i] < b[i]){
                a[i] = b[i];
            }
        }
        for(int i=n-1;i>=0;i--){
            if(i != 0 && a[i] > a[i-1]){
                a[i-1] = a[i];
            }
        }
        vector<int> psum (n+1);
        psum[0] = 0;
        for(int i=1;i<=n;i++){
            psum[i] = psum[i-1] + a[i-1];
        }
        int l, r;
        for(int i=0; i<q;i++){
            cin>>l>>r;
            cout<<psum[r] - psum[l-1]<<" ";
        }
        cout<<'\n';
    }
    return 0;
}