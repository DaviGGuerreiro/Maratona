#include<bits/stdc++.h>
using namespace std;

bool func(string& a, string& b){
    int l = 0;
    int r = 0;
    while(true){
        if(a[l] > b[r]){
            return false;
        }
        else if(a[l] < b[r]){
            return true;
        }
        r++;
        l++;
        if(l == a.size() && r == b.size()){
            return false;
        }
        else if(l == a.size()){
            l = 0;
        }
        else if(r == b.size()){
            r = 0;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int n;
    cin>>n;
    vector<string> vec (n);
    for(int i=0;i<n;i++){
        cin>>vec[i];
    }
    sort(vec.begin(),vec.end(), func);
    for(int i=0;i<n;i++){
        cout<<vec[i];
    }
    return 0;
}