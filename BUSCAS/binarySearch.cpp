#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int n, q;
    cin>>n>>q;
    vector<int> vec;
    int aux;
    while(n--){
        cin>>aux;
        vec.push_back(aux);
    }
    while(q--){
        cin>>aux;
        auto query = lower_bound(vec.begin(), vec.end(), aux);
        if(query == vec.end()){
            cout<<"-1\n";
        }
        else if(*query == aux){
            cout<<query-vec.begin()<<'\n';
        }
        else{
            cout<<"-1\n";
        }
    }

    return 0;
}