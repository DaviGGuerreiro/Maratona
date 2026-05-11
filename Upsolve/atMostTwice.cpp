#include<bits/stdc++.h>
using namespace std;
using ll = long long;

string n;
string resposta = "";
vector<int> f (10,0);

bool solve(int index, bool menorque, string& atual){
    if(index == n.size()){
        resposta = atual;
        return true;
    }

    int limite = menorque ? 9 : (n[index] - '0');

    for(int i = limite; i>=0; i--){
        if(f[i] == 2) continue;

        if(f[i] < 2){
            f[i]++;
            atual.push_back(i + '0');
        }

        if(solve(index + 1, (menorque || i < limite), atual)){
            return true;
        }

        atual.pop_back();
        f[i]--;
    }

    return false;
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    cin>>n; string atual = "";
    solve(0, false, atual);
    return 0;
}