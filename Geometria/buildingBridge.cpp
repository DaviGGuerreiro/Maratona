#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const double eps = 1e-12;

int cmp(double a, double b){
    if(abs(a - b) < eps) return 0;
    if(a < b) return -1;
    else return 1;
}

struct Point{
        double x, y;
        Point(ll x = 0, ll y = 0) : x(x),y(y){}
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
    double resposta = 1e9;
    int f1 = 0, f2 = 0;
    int n, m, a, b;
    cin>>n>>m>>a>>b;
    vector<Point> left(n);
    vector<Point> right(m);
    vector<int> custo(m);
    vector<double> custoE(n);
    for(int i = 0; i<n; i++){
        left[i].x = a;
        cin>>left[i].y;
        custoE[i] = norm(left[i]);
    }
    for(int i = 0;i<m; i++){
        right[i].x = b;
        cin>>right[i].y;
    }
    for(int i = 0;i<m; i++){
        cin>>custo[i];
    }
    double valor;
    double r1, r2;
    for(int i = 0; i<m; i++){
        valor = custo[i];
        int l = 0, r = n-1;
        while(r - l > 2){
            int m1 = l + ((r-l)/3);
            int m2 = r - ((r-l)/3);
            r1 = custoE[m1] + dist(right[i], left[m1]);
            r2 = custoE[m2] + dist(right[i], left[m2]);
            if(r1 < r2){
                r = m2;
            }
            else{
                l = m1;
            }
        }
        double local = 1e9;
        int id = 0;
        for (int k = l; k <= r; k++) {
            if (custoE[k] + dist(right[i], left[k]) < local) {
                local = custoE[k] + dist(right[i], left[k]);
                id = k;
            }
        }
        local += valor;
        if(local - resposta < eps){
            resposta = local;
            f1 = id + 1;
            f2 = i+1;
        }
    }
    cout<<f1<<" "<<f2<<'\n';
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    solve();
    return 0;
} 