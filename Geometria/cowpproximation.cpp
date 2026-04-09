#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
const double eps = 1e-9;
int n; 
int cmp(double a, double b){
    if(abs(a - b) < eps) return 0;
    if(a < b) return -1;
    else return 1;
}

struct Point{
        double x, y, raio;
        Point(double x = 0, double y = 0, double raio = 0) : x(x),y(y),raio(raio){}
        Point(const Point& p): x(p.x), y(p.y), raio(p.raio){}
    bool operator < (const Point &p) const{
        if(cmp(x, p.x) != 0) return x < p.x;
        return cmp(y, p.y) < 0;
    }
    bool operator == (const Point &p) const{return !cmp(x, p.x) && !cmp(y, p.y);}
    bool operator != (const Point &p) const{return !(p == *this);}

        Point operator + (const Point &p) const{return Point(x + p.x, y + p.y);}
        Point operator - (const Point &p) const{return Point(x - p.x, y - p.y);}
        Point operator * (const double k) const{return Point(x*k,y*k);}
        Point operator / (const double k) const{return Point(x/k,y/k);}
        Point& operator=(const Point&) = default;
};

double dot(const Point& p, const Point& q){return ((p.x * q.x) + (p.y * q.y));}
long long cross(const Point& p, const Point& q){return ((p.x * q.y) - (p.y * q.x));} // (modulo) area do paralelogramo;
double norm(const Point& p){return hypot(p.x,p.y);}
double dist(const Point& p, const Point& q){return hypot((p.x - q.x), (p.y - q.y));} 
double dist2(const Point& p, const Point& q){return dot(p-q,p-q);}
Point normalize(const Point& p){return p/hypot(p.x,p.y);} //retorna vetor unitario;
double angle(const Point& p, const Point& q){return atan2(cross(p,q), dot(p,q));}
double angle(const Point& p){return atan2(p.y,p.x);}

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
    for (int i = 0; i < 100; i++) {
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
}

void solve(){
    cin>>n;
    vacas = vector<Point> (n);
    for(int i = 0; i<n;i++){
        cin>>vacas[i].x>>vacas[i].y>>vacas[i].raio;
    }
    if(n == 1){cout<<fixed<<setprecision(7)<<0.0<<'\n'; return;}
    double resposta = ternaryX();
    cout<<fixed<<setprecision(7)<<resposta<<'\n';
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    solve();
    return 0;
}