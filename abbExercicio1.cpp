#include <iostream>
using namespace std;

typedef int Dado;

class noh{
	friend class abb;
	private:
		noh* mPai;
		noh* mDir;
		noh* mEsq;
		Dado mValor;
	public:
		noh(Dado num);
	
};

noh::noh(Dado num) : mValor(num){
	mPai = NULL;
	mEsq = NULL;
	mDir = NULL;
}

class abb{
	private:
		noh* mRaiz;
	public:
		abb();
		void inserir(Dado num);
};

abb::abb(){
	mRaiz = NULL;
}

void abb::inserir(Dado num){
	noh* novo = new noh(num);
	
	if(mRaiz == NULL){
		mRaiz = novo;
	}
	
	else{
		noh* atual = mRaiz;
		noh* anterior;
		
		while(atual != NULL){
			anterior = atual;
			if(atual->mValor < num){
				atual = atual->mDir;
			}
			else{
				atual = atual->mEsq;
			}
		}
		
		novo->mPai = anterior;
		
		if(novo->mValor > anterior->mValor){
			anterior->mDir = novo;
		}
		else{
			anterior->mEsq = novo;
		}
	}
}


int main(){
	return 0;
}
