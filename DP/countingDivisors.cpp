#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int maximo = 1 + 1e6;
vector<int> vec (maximo, 0);
int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int n;
    for(int i = 1; i<=1e6; i++){
        for(int j = i; j<=1e6; j = j+i){
            vec[j]++;
        }
    }
    cin>>n;
    int aux;
    while(n--){
        cin>>aux;
        cout<<vec[aux]<<'\n';
    }

    return 0;
}