#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pii pair<int,int>
#define FORi(n) for(int i=0;i<n;i++)
#define FORj(n) for(int j=0;j<n;j++)
#define all(a) (a).begin(),(a).end()
#define printn(v,n) for(int i=0;i<n;i++) cout << v[i] << (i == n-1 ? "\n" : " ")

void solve() {
    int a,b,c,d; cin>>a>>b>>c>>d;

    if(b == 1 && c == 2 && d == 3) { cout << "1\n"; }
    else if(a == 1 && c == 1 && d == 2) { cout << "2\n"; }
    else if(a == 2 && b == 1 && d == 1) { cout << "3\n"; }
    else if(a == 3 && b == 2 && c == 1) { cout << "4\n"; }
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);

    solve();
}