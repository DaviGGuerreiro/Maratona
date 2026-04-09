#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const double eps = 1e-12;

int cmp(double a, double b){
    if(abs(a-b) < eps) return 0;
    if(a < b) return -1;
    else return 1;
}

struct Point{
        double x, y;
        Point(double x = 0, double y = 0) : x(x),y(y){}
        Point(const Point& p): x(p.x), y(p.y){}
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
};

double dot(const Point& p, const Point& q){return ((p.x * q.x) + (p.y * q.y));}
double cross(const Point& p, const Point& q){return ((p.x * q.y) - (p.y * q.x));} // (modulo) area do paralelogramo;
double norm(const Point& p){return hypot(p.x,p.y);}
double dist(const Point& p, const Point& q){return hypot((p.x - q.x), (p.y - q.y));} 
double dist2(const Point& p, const Point& q){return dot(p-q,p-q);}
Point normalize(const Point& p){return p/hypot(p.x,p.y);} //retorna vetor unitario;
double angle(const Point& p, const Point& q){return atan2(cross(p,q), dot(p,q));}
double angle(const Point& p){return atan2(p.y,p.x);}


void solve(){
    double x1, y1, x2, y2, x3, y3;
    cin>>x1>>y1>>x2>>y2>>x3>>y3;
    Point a(x1,y1), b(x2,y2), c(x3,y3);
    Point v1 = b - a;
    Point v2 = c - a;
    double aux = angle(v1,v2);
    if(abs(aux - M_PI) < eps || abs(aux + M_PI) < eps || abs(aux) < eps){
        cout<<"TOUCH"<<'\n';
    }
    else if(aux < -eps){
        cout<<"RIGHT"<<'\n';
    }
    else{
        cout<<"LEFT"<<'\n';
    }
    return;
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int t; cin>>t;
    while(t--){
        solve();
    }
    return 0;
}