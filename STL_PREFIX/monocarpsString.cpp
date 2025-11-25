    #include<bits/stdc++.h>
    using namespace std;

    int main(){
        ios::sync_with_stdio(false);cin.tie(0);
        int t, n;
        int resto;
        cin>>t;
        while(t--){
            cin>>n;
            vector<int> vec;
            char aux;
            resto = 0;
            int a=0,b=0;
            int a_aux=0, b_aux=0;
            for(int i=0;i<n;i++){
                cin>>aux;
                if(aux == 'a'){
                    a++;
                    a_aux++;
                    if(b_aux!=0){
                        vec.push_back(-b_aux);
                        b_aux = 0;
                    }
                }
                else{
                    b++;
                    b_aux++;
                    if(a_aux!=0){
                        vec.push_back(a_aux);
                        a_aux=0;
                    }
                }
            }
            if(a_aux != 0){
                vec.push_back(a_aux);
            }
            else{
                vec.push_back(-b_aux);
            }
            int diferenca = a-b;
            int soma = 0;
            int quantidade = 0;
            int resposta = 1e9;
            bool c = false;
            if(diferenca == 0){
                cout<<soma<<'\n';
            }
            else if(diferenca > 0){
                vector<int> vet;
                size_t j = 0;
                for(int d : vec){
                    soma = soma + d;
                    vet.push_back(d);
                    if(d<0){
                        quantidade = quantidade - d;
                    }
                    else{
                        quantidade = quantidade + d;
                    }
                    if(soma <= 0){
                        soma = 0;
                        quantidade = 0;
                        j = vet.size();
                    }
                    else if(soma >= diferenca){
                        c = true;
                        if(d >= diferenca){
                            resposta = diferenca;
                            if(a == 0 || b == 0){
                                c = false;
                            }
                            break;
                        }
                        else{
                            resto = soma - diferenca;
                            while(j < vet.size()-1 && resto>=vet[j]){
                                resto = resto - vet[j] - vet[j+1];
                                quantidade = quantidade - vet[j] + vet[j+1];
                                j = j+2;
                            }
                            vet[j] = vet[j] - resto;
                            //cout<<resto<<'\n';
                            if(quantidade-resto < resposta){
                                if(quantidade-resto == a + b){
                                    c = false;
                                    break;
                                }
                                else{
                                    resposta = quantidade-resto;
                                }
                            }
                            soma = diferenca;
                        }
                    }
                }
                if(c){
                    cout<<resposta<<'\n';
                }
                else{
                    cout<<-1<<'\n';
                } 
            }
            else{
                vector<int> vet;
                size_t j = 0;
                for(int d : vec){
                    soma = soma + d;
                    vet.push_back(d);
                    if(d<0){
                        quantidade = quantidade - d;
                    }
                    else{
                        quantidade = quantidade + d;
                    }
                    if(soma >= 0){
                        soma = 0;
                        quantidade = 0;
                        j = vet.size();
                    }
                    else if(soma <= diferenca){
                        c = true;
                        if(d <= diferenca){
                            resposta = -diferenca;
                            if(a == 0 || b == 0){
                                c = false;
                            }
                            break;
                        }
                        else{
                            resto = diferenca - soma;
                            while(j < vet.size()-1 && resto >= -(vet[j])){
                                resto = resto + vet[j] + vet[j+1];
                                quantidade = quantidade + vet[j] - vet[j+1];
                                j = j+2;
                            }
                            vet[j] = vet[j] + resto;
                            if(quantidade-resto < resposta){
                                if(quantidade-resto == a + b){
                                    c = false;
                                    break;
                                }
                                else{
                                    resposta = quantidade-resto; 
                                }
                            }
                            soma = diferenca;
                        }
                    }
                }
                if(c){
                    cout<<resposta<<'\n';
                }
                else{
                    cout<<-1<<'\n';
                }
            }
        }
        return 0;
    }