#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int n;
    cin>>n;
    vector<pair<int,int>> vec (n);
    vector<int> v;
    for(int i=0;i<n;i++){
        cin>>vec[i].first;
        cin>>vec[i].second;
        v.push_back(vec[i].first);
        v.push_back(vec[i].second);
    }
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()), v.end());
    int tamanho = v.size();
    vector<int> contagem (tamanho, 0);
    vector<int> prefix (tamanho+1,0);
    bool b=true;
    for(auto it :vec){
        int pos1 = lower_bound(v.begin(), v.end(), it.first) - v.begin();
        int pos2 = lower_bound(v.begin(),v.end(),it.second) - v.begin();
        if(contagem[pos1] == -2 || contagem[pos2] == 2){
            b = false;
            break;
        }
        if(contagem[pos1] == -1){
            contagem[pos1] = 1e9;
        }
        else{
          contagem[pos1]++;  
        }
        if(contagem[pos2] == 1){
            contagem[pos2] = 1e9;
        }
        else{
            contagem[pos2]--; 
        }
    }
    prefix[0] = 0;
    if(b){
        for(int i=1;i<=tamanho;i++){
            if(contagem[i-1] == 1e9){
                if(prefix[i-1]>1){
                    b = false;
                    break;
                }
                else{
                    contagem[i-1] = 0;
                }
            }
            prefix[i] = prefix[i-1] + contagem[i-1];
            if(prefix[i]>2){
                b = false;
                break;
            }
        }
    }
    if(b){
        cout<<"YES";
    }
    else{
        cout<<"NO";
    }

    return 0;
}