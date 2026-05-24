#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define int double
#define pi acos(-1)
using namespace std;

int32_t main(){


    int raio;
    cin>>raio;


    int a=asin((double)3/(double)5);

    int ang=pi-(double)2*a;

    int atriangulo=raio*raio*sin(ang)*0.5;



    int resp=pi*raio*raio*0.5 - (raio*raio*ang*(0.5) - atriangulo);

    cout<<fixed<<setprecision(10)<<resp;




}