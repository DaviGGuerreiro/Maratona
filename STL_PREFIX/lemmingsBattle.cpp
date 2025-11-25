#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int t, aux;
    int b, azul, verde;
    cin>>t;
    priority_queue<int> v;
    priority_queue<int> a;
    stack<int> wa;
    stack<int> wv;
    int l = 0;
    while(t--){
        cin>>b>>verde>>azul;
        for(int i = 0;i<verde;i++){
            cin>>aux;
            v.push(aux);
        }
        for(int i = 0;i<azul;i++){
            cin>>aux;
            a.push(aux);
        }
        while(!a.empty() && !v.empty()){
            l++;
            if(a.top() == v.top()){
                a.pop();
                v.pop();
            }
            else if(a.top() > v.top()){
                aux = a.top() - v.top();
                a.pop();
                v.pop();
                wa.push(aux);
            }
            else{
                aux = v.top() - a.top();
                v.pop();
                a.pop();
                wv.push(aux);
            }
            if(l%b == 0 || a.empty() || v.empty()){
                while(!wa.empty()){
                    a.push(wa.top());
                    wa.pop();
                }
                while(!wv.empty()){
                    v.push(wv.top());
                    wv.pop();
                }
                l = 0;
            }
        }
        if(a.empty()){
            if(v.empty()){
                cout<<"green and blue died\n";
            }
            else{
                cout<<"green wins\n";
                while(!v.empty()){
                    cout<<v.top()<<'\n';
                    v.pop();
                }
            }
        }
        else{
            cout<<"blue wins\n";
            while(!a.empty()){
                cout<<a.top()<<'\n';
                a.pop();
            }
        }
        if(t != 0){
            cout<<'\n';
        }
    }
    return 0;
}