#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int n;
ll x1, x2;
bool func(pair<ll,ll> a, pair<ll,ll> b){
    if(a.first < b.first){
        return true;
    }
    else if(a.first == b.first){
        if(a.second < b.second){
            return true;
        }
        else{
            return false;
        }
    }
    else{
        return false;
    }
}
int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    cin>>n;
    cin>>x1>>x2;
    ll a, b;
    ll y1, y2;
    multiset<ll> conj;
    vector<pair<ll,ll>> vec;
    for(int i=0;i<n;i++){
        cin>>a>>b;
        y1 = a*x1 + b;
        y2 = a*x2 + b;
        vec.push_back({y1,y2});
    }
    sort(vec.begin(),vec.end(), func);
    bool r = true;
    for(int i = 1;i<n;i++){
        if(vec[i].second < vec[i-1].second){
            r = false;
            break;
        }
    }
    if(r){
        cout<<"NO";
    }
    else{
        cout<<"YES";
    }
    return 0;
}