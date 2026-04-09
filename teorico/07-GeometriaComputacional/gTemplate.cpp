#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const double eps = 1e-12;

int cmp(double a, double b){ // mudar cmp tambem
    if(abs(a-b) < eps) return 0;
    if(a < b) return -1;
    else return 1;
}

struct Point{ //mudar tipo dependendo da questão
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
long double cross(const Point& p, const Point& q){return ((p.x * q.y) - (p.y * q.x));} // (modulo) area do paralelogramo;
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
            if(cross(v1,v2) > 0){
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
            if(cross(v1,v2) < 0){
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

bool isInside(const vector<Point> &hull, Point pt){
    int n = hull.size();
    Point v0 = pt - hull[0], v1 = hull[1] - hull[0], v2 = hull[n-1] - hull[0];
    if(cross(v0,v1) > 0 || cross(v0,v2) < 0){
        return false;
    }
    int l = 1, r = n-1;
    while(l != r){
        int mid = (l + r + 1)/2;
        Point v1 = hull[mid] - hull[0];
        if(cross(v0,v1) < 0){
            l = mid;
        }
        else{
            r = mid - 1;
        }
    }
    v0 = hull[(l+1)%n] - hull[l];
    v1 = pt - hull[l];
    return cross(v0,v1) >= 0;
}