#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int n;
    cin>>n;
    vector<pair<int,int>> vec (n);
    vector<int> v;
    int s, f;
    cin>>s>>f;
    for(int i=0;i<n;i++){
        cin>>vec[i].first;
        cin>>vec[i].second;
        v.push_back(vec[i].first);
        v.push_back(vec[i].second);
    }
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()), v.end());
    int tamanho = (int) v.size();
    vector<int> count (tamanho,0);
    vector<int> psum (tamanho+1, 0);
    psum[0] = 0;
    for(auto it: vec){
        int pos1 = lower_bound(v.begin(),v.end(),it.first) - v.begin();
        int pos2 = lower_bound(v.begin(),v.end(),it.second) - v.begin();
        count[pos1]++;
        count[pos2]--;
    }
    vector<int> resposta (n,0);
    for(int i=1; i<=tamanho;i++){
        psum[i] = psum[i-1] + count[i-1];
    }
    int aux1;
    bool fl = true;
    for(int i=0;i<tamanho;i++){
        if(v[i]>= s && v[i] <= f){
            if(fl){
                resposta[psum[i]] = v[i] - s;
                fl = false;
            }
            if(i < tamanho - 1){
                aux1 = min(f,v[i+1]);
            }
            else{
                aux1 = f;
            }
            resposta[psum[i+1]] += aux1 - v[i];
        }
        else if(v[i] > f && fl == true){
            resposta[psum[i]] = f - s;
            fl = false;
        }
    }

    int x = 0;
    if(fl == false){
        for(int i=0;i<n;i++){
            x += resposta[i];
            cout<<x<<" ";
        }
    }
    else{
        for(int i=0;i<n;i++){
            cout<<f-s<<" ";
        }
    }
    

    return 0;
}