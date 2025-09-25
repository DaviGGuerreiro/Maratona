#include <bits/stdc++.h>
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
    int m, aux;
    cin>>m;
    while(m--){
        cin>>aux;
        auto query = upper_bound(vec.begin(),vec.end(),aux);
        if(query == vec.end()){
            cout<<n<<'\n';
        }
        else if(query == vec.begin()){
            if(vec[0] > aux){
                cout<<"0\n";
            }
            else{
                cout<<"1\n";
            }
        }
        else{
            --query;
            cout<<((query-vec.begin())+1)<<'\n';
        }
    }
    return 0;
}