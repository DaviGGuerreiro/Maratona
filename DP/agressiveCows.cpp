#include<bits/stdc++.h>
using namespace std;
using ll = long long;
vector<int> dp;
vector<int> dp2;
vector<int> vec;
int n, c;
bool solve(int m){
    dp = vector<int> (n,0);
    dp[0] = 1;
    long long aux = 0;
    for(int i=1;i<n;i++){
        aux += vec[i] - vec[i-1];
        dp[i] = dp[i-1];
        if(aux >= m){
            dp[i]++;
            aux = 0;
            if(dp[i] >= c){
                for(int j = 0; j<n; j++){
                    dp2[j] = dp[j];
                    if(dp2[j] == c){
                        return true;
                    }
                }
            }
        }
    }
    return false;
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        cin>>n>>c;
        dp2 = vector<int> (n,0);
        vec = vector<int> (n);
        for(int i=0;i<n;i++){
            cin>>vec[i];
        }
        sort(vec.begin(), vec.end());
        int l = 0;
        int r = 1e9;
        int mid;
        while(r>=l){
            mid = l + ((r-l)/2);
            bool b = solve(mid);
            if(b){
                l = mid + 1;
            }
            else{
                r = mid - 1;
            }
        }
        ll aux = 0;
        ll menor = 1e9;
        for(int i=1;i<n;i++){
            aux += vec[i] - vec[i-1];
            if(dp2[i] != dp2[i-1]){
                menor = min(menor, aux);
                aux = 0;
                if(dp2[i] == c){
                    break;
                }
            }
        } 
        cout<<menor<<'\n';
    }
    

    return 0;
}