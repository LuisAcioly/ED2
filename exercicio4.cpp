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
        noh* josephusAux(noh* aux, int num);
    public:
        lista(int num);
        void imprimir();
        int josephus(int num);
        void remover(noh* aux, noh* temp);
};

lista::lista(int num){
    mPrimeiro = NULL;
    mUltimo = NULL;
    mTamanho = 0;
    
    for(int i = 1; i < num+1; i++)
    {   
        inserir(i);
    }
    
    mUltimo->proximo = mPrimeiro;
}

void lista::inserir(int num){
    noh* novo = new noh(num);

    if(mTamanho == 0){
        mPrimeiro = novo;
        mUltimo = novo;
    }
    else{
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

int lista::josephus(int num){
	noh* aux = josephusAux(mPrimeiro, num);
	
	return aux->valor;
}

noh* lista::josephusAux(noh* aux, int num){
	if(mTamanho == 1){
		return aux;
	}
	else{
		noh* temp;
		for (int i = 0; i < num+1; i++)
		{
			temp = aux;
			aux = aux->proximo;
		}
		
		remover(aux, temp);
		
		return josephusAux(temp->proximo, int num);
		
	}
}

void lista::remover(noh* aux, noh* temp){
	if(aux == mPrimeiro){
		mPrimeiro = aux->proximo;
		mUltimo->proximo = mPrimeiro;
		aux->proximo = NULL;
		delete aux;
	}
	else if(aux == mUltimo){
		mUltimo = temp;
		mUltimo->proximo = mPrimeiro;
		aux->proximo = NULL;
		delete aux;
	}
	else{
		temp->proximo = aux->proximo;
		aux->proximo = NULL;
		delete aux;
	}
}



int main(){

    int N, M;

    cin >> N;

    lista umaLista(N);
    
    umaLista.imprimir();

    return 0;
}
