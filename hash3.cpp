#include <iostream>

using namespace std;
typedef string dados;

int funcaoHash(dados key, dados valor){
    
}

class noh{
    private:
        noh* proximo;
        dados dado;
        dados chave;
    public:
        noh(dados d = 0);

};

noh::noh(dados d){
    proximo = NULL;
    dado = d;
    chave = "";
}

class hash{
    private:
        noh** elementos;
        int capacidade;
    public:
        hash(int cap = 10);
        void insere(dados key, dados valor);

};

hash::hash(int cap){
    elementos = new noh*[cap];
    capacidade = cap;
}

void hash::insere(dados key, dados valor){
    int posicao = funcaoHash(dados key, dados valor);
}
