#include<bits/stdc++.h>
using namespace std;
using ll = long long;

vector<int> vec;
int n;
ll k;

bool func(ll mid){
    ll quantidade = 0;
    for(int i = 0;i<n;i++){
        auto it = upper_bound(vec.begin(),vec.end(), mid - vec[i]) - vec.begin();
        quantidade += (it);
        if(quantidade >= k){
            return true;
        }
    }
    return false;
}

void solve(){
    cin>>n>>k;
    vec = vector<int> (n);
    for(int i=0;i<n;i++){
        cin>>vec[i];
    }
    sort(vec.begin(),vec.end());
    ll l = 2*vec[0], r = 2*vec[n-1];
    ll mid;
    while(r>=l){
        mid = l + ((r-l)/2);
        if(func(mid)){
            r = mid - 1;
        }
        else{
            l = mid + 1;
        }
    }
    cout<<l<<'\n';
}



int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}