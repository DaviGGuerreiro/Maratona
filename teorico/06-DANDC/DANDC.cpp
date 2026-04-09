#include<bits/stdc++.h>
using namespace std;
using ll = long long;
struct Query{
    int l, r, idx;
};
vector<int> vec;
vector<int> resposta;
vector<Query> queries;
vector<Query> aux;
vector<int> s, p;
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
    s[m] = vec[m];  //salvando menor sufixo [l,m]
    for(int i = m-1; i>=l; i--){
        s[i] = min(vec[i], s[i+1]);
    }
    p[m] = vec[m];  // salvando menor prefixo [m,r]
    for(int i = m+1; i<=r; i++){
        p[i] = min(vec[i], p[i-1]);
    }
    Query x;
    for(int i = m_start; i<= m_end; i++){
        x = queries[i];
        resposta[x.idx] = min(s[x.l], p[x.r]);  //query x é uma query do meio que tem como menor valor ou o menor sufixo [l,m] ou o menor prefixo [m,r]
    }
}

void solve(){
    int n, q; cin>>n>>q;
    vec = vector<int> (n);
    s = vector<int> (n);
    p = vector<int> (n);
    resposta = vector<int> (q);
    queries = vector<Query> (q);
    aux = vector<Query> (q);
    for(int i=0;i<n;i++) cin>>vec[i];
    for(int i=0;i<q;i++){
        cin>>queries[i].l;
        cin>>queries[i].r;
        queries[i].l--; queries[i].r--;
        queries[i].idx = i;
    }
    dnc(0, n-1, 0, q-1);
    for(int i = 0;i<q;i++){
        cout<<resposta[i]<<'\n';
    }
}