#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void bin(){
    int n,k; cin>>n>>k;
    vector<int> vec;
    int l = 0; int r = n-1;
    int mid;
    while(r >= l){
        mid = l + ((r-l)/2);
        if(vec[mid] > k){
            r = mid - 1;
        }
        else if(vec[mid] <= k){
            l = mid + 1;
        }
    }
}

double f(double x) { // func unimodal
    return -(x * x) + 4 * x;
}
double ternarySearchDouble(double l, double r) {
    for (int i = 0; i < 200; i++) {
        double m1 = l + (r - l) / 3.0;
        double m2 = r - (r - l) / 3.0;
        if (f(m1) < f(m2)) {
            l = m1;
        } else {
            r = m2;
        }
    }
    return f(l);
}
ll f2(ll x) {
    return -(x * x) + 4 * x;
}
ll ternarySearchInt(ll l, ll r) {
    while (r - l > 2) {
        ll m1 = l + (r - l) / 3;
        ll m2 = r - (r - l) / 3;
        if (f2(m1) < f2(m2)) {
            l = m1;
        } else {
            r = m2;
        }
    }
    ll ans = f2(l);
    for (ll i = l + 1; i <= r; i++) {
        ans = max(ans, f2(i));
    }
    return ans;
}
