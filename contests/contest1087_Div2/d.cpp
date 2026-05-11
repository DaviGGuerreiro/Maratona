#include<bits/stdc++.h>
using namespace std;
using ll = long long;
void solve(){
    vector<pair<int,char>> vec (3);
    char ultimo = ' ';
    string resposta;
    cin>>vec[0].first; vec[0].second = 'R';
    cin>>vec[1].first; vec[1].second = 'G';
    cin>>vec[2].first; vec[2].second = 'B';
    sort(vec.begin(), vec.end(), greater<pair<int, int>>());
    while(vec[1].first != vec[2].first){
        resposta.push_back(vec[0].second);
        ultimo = vec[0].second;
        vec[0].first--;
        if(vec[1].first > 0){
            resposta.push_back(vec[1].second);
            ultimo = vec[1].second;
            vec[1].first--;
        }
        else break;
    }
    if(vec[1].first == vec[2].first && vec[1].first == 0){
        if(ultimo != vec[0].second && vec[0].first > 0) resposta.push_back(vec[0].second);
        for(auto it : resposta){
            cout<<it;
        }
        cout<<'\n';
        return;
    }

    if(vec[0].first >= vec[1].first + vec[2].first){
        while(vec[1].first > 0){
            resposta.push_back(vec[0].second);
            vec[0].first--;
            resposta.push_back(vec[1].second);
            vec[1].first--;
        }
        while(vec[2].first > 0){
            resposta.push_back(vec[0].second);
            vec[0].first--;
            resposta.push_back(vec[2].second);
            vec[2].first--;
        }
        if(vec[0].first > 0) resposta.push_back(vec[0].second);
    }
    else{
        while(vec[0].first > vec[1].first){
            resposta.push_back(vec[0].second);
            vec[0].first--;
            resposta.push_back(vec[1].second);
            vec[1].first--;
            resposta.push_back(vec[0].second);
            vec[0].first--;
            resposta.push_back(vec[2].second);
            vec[2].first--;
            ultimo = vec[2].second;
        }
        int b = 0;
        while(vec[0].first > 0){
            if(b == 0){
                resposta.push_back(vec[0].second);
                vec[0].first--;
                resposta.push_back(vec[2].second);
                vec[2].first--;
                resposta.push_back(vec[1].second);
                vec[1].first--;
                ultimo = vec[1].second;
                b = 1;
            }
            else if(b == 1){
                resposta.push_back(vec[2].second);
                vec[2].first--;
                resposta.push_back(vec[1].second);
                vec[1].first--;
                resposta.push_back(vec[0].second);
                vec[0].first--;
                ultimo = vec[0].second;
                b = 2;
            }
            else{
                resposta.push_back(vec[1].second);
                vec[1].first--;
                resposta.push_back(vec[0].second);
                vec[0].first--;
                resposta.push_back(vec[2].second);
                vec[2].first--;
                ultimo = vec[2].second;
                b = 0;
            }
        }
        if(vec[1].first > 0){
            if(ultimo == vec[1].second){
                resposta.push_back(vec[2].second);
                resposta.push_back(vec[1].second);
            }
            else if(ultimo == vec[2].second || ultimo == vec[0].second){
                resposta.push_back(vec[1].second);
                resposta.push_back(vec[2].second);
            }
        }
    }

    for(auto it : resposta){
        cout<<it;
    }
    cout<<'\n';
    return;
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}