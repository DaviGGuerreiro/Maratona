#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
const double eps = 1e-9;

int cmp(double a, double b){
    if(abs(a - b) < eps) return 0;
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



void solve(){
    double x1, y1, x2, y2, a;
    cin>>x1>>y1>>x2>>y2>>a; 
    Point f1(x1,y1), f2(x2,y2);
    Point meio = f1 + ((f2 - f1)/2.0);
    double Fdist = dist(f1,f2);
    if(Fdist == 0){
        cout<<fixed<<setprecision(6)<<(meio.x - (a/2.0))<<' '<<(meio.y - (a/2.0))<<' '<<(meio.x + (a/2.0))<<' '<<(meio.y + (a/2.0))<<'\n';
        return;
    }
    double auxF = Fdist/2.0;
    double aF = a/2.0;
    double b = (aF*aF) - (auxF*auxF); b = sqrt(b);
    double seno = (f1.y - f2.y)/Fdist;
    double cosseno = (f1.x - f2.x)/Fdist;

    double num1 = aF*cosseno, num2 = b * seno;
    double Maior_x = meio.x + (sqrt((num1*num1) + (num2*num2)));
    double Menor_x = meio.x - (sqrt((num1*num1) + (num2*num2)));
    num1 = aF*seno, num2 = b * cosseno;
    double Maior_y = meio.y + (sqrt((num1*num1) + (num2*num2)));
    double Menor_y = meio.y - (sqrt((num1*num1) + (num2*num2)));
    cout<<fixed<<setprecision(6)<<Menor_x<<' '<<Menor_y<<' '<<Maior_x<<' '<<Maior_y<<'\n';
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    solve();
    return 0;
}

//FiZgu6fF^f5W?xA