#include<bits/stdc++.h>
using namespace std;
using ll = long long;
/*
vector<Point> vacas;

double f(double x, double y) {
    double resposta = 0.0;
    double aux; Point aux2;
    for(int i = 0; i<n; i++){
        aux2.x = x; aux2.y = y; aux2.raio = vacas[i].raio;
        aux = dist(vacas[i], aux2) - aux2.raio;
        if(aux < 0.0) continue;
        if(resposta - aux < eps){
            resposta = aux;
        }
    }
    return resposta; 
}
double ternaryY(double x) {
    double l = -1000, r = 1000;
    for (int i = 0; i < 100; i++) { //limitar quantidade de vezes da procura, util para ld, ou double
        double m1 = l + (r - l) / 3.0;
        double m2 = r - (r - l) / 3.0;
        if (f(x, m1) > f(x, m2)) {
            l = m1;
        } else {
            r = m2;
        }
    }
    return f(x, l); 
}
double ternaryX() {
    double l = -1000, r = 1000;
    for (int i = 0; i < 100; i++) {
        double m1 = l + (r - l) / 3.0;
        double m2 = r - (r - l) / 3.0;
        if (ternaryY(m1) > ternaryY(m2)) {
            l = m1; 
        } else {
            r = m2;
        }
    }
    return ternaryY(l); 
} //exemplo de ternária aninhada
 */

// while(r - l > 2){
//     int m1 = l + ((r-l)/3);
//     int m2 = r - ((r-l)/3);
//     r1 = custoE[m1] + dist(right[i], left[m1]);
//     r2 = custoE[m2] + dist(right[i], left[m2]);
//     if(r1 < r2){
//         r = m2;
//     }
//     else{
//         l = m1;
//     }
// } // escopo
