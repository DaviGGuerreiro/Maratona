#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int t;
    cin>>t;
    int n;
    while(t--){
        cin>>n;
        vector<int> vec (n);
        int l = -1;
        int r = -1;
        for(int i=0;i<n;i++){
            cin>>vec[i];
            if(l == -1 && vec[i] != n-i){
                l = i;
            }
            if(r == -1 && vec[i] == n-l){
                r = i;
            }
        }
        for(int i = 0;i<n;i++){
            if(i>=l && i<= r){
                cout<<vec[r + (l-i)]<<" ";
            }
            else{
                cout<<vec[i]<<" ";
            }
        }
        cout<<'\n';
    }
    return 0;
}