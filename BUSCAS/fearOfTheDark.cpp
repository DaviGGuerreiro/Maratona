#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    cout<<fixed<<setprecision(10);
    int t;
    cin>>t;
    long double xc, yc;
    long double xl1, yl1;
    long double xl2, yl2;
    long double aux1, aux2, aux3, aux4, aux5, aux6;
    long double r, s, x, y,w ,k, R ;
    while(t--){
        cin>>xc>>yc>>xl1>>yl1>>xl2>>yl2;

        aux1 = (xl1-xc)*(xl1-xc) + (yl1-yc)*(yl1-yc); // lant1 ate casa
        aux3 = (xl2-xc)*(xl2-xc) + (yl2-yc)*(yl2-yc); //lant 2 ate casa
        aux2 = ((xl1-xl2)*(xl1-xl2) + (yl1-yl2)*(yl1-yl2))/4; //lant 1 lant 2
        aux4 = (xl1)*(xl1) + (yl1)*(yl1); //lant1 ate p
        aux5 = (xl2)*(xl2) + (yl2)*(yl2); //lant2 ate p
        
        r = max(aux1, aux4); //lan1 cobrindo tudo

        s = max(aux3, aux5); //lan2 cobrindo tudo

        w = max(aux2, aux4); //p - lan1 - lan2 - c
        w = max(w, aux3);

        k = max(aux2, aux5); //p - lan2 - lan1 - c
        k = max(k, aux1);
        //cout<<s<<' '<<r<<'\n';

        R = min({r,s,w,k});
        R = sqrt(R);
        cout<<R;
        cout<<'\n';
    }
    return 0;
}