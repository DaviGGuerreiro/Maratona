#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int t, n, q;
    cin>>t;
    while(t--){
        cin>>n>>q;
        vector<int> vec (n);
        for(int i=0;i<n;i++){
            cin>>vec[i];
        }
        sort(vec.begin(), vec.end(), greater<int>());
        for(int i=1;i<n;i++){
            vec[i] = vec[i] + vec[i-1];
        }
        int x;
        while(q--){
            cin>>x;
            auto it = lower_bound(vec.begin(),vec.end(), x);
            if(it == vec.end()){
                cout<<-1<<'\n';
            }
            else{
                cout<<it-vec.begin()+1<<'\n';
            }
        }
    }

    return 0;
}