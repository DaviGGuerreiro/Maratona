    #include<bits/stdc++.h>
    using namespace std;

    int main(){

        ios::sync_with_stdio(false);cin.tie(0);

        int t;
        int input;
        int median;
        cin>>t;
        for(int i=0;i<t;i++){
            multiset<int> maior, menor;
            int size_d=0, size_e=0;
            cin>>input;
            median = input;
            if(median != 0){
                cin>>input;
            }
            while(input!=0){
                if(input==-1){
                    cout<<median<<'\n';
                    if(size_d==size_e){
                        if(size_e!=0){
                            median = *menor.rbegin();
                            auto it = prev(menor.end());
                            menor.erase(it);
                            size_e--;
                        }
                        else{
                            median = -1;
                        }
                    }
                    else{
                        median = *maior.begin();
                        auto it = maior.begin();
                        maior.erase(it);
                        size_d--;
                    }
                }
                else if(input > 0){
                    if(median==-1){
                        median = input;
                    }
                    else if(input>median){
                        if(size_d==size_e){
                            maior.insert(input);
                            size_d++;
                        }
                        else{
                            maior.insert(input);
                            menor.insert(median);
                            median = *maior.begin();
                            auto it = maior.begin();
                            maior.erase(it);
                            size_e++;
                        }
                    }
                    else{
                        if(size_d==size_e){
                            menor.insert(input);
                            maior.insert(median);
                            median = *menor.rbegin();
                            auto it = prev(menor.end());
                            menor.erase(it);
                            size_d++;
                        }
                        else{
                            menor.insert(input);
                            size_e++;
                        }
                    }
                }
                cin>>input;
            }
        }

        return 0;
    }