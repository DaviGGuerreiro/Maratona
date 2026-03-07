#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int minimo;
int n, k;
vector<int> vec;

bool binS(int mid){
    int j = 0;
    ll aux = 0;
    for(int i=1;i<=k;i++){
        aux = vec[j];
        aux = aux + 2*mid;
        int it = upper_bound(vec.begin(),vec.end(),aux) - vec.begin();
        if(it == n){
            minimo = mid;
            return true;
        }
        j = it;
    }
    return false;
}


int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    freopen("angry.in", "r", stdin);
    freopen("angry.out", "w", stdout);
    minimo = 1e9;
    cin>>n>>k;
    vec = vector<int> (n);
    for(int i=0;i<n;i++){
        cin>>vec[i];
    }
    sort(vec.begin(),vec.end());
    int r = 1e9;
    int l = 0;
    while(r>=l){
        int mid = l + ((r-l)/2);
        if(binS(mid)){
            r = mid-1;
        }
        else{
            l = mid+1;
        }
    }
    cout<<minimo;
    return 0;
}