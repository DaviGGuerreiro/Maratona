#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int t, n;
    cin>>t;
    ll a1, a2, a3, a4, a5, a6;
    ll aux;
    while(t--){
        cin>>n;
        a1 = 1e18 + 1;
        a2 = 1e18 + 1;
        a3 = 1e18 + 1;
        a4 = 1e18 + 1;
        a5 = 1e18 + 1;
        a6 = 1e18 + 1;
        vector<pair<int,int>> vec (n);
        vector<pair<int,int>> v (n);
        for(int i=0;i<n;i++){
            cin>>vec[i].first;
            cin>>vec[i].second;
            v[i].first = vec[i].second;
            v[i].second = vec[i].first;
        }
        sort(vec.begin(),vec.end());
        sort(v.begin(),v.end());
        if(n>2){
            if(v[0].first == vec[0].second && v[0].second == vec[0].first){
                a1 = min(a1, 1LL * (v[n-1].first - v[1].first + 1) * (vec[n-1].first - vec[1].first + 1));
                if(a1<n){
                    aux = min(a1 + v[n-1].first -v[1].first + 1, a1 + vec[n-1].first - vec[1].first + 1);
                    a1 = aux;
                }
            }
            else if(v[0].first == vec[n-1].second && v[0].second == vec[n-1].first){
                a1 = min(a1, 1LL * (v[n-1].first - v[1].first + 1) * (vec[n-2].first - vec[0].first + 1));
                if(a1<n){
                    aux = min(a1 + v[n-1].first - v[1].first + 1, a1 + vec[n-2].first - vec[0].first + 1);
                    a1 = aux;
                }
            }

            if(v[n-1].first == vec[n-1].second && v[n-1].second == vec[n-1].first){
                a2 = min(a2,1LL * (v[n-2].first - v[0].first + 1) * (vec[n-2].first - vec[0].first + 1));
                if(a2<n){
                    aux = min(a2 + v[n-2].first -v[0].first + 1, a2 + vec[n-2].first - vec[0].first + 1);
                    a2 = aux;
                }
            }
            else if(v[n-1].first == vec[0].second && v[n-1].second == vec[0].first){
                a2 = min(a2,1LL * (v[n-2].first - v[0].first + 1) * (vec[n-1].first - vec[1].first + 1));
                if(a2<n){
                    aux = min(a2 + v[n-2].first -v[0].first + 1, a2 + vec[n-1].first - vec[1].first + 1);
                    a2 = aux;
                }
            }

            a5 = min(a5, 1LL * (v[n-1].first - v[1].first+1) * (vec[n-1].first - vec[0].first +1));
            if(a5<n){
                aux = min(a5 + v[n-1].first - v[1].first + 1, a5 + vec[n-1].first - vec[0].first + 1);
                a5 = aux;
            }
            a6 = min(a6, 1LL * (v[n-2].first - v[0].first+1) * (vec[n-1].first - vec[0].first +1));
            if(a6<n){
                aux = min(a6 + v[n-2].first - v[0].first + 1, a6 + vec[n-1].first - vec[0].first + 1);
                a6 = aux;
            }
            a3 = min(a3, 1LL * (v[n-1].first - v[0].first+1) * (vec[n-1].first - vec[1].first +1));
            if(a3<n){
                aux = min(a3 + v[n-1].first - v[0].first + 1, a3 + vec[n-1].first - vec[1].first + 1);
                a3 = aux;
            }
            a4 = min(a4, 1LL * (v[n-1].first - v[0].first+1) * (vec[n-2].first - vec[0].first +1));
            if(a4<n){
                aux = min(a4 + v[n-1].first - v[0].first + 1, a4 + vec[n-2].first - vec[0].first + 1);
                a4 = aux;
            }
            a1 = min(a1,a2);
            a1 = min(a1,a3);
            a1 = min(a1,a4);
            a1 = min(a1,a5);
            a1 = min(a1,a6);

            cout<<a1<<'\n';
        }
        else{
            cout<<n<<'\n';
        }
    }

    return 0;
}