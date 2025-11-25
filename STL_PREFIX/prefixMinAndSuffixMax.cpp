#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int t, n;
    cin>>t;
    while(t--){
        cin>>n;
        vector<int> menor (n);
        vector<int> maior (n);
        vector<int> vec (n);
        int min = 1e9;
        int max = -1;
        int aux;
        for(int i=0;i<n;i++){
            cin>>aux;
            vec[i] = aux;
            if(min > aux){
                min = aux;
            }
            menor[i] = min;
        }
        for(int i=0;i<n;i++){
            if(max < vec[n-1-i]){
                max = vec[n-1-i];
            }
            maior[n-1-i] = max;
        }
        for(int i=0;i<n;i++){
            if(i == 0 || i == n-1){
                cout<<1;
            }
            else{
                if(vec[i] == maior[i] || vec[i] == menor[i]){
                    cout<<1;
                }
                else{
                    cout<<0;
                }
            }
        }
        cout<<'\n';
    }

    return 0;
}