#include <bits/stdc++.h>
using namespace std;
const long double eps = 1e-9;

int main(){

    ios::sync_with_stdio(false);cin.tie(0);
    long double a, b, c;
    cin>>a>>b>>c;

    long double t = (a*c + b*c + b*a);
    long double y = a*b*c;

    if(y<=t + eps){
        cout<<"No";
    }
    else{
        cout<<"Yes";
    }

    return 0;
}
