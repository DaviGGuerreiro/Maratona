#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int n,m,k;
    int resposta=0;
    cin>>n>>m>>k;
    vector<int> p (n);
    vector<int> casa (m);
    for(int i=0;i<n;i++){
        cin>>p[i];
    }
    sort(p.begin(), p.end());
    for(int i=0;i<m;i++){
        cin>>casa[i];
    }
    sort(casa.begin(),casa.end());
    int l = 0;
    int r = 0;
    while(r < n && l < m){
        if(p[r] < (casa[l] - k) || p[r] > (casa[l] + k)){
            if(p[r] > casa[l]){
                l++;
            }
            else{
                r++; 
            }
        }
        else{
            resposta++;
            r++;
            l++;
        }
    }
    
    cout<<resposta;
    
    return 0;
}
