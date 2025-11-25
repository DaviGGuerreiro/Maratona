#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int n, resposta = 0;
    cin>>n;
    vector<pair<int, int>> vec (n);
    vector<int> v;
    for(int i=0;i<n;i++){
        cin>>vec[i].first;
        cin>>vec[i].second;
        v.push_back(vec[i].first);
        v.push_back(vec[i].second);
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(),v.end()), v.end());
    int tamanho = v.size();
    vector<int> contagem (tamanho, 0);
    vector<int> prefix (tamanho + 1);
    prefix[0] = 0;
    for(auto it: vec){
        int l = it.first;
        int r = it.second;
        int pos1 = lower_bound(v.begin(),v.end(), l) - v.begin();
        int pos2 = lower_bound(v.begin(),v.end(), r) - v.begin();
        contagem[pos1]++;
        contagem[pos2]--;
    }
    for(int i=1;i<=tamanho;i++){
        prefix[i] = prefix[i-1] + contagem[i-1];
        if(prefix[i] > resposta){
            resposta = prefix[i];
        }
    }
    cout<<resposta;

    return 0;
}