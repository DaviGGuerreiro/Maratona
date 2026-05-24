#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int t;
    cin>>t;
    int n, m, k;
    ll p;
    ll x;
    while(t--){
        cin>>n>>m>>k;
        int a = k%n;
        int b = k/n;
        if(a != 0){
            b++;
        }
        int l = 0;
        int r = m;
        int mid;
        while(r>=l){
            mid = l + ((r-l)/2);
            p = m/(mid+1);
            x = m%(mid+1);
            p = p*mid;
            p += x;
            if(p<b){
                l = mid + 1;
            }
            else{
                r = mid - 1;
            }
            
        }
        cout<<l<<'\n';
    }


    return 0;
}