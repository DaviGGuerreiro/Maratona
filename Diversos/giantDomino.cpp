#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int t;
    int n;
    cin>>t;
    int primeiro, ultimo;
    while(t--){
        cin>>n;
        vector<int> vec (n-2);
        cin>>primeiro;
        for(int i=0;i<n-2;i++){
            cin>>vec[i];
        }
        sort(vec.begin(),vec.end());
        cin>>ultimo;
        int x = primeiro;
        int quantidade = 2;
        bool b = true;
        while(2*x < ultimo){
            auto it = upper_bound(vec.begin(),vec.end(),2*x);
            if(it == vec.begin()){
                b = false;
                break;
            }
            else{
                it--;
                if(*it == x){
                    b = false;
                    break;
                }
                else{
                    quantidade++;
                    x = *it;
                }
            }
        }
        if(b){
            cout<<quantidade<<'\n';
        }
        else{
            cout<<-1<<'\n';
        }
    }
    return 0;
}