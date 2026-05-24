#include <bits/stdc++.h>
using namespace std;

int main(){

    int N;
    cin>>N;

    vector<int> v(N+1,0);
    vector<int> qtd(N+1,0);

    for(int i=1;i<=N;i++){

        cin>>v[i];
        qtd[v[i]]++;

    }


    for(int i=1;i<=N;i++){

        if(qtd[i]>4){
            cout<<"N";
            return 0;
        }
    }

    for(int i=1;i<N;i++){

        if(qtd[v[i]]>3 && qtd[v[i+1]]>3 && v[i]!=v[i+1]){
            cout<<"N";
            return 0;
        }



    }

    cout<<"S";



}