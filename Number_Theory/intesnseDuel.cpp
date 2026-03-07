#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int modulo = 7 + 1e9;
int main(){
ios::sync_with_stdio(false);cin.tie(0);
ll n;
cin>>n;
int x, y;
cin>>x>>y;
if(n%2 == 0){
    cout<<"Lleumas\n";
    cout<<y;
}
else{
    cout<<"Samuell\n";
    cout<<x;
}
return 0;
}