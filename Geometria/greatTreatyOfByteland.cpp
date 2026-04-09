#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const double eps = 1e-12;

int cmp(ll a, ll b){
    if(a == b) return 0;
    if(a < b) return -1;
    else return 1;
}

struct Point{
        ll x, y;
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

vector<Point> convexHull(vector<Point>& pts, bool sorted = false){
    int n = pts.size();
    if(!sorted){
        sort(pts.begin(),pts.end());
    }
    vector<Point> lower(n+1), upper(n+1);
    int s = 0;
    for(int i = 0;i < n;i++){
        lower[s++] = pts[i];
        while(s>=3){
            Point a = lower[s-3]; Point b = lower[s-2]; Point c = lower[s-1];
            Point v1 = b-a, v2 = c - b;
            if(cross(v1,v2) >= 0){
                break;
            }
            lower[s-2] = lower[s-1];
            s--;
        }
    }
    lower.resize(s);
    s = 0;
    for(int i = 0;i < n;i++){
        upper[s++] = pts[i];
        while(s>=3){
            Point a = upper[s-3]; Point b = upper[s-2]; Point c = upper[s-1];
            Point v1 = b-a, v2 = c - b;
            if(cross(v1,v2) <= 0){
                break;
            }
            upper[s-2] = upper[s-1];
            s--;
        }
    }
    upper.resize(s-1);
    reverse(upper.begin(),upper.end());
    upper.pop_back();
    lower.insert(lower.end(),upper.begin(),upper.end());
    return lower;
}

void solve(){
    int n; cin>>n;
    vector<Point> vec(n);
    map<Point, int> mapa;
    for(int i=0;i<n;i++){
        cin>>vec[i].x>>vec[i].y;
        mapa[vec[i]] = i+1;
    }
    if(n == 2){ cout<<1<<' '<<2<<' '; return;}
    auto v = convexHull(vec, false);
    set<int> resposta;
    for(auto it : v){
        resposta.insert(mapa[it]);
    }
    for(auto it : resposta){
        cout<<it<<' ';
    }
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    solve();
    return 0;
} 