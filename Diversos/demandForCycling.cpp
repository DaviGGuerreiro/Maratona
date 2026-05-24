#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    int menor1=1e9+1, menor2=1e9+1;
    int maior1=-1, maior2=-1; 
    int a, b;
    for(int i=0;i<n;i++){
        cin>>a>>b;
        menor1 = min(menor1, a);
        menor2 = min(menor2, b);
        maior1 = max(maior1, a);
        maior2 = max(maior2, b);
    }
    cout<<4<<'\n';
    cout<<maior1<<" "<<menor2<<'\n';
    cout<<maior1<<" "<<maior2<<'\n';
    cout<<menor1<<" "<<maior2<<'\n';
    cout<<menor1<<" "<<menor2<<'\n';
    return 0;
}