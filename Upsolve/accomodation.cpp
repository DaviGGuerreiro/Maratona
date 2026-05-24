#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int n;

struct func{
    bool operator()(const pair<int, int>& p1, const pair<int, int>& p2) const{
        int diff1, diff2, cnt1, cnt2;
        if(p1.first == 1 || p1.second == n){ diff1 = p1.second - p1.first + 1; cnt1 = 1;}
        else{ diff1 = ((p1.second - p1.first + 2)/2); cnt1 = ((p1.second - p1.first + 1) % 2 == 0) ? 1 : 2;}
        if(p2.first == 1 || p2.second == n){ diff2 = p2.second - p2.first + 1; cnt2 = 1;}
        else{ diff2 = ((p2.second - p2.first + 2)/2); cnt2 = ((p2.second - p2.first + 1) % 2 == 0) ? 1 : 2;}
        if(diff1 != diff2) return diff1 > diff2;
        else if(cnt1 != cnt2) return cnt1 < cnt2;
        return p1.first > p2.first;
    }
};

void solve(){
    int q, tipo, paciente, k; cin>>n>>q;
    int left, right;
    pair<int,int> aux, xua;
    set<pair<int,int>> intervalos;
    set<pair<int,int>, func> intervalos_prioridade;
    vector<int> lista (q+1, 0);
    auto inserir = [&](pair<int,int> interval){
        intervalos.insert(interval);
        intervalos_prioridade.insert(interval);
    };
    auto remover = [&](pair<int,int> interval){
        intervalos.erase(interval);
        intervalos_prioridade.erase(interval);
    };
    inserir({1, n});
    for(int i = 1; i<=q; i++){
        cin>>tipo;
        if(tipo == 0){
            aux = (*intervalos_prioridade.begin());
            if(aux.second == n){
                cout<<n<<'\n';
                remover(aux);
                if(aux.first != n) inserir({aux.first, n-1});
                lista[i] = n;
            }
            else if(aux.first == 1){
                cout<<1<<'\n';
                remover(aux);
                if(aux.second != 1) inserir({2, aux.second});
                lista[i] = 1;
            }
            else{
                k = aux.first + ((aux.second - aux.first + 1)/2);
                cout<<k<<'\n';
                remover(aux);
                if(aux.first != k) inserir({aux.first, k-1});
                if(aux.second != k) inserir({k+1, aux.second});
                lista[i] = k;
            }
        }
        else{
            cin>>paciente;
            k = lista[paciente];
            left = k; right = k;
            auto it = intervalos.lower_bound({k,0});
            if(it != intervalos.end()) aux = (*it);
            if(it != intervalos.end() && aux.first == k + 1){remover(aux); right = aux.second;}
            auto et = intervalos.lower_bound({k,0}); 
            auto at = et;
            if(et != intervalos.begin()) xua = *(--at);
            if(et != intervalos.begin() && xua.second == k - 1){remover(xua); left = xua.first;}
            inserir({left, right});
        }
    }
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    solve();
    return 0;
}