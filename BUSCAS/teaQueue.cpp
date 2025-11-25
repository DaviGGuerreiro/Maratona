#include <bits/stdc++.h>
using namespace std;
void search(int a,int b, vector<int>& vec){
    int aux = 0;
    while(a < b){
        int mid = a + (b-a)/2;
        if(vec[mid] == 0){
            aux = mid;
            b = mid-1;
        }
        else if(vec[mid] == 1){
            a = mid+1;
        }
    }
    if(aux != 0){
        vec[aux] = 1;
    }
    cout<<aux<<' ';
    return;
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int t, n;
    int a, b;
    cin>>t;
    while(t--){
        cin>>n;
        vector<int> vec (5001, 0);
        while(n--){
            cin>>a>>b;
            search(a,b,vec);
        }
        cout<<'\n';
    }
    return 0;
}