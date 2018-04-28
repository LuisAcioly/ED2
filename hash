
#include <iostream>
using namespace std;


int funcaoHash(string xave, int tam){
	int primo = 13;
	long posicao = 0;
	
	for (unsigned int i = 0; i < xave.length(); i++)
	{
		posicao = (primo*posicao + xave[i])%tam;
	}
	
	return posicao;
}

class noh{
	friend class hash;
	
	public:
		
		noh();
		
	private:
	
		string chave;
		string valor;
		noh *proximo;
};

class hash{
	public:
		hash(int tamanho);
		void insere(string xave, string dado);
		bool existe(string xave);
		void remove(string xave);
		void imprime();
	private:
		int capacidade;
		noh **vetor;
};

noh::noh(){
	proximo = NULL;
}

hash::hash(int tamanho){
	this->capacidade = tamanho;
	this->vetor = new noh*[capacidade];
	
	for (int i = 0; i < capacidade; i++)
	{
		vetor[i] = NULL;
	}
	 
}
void  hash::remove(string xave){
		int posicao = funcaoHash(xave, capacidade);
		
		if(existe(xave) == true){
			if(vetor[posicao]->proximo == NULL and vetor[posicao]->chave == xave){
				vetor[posicao] = NULL;
			}
			else{
				noh* aux = vetor[posicao];
				noh* aux2;
				
				while(aux != NULL and aux->chave != xave){
					aux2 = aux;
					aux = aux->proximo;
				}
				
				if(aux->proximo == NULL) {
					delete aux;
				}
				else{
					aux2->proximo = NULL;
					delete aux;
				}
					
			}
			
			
		}
}

bool hash::existe(string xave){
	int posicao = funcaoHash(xave, capacidade);
	
		if(vetor[posicao] != NULL and vetor[posicao]->chave == xave){
			return true;
		}
		
		else if(vetor[posicao] != NULL and vetor[posicao]->chave != xave){
			noh* aux = vetor[posicao];
			
			while(aux != NULL){
				if(vetor[posicao]->chave == xave){
					return true;
				}
				
				aux = aux->proximo;
			}
		}
			return false;
}

void altera

void hash::insere(string xave, string dado){
	int posicao;
	
	posicao = funcaoHash(xave, capacidade);
	
	if(existe(xave) == false){
		
		if(vetor[posicao] == NULL){
			vetor[posicao] = new noh;
			vetor[posicao]->chave = xave;
			vetor[posicao]->valor = dado;
		}
		else if(vetor[posicao] != NULL){
			noh* aux = vetor[posicao];
			
			while(aux != NULL){
				aux = aux->proximo;
			}
			
			aux = new noh;
			vetor[posicao]->proximo = aux;
			aux->chave = xave;
			aux->valor = dado;
		}
		else{
			cout << "CHAVE EXISTENTE FILHO DA PUTA!" <<	endl;
		}
	}
}

void hash::imprime(){
	
	
	for (int i = 0; i < capacidade; i++)
	{
		noh* aux = vetor[i];
		
		while(aux != NULL){
			cout << aux->valor << " ";
			aux = aux->proximo;
			
			if(aux == NULL){
				cout << endl;
			}
		}
		if(vetor[i] == NULL){
			cout << "["<< i << "]" << endl;
		}
		
	}
	
}

int main()
{
    int tamanho = 5;
    
    
    hash tabela(tamanho);
    
    
    tabela.insere("Luis", "Gostoso");
    tabela.insere("GUi", "Viado");
    
    tabela.remove("GUi");
    tabela.remove("Luis");
    
    tabela.imprime();
    return 0;
}
