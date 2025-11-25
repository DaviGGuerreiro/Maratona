#include<bits/stdc++.h>
using namespace std;
using ll = long long;

bool ord(const string& a, const string& b){
    return a.size() < b.size();
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int n;
    cin>>n;
    vector<string> vec;
    string aux;
    for(int i=0;i<n;i++){
        cin>>aux;
        vec.push_back(aux);
    }
    sort(vec.begin(), vec.end(), ord);
    if(n == 1){
        cout<<vec[0]<<'\n';
    }
    else if(vec[0].size() == vec[1].size()){
        cout<<"Not found"<<'\n';
    }
    else{
        bool b = true;
        int comp;
        int tamanho = vec[0].size();
        string s = vec[0];
        for(int i=1;i<n;i++){
            comp = vec[i].compare(vec[i].size()-tamanho, tamanho, s);
            if(comp != 0){
                b = false;
                break;
            }
        }
        if(b){
            cout<<vec[0]<<'\n';
        }
        else{
            cout<<"Not found"<<'\n';
        }
    }

    return 0;
}