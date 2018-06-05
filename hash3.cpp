#include <iostream>
#include <string>

using namespace std;

typedef string dados;

const int PRIMO = 13;

int funcaoHash(dados key, int cap){
    long h = 0;
    for(int i = 0; i < key.length(); i++){
        h = (PRIMO * h + key[i])%cap;
    }
    return h;
}

class noh{
    friend class hash;
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
        string recupera(dados key);

};

hash::hash(int cap){
    elementos = new noh*[cap];
    capacidade = cap;
}

void hash::insere(dados key, dados valor){
    int posicao = funcaoHash(dados key, dados valor);

    if(this->recupera == "NÃO ENCONTRADO"){
       if(elementos[h] == NULL){
            elementos[h] = new noh;
            elementos[h]->chave = key;
            elementos[h]->dado = valor;
            elementos[h]->proximo = NULL;
       }
       else{
           cout << "colidiu" << endl;
            noh* atual = elementos[h];
           while(atual->proximo != NULL){
               atual = atual->proximo;
           }
            noh* novo = new noh;
            novo->chave = key;
            novo->dado = valor;
            atual->proximo = novo;
           
       }
    }
    
}

string hash::recupera(dados key){
    long h = funcaoHash(dados key);

    if(elementos[h] != NULL and elementos[h]->chave == key){
        return elementos[h]->dado;
    }
    else{
        noh* atual = elementos[h];

        while(atual != NULL and atual->chave != key){
                atual = atual->proximo;
        }
        if(atual != NULL and atual->chave == key){
            return atual->valor;
        }
        else{
            return "NÃO ENCONTRADO";
        }


    }
}
