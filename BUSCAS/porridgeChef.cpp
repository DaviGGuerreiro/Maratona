#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int n, q;
    cin>>n>>q;
    vector<pair<int,int>> vec (n);
    vector<int> v;
    map<int,int> mapa;
    for(int i=0;i<n;i++){
        cin>>vec[i].first;
        cin>>vec[i].second;
        v.push_back(vec[i].first);
        v.push_back(vec[i].second);
        mapa[vec[i].second]++;
    }
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()), v.end());
    int tamanho = v.size();
    //for(int i=0;i<tamanho;i++){
     //   cout<<v[i]<<' ';
    //}
    vector<int> count (tamanho, 0);
    for(auto x :vec){
        int pos1 = lower_bound(v.begin(),v.end(), x.first) - v.begin();
        int pos2 = lower_bound(v.begin(), v.end(), x.second)- v.begin();
        count[pos1]++;
        count[pos2]--;
    }
    //cout<<'\n';
    vector<int> pre(tamanho+1);
    pre[0] = 0;
    for(int i=1;i<=tamanho;i++){
        pre[i] = pre[i-1] + count[i-1];
        //cout<<pre[i]<<' ';
    }
    //cout<<'\n';
    int query;
    int pos3;
    for(int i=0;i<q;i++){
        cin>>query;
        pos3 = (upper_bound(v.begin(),v.end(), query) - v.begin());
        cout<<pre[pos3] + mapa[query]<<'\n';
    }

    return 0;
}