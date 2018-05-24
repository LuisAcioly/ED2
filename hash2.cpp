#include <iostream>
using namespace std;

typedef int data;

int funcaoHash(data dado, int tam){
	return dado%tam;
}

class noh{
	friend class hash;
	private:
		noh* proximo;
		data valor;
	public:
		noh(data num = 0);
};

noh::noh(data num){
	proximo = NULL;
	valor = num;
}

class hash{
	private:
		int capacidade;
		noh** tabelaHash;
	public:
		hash(int cap = 5);
		void insere(data dado);
		void imprime();
		void remove(data dado);
};

hash::hash(int cap){
	capacidade = cap;
	tabelaHash = new noh*[capacidade];
}

void hash::insere(data dado){
	
	noh* novo = new noh(dado);
	
	int posicao;
	
	posicao = funcaoHash(dado, capacidade);
	
	if(tabelaHash[posicao] == NULL){
		tabelaHash[posicao]= novo;
	}
	
	 else if(tabelaHash[posicao] != NULL){
		noh* aux = tabelaHash[posicao];
		
		while(aux->proximo != NULL){
			aux = aux->proximo;
		}
		aux->proximo = novo;
	}
}

void hash::imprime(){
	
	for (int i = 0; i < capacidade; i++)
	{
		noh* aux = tabelaHash[i];
		while(aux != NULL){
			cout << aux->valor << " ";
			aux = aux->proximo;
			
			if(aux == NULL){
				cout << endl;
			}
		}
		
		if(tabelaHash[i] == NULL){
			cout << "[]" << endl;
		}
	}
	
	
}

void hash::remove(data dado){
	int posicao;
	
	posicao = funcaoHash(dado, capacidade);
	noh* aux = tabelaHash[posicao];
	
	if(tabelaHash[posicao]->valor == dado){
		tabelaHash[posicao] = tabelaHash[posicao]->proximo;
		delete aux;
	}
	else if(tabelaHash[posicao]->valor != dado and tabelaHash[posicao] != NULL){
		noh* aux2;
		while(aux->valor != dado){
			aux2 = aux;
			aux = aux->proximo;
		}
		if(aux->proximo == NULL){
			aux2->proximo = NULL;
			delete aux;
		}
		else{
			aux2->proximo = aux->proximo;
			delete aux;
		}
	}
	else if(tabelaHash[posicao] == NULL){
		cout << "numero inexistente" << endl;
	}
	
}

int main()
{
    hash umaHash;
    
    umaHash.insere(11);
    umaHash.insere(26);
    umaHash.insere(36); 
    umaHash.insere(41);
    
    umaHash.imprime();
    
    cout << endl;
    
    umaHash.remove(41);
    
    umaHash.imprime();
    
    return 0;
}
