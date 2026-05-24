#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;

int main(){

    int N;
    cin>>N;

    int distancia=0;
    int vermelho;
    int verde;
    int azul;

    vector<int> r(N,0);
    vector<int> g(N,0);
    vector<int> b(N,0);


    for(int i=0;i<N;i++){

        cin>>r[i]>>g[i]>>b[i];

    }

    for(int i=0;i<256;i++){

        for(int j=0;j<256;j++){

            for(int k=0;k<256;k++){

                int dist=INF;


                for(int x=0;x<N;x++){
                
                    int d=abs(r[x]-i)+abs(g[x]-j)+abs(b[x]-k);

                    dist=min(dist,d);

                }

                if(dist>distancia){

                        distancia=dist;
                        vermelho=i;
                        verde=j;
                        azul=k;
                    }
            }
        }
    }

    cout<<vermelho<<" "<<verde<<" "<<azul;
}