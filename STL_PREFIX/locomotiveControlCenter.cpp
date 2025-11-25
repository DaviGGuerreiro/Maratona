#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int n, i;
    cin>>n;
    int aux;
    stack<int> pilhaA;
    stack<int> pilhaB;
    queue<int> movimentos;
    for(i = 0;i<n;i++){
        cin>>aux;
        pilhaA.push(aux);
    }
    int q = 0;
    i = 1;
    while(i <= n){
        if(!pilhaA.empty() && pilhaA.top() == i){
            pilhaA.pop();
            movimentos.push(0);
            i++;
        }
        else if(!pilhaB.empty() && pilhaB.top() == i){
            pilhaB.pop();
            movimentos.push(1);
            i++;
        }
        else if(!pilhaA.empty()){
            aux = pilhaA.top();
            pilhaB.push(aux);
            pilhaA.pop();
            movimentos.push(2);
        }
        else{
            break;
        }
        q++;
    }
    if(i != n+1){
        cout<<-1<<'\n';
    }
    else{
        cout<<q<<'\n';
        while(q--){
            if(movimentos.front() == 0){
                cout<<"A C"<<'\n';
            } else if(movimentos.front() == 1){
                cout<<"B C"<<'\n';
            } else{
                cout<<"A B"<<'\n';
            }
            movimentos.pop();
        }
    }

    return 0;
}