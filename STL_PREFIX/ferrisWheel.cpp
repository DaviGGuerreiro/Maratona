#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int n, x;
    cin>>n>>x;
    vector<int> vec (n);
    for(int i=0;i<n;i++){
        cin>>vec[i];
    }
    sort(vec.begin(), vec.end());
    int l = 0, r = n-1;
    int resposta = 0;
    while(r >= l){
        if(r == l){
            resposta++;
            l = r +1;
        }
        else if(vec[l] + vec[r] <= x){
            resposta++;
            l++;
            r--;
        }
        else{
            resposta++;
            r--;
        }
    }
    cout<<resposta;

    return 0;
}