#include<bits/stdc++.h>
using namespace std;
int n, m, k;
vector<int> obj;
bool solve(int mid, vector<int>& caixas){
    int c = 0;
    for(int l = n - mid;l<n;l++){
        if(caixas[c] >= obj[l]){
            caixas[c] -= obj[l];
        }
        else{
            c++;
            if(c == m){
                return false;
            }
            else{
                caixas[c] -= obj[l];
            }
        }
    }
    return true;
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    cin>>n>>m>>k;
    obj = vector<int> (n);
    for(int i=0;i<n;i++){
        cin>>obj[i];
    }
    int l = 0;
    int r = n;
    while(r>=l){
        int mid = l + ((r-l)/2);
        vector<int> caixas (m, k);
        bool b = solve(mid, caixas);
        if(b){
            l = mid + 1;
        }
        else{
            r = mid - 1;
        }
    }
    cout<<r;

    return 0;
}