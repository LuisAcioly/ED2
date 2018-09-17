#include <iostream>
using namespace std;

class noh{
    friend class lista;
    private:
        noh* proximo;
        int valor;
    public:
        noh(int num);
};

noh::noh(int num) : valor(num){
    proximo = NULL;
}

class lista{
    private:  
        noh* mPrimeiro;
        noh* mUltimo;
        int mTamanho;
        void inserir(int num);
    public:
        lista(int num);
        void imprimir();
};

lista::lista(int num){
    mPrimeiro = NULL;
    mUltimo = NULL;
    
    for(int i = 1; i < num+1; i++)
    {   
        cout << "a" << endl;
        inserir(i);
    }

    mUltimo->proximo = mPrimeiro;
}

void lista::inserir(int num){
    noh* novo = new noh(num);

    if(mTamanho == 0){
        cout << "b" << endl;
        mPrimeiro = novo;
        mUltimo = novo;
    }
    else{
        cout << "b" << endl;
        mUltimo->proximo = novo;
        mUltimo = novo;
    }

    mTamanho++;
}

void lista::imprimir(){
    noh* aux = mPrimeiro;

    
    for(int i = 0; i < mTamanho; i++)
    {
        cout << aux->valor << " ";
        aux = aux->proximo;
    }
    
}

int main(){

    int N, M;

    cin >> N;

    lista umaLista(N);

    umaLista.imprimir();

    return 0;
}
