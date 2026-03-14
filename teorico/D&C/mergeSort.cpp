#include<bits/stdc++.h>
using namespace std;
using ll = long long;

vector<int> vec;
vector<int> aux;
ll inversoes = 0;

void merge(int l, int m, int r){
    int i = l, j = m+1, k = l;
    while(i <= m && j <= r){
        if(vec[i] < vec[j]){
            aux[k] = vec[i];
            i++;
        }
        else{
            aux[k] = vec[j];
            j++;
        }
        k++;
    }
    while(i <= m){
        aux[k] = vec[i];
        i++;
        k++;
    }
    while(j <= r){
        aux[k] = vec[j];
        j++;
        k++;
    }
    return;
}

void mergeSort(int l, int r){
    if(l >= r) return;
    int m = l + (r-l)/2;
    mergeSort(l,m);
    mergeSort(m+1,r);
    merge(l, m, r);
    
    ll a = 0;
    for(int i = l; i<=m; i++){
        while(a < (r - m) && vec[a + m + 1] <= vec[i]) a++;
        inversoes += a;
    }

    for(int i = l; i<= r; i++){
        vec[i] = aux[i];
    }
}

void solve(){
    int n; cin>>n;
    vec = vector<int> (n);
    aux = vector<int> (n);
    for(int i = 0;i<n; i++){
        cin>>vec[i];
    }
    mergeSort(0, n-1);
    for(int i = 0; i<n; i++){
        cout<<vec[i]<<" ";
    }
    cout<<'\n';
    cout<<inversoes;
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    solve();
    return 0;
}