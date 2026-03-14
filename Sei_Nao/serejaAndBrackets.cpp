#include<bits/stdc++.h>
using namespace std;
using ll = long long;

struct Query{
    int l, r, idx;
};

vector<ll> resposta;
vector<Query> queries;
vector<Query> aux;
vector<pair<int,i nt    >> s, p, esquerda, direita, esq, dir;

void dnc(int l, int r, int ql, int qr){
    if(l > r || ql > qr) return;
    int m = l + (r-l)/2;
    int cnt_l = 0, cnt_m = 0, cnt_r = 0; // quantidade de queries q ficam a esquerda, têm ou ficam a direita de m
    for(int i = ql; i <= qr; i++){
        if(queries[i].l <= m && m <= queries[i].r) cnt_m++;
        else if(queries[i].r < m) cnt_l++;
        else cnt_r++;
    }

    int p_l = ql, p_m = ql + cnt_l, p_r = p_m + cnt_m; // iterador que indica inicio de cada uma desses grupos [esquerda,m,direita]
    for(int i = ql; i <= qr; i++){ //atualiza aux para delimitar [esquerda,meio,direita]
        if(queries[i].l <= m && queries[i].r >= m){
            aux[p_m] = queries[i];
            p_m++;
        }
        else if(queries[i].r < m){
            aux[p_l] = queries[i];
            p_l++;
        }
        else{
            aux[p_r] = queries[i];
            p_r++;
        }
    }

    for(int i = ql; i <= qr; i++){ //queries pega os valores antes organizados
        queries[i] = aux[i];
    }

    int l_start = ql, l_end = ql + cnt_l - 1; // indicadores comeco e fim de cada um dos grupos [esquerda,meio,direita]
    int m_start = l_end + 1, m_end = m_start + cnt_m - 1;
    int r_start = m_end + 1, r_end = qr;
    
    dnc(l, m - 1, l_start, l_end);
    dnc(m+1, r, r_start, r_end);

    if(m_start > m_end) return;

    ll soma = vec[m];
    s[m] = vec[m];  //salvando menor sufixo [l,m]
    for(int i = m-1; i>=l; i--){
        soma += vec[i];
        s[i] = max(soma, s[i+1]);
    }

    esq[m] = max(0LL,vec[m]);
    esquerda[m] = max(0LL, vec[m]);
    for(int i = m-1; i>=l; i--){
        if(vec[i] >= 0){
            esquerda[i] = esquerda[i+1] + vec[i];
        }
        else{
            esquerda[i] = max(0LL, esquerda[i+1] + vec[i]);
        }
        esq[i] = max(esq[i+1],esquerda[i]); 
    }

    soma = vec[m];
    p[m] = vec[m];  // salvando menor prefixo [m,r]
    for(int i = m+1; i<=r; i++){
        soma += vec[i];
        p[i] = max(soma, p[i-1]);
    }

    dir[m] = max(0LL,vec[m]);
    direita[m] = max(0LL,vec[m]);
    for(int i = m+1; i<=r; i++){
        if(vec[i] >= 0){
            direita[i] = direita[i-1] + vec[i];
        }
        else{
            direita[i] = max(0LL, direita[i-1] + vec[i]);
        }
        dir[i] = max(dir[i-1], direita[i]);
    }

    Query x;
    for(int i = m_start; i<= m_end; i++){
        x = queries[i];
        resposta[x.idx] = min(s[x.l], p[x.r]);  //query x é uma query do meio que tem como menor valor ou o menor sufixo [l,m] ou o menor prefixo [m,r]
    }

}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    string si; cin>>si;
    int q; cin>>q;
    queries = vector<Query> (q);
    int a, b;
    for(int i = 0;i<q;i++){
        cin>>queries[i].l;queries[i].l--;
        cin>>queries[i].r;queries[i].r--;
        queries[i].idx = i;
    }
    dnc(0, n-1, 0, q-1);
    return 0;
}