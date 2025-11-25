#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int n;
    cin>>n;
    vector<int> vec (n);
    for(int i=0;i<n;i++){
        cin>>vec[i];
    }
    sort(vec.begin(),vec.end());
    int q;
    int aux;
    cin>>q;
    while(q--){
        cin>>aux;
        auto it = upper_bound(vec.begin(),vec.end(), aux);
        if(it == vec.begin()){
            cout<<0<<'\n';
        }
        else{
            --it;
            cout<<it-vec.begin()+1<<'\n';
        }
    }

    return 0;
}