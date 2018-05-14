#include <iostream>
using namespace std;

typedef int Dado;
class noh{
	friend class fila;
	private:
		Dado dado;
		noh* proximo;
	public:
		noh(Dado num);
};

noh::noh(Dado num){
	dado = num;
	proximo = NULL;
}


class fila{
	private: 
		noh* inicio;
		noh* fim;
		int tamanho;
	public:
		fila();
		void enfileira(Dado valor);
		int desenfileira();
		void imprime();
		bool vazia();
		void reenfileira(fila umaFila);
		void empilhando(int tam);
};

fila::fila(){
	inicio = NULL;
	fim = NULL;
	tamanho = 0;
}

void fila::enfileira(Dado valor){
	noh* aux = new noh(valor);
	
	
	if(inicio == NULL){
		inicio = aux;
		fim = aux;
	}
	
	else{
		fim->proximo = aux;
		fim = aux;
	}
	
	tamanho++;
}

int fila::desenfileira(){
	noh* aux = inicio;
	int removido = inicio->dado;
	
	inicio = inicio->proximo;
	
	delete aux;
	
	tamanho--;
	
	return removido;
	
}
void fila::empilhando(int tam){
	fila umaFila;
	noh* aux = inicio;
	
		while(inicio != fim){
			while(aux->proximo != fim){
				aux = aux->proximo;
			}
				cout << endl;
				umaFila.enfileira(fim->dado);
				fim = aux;
				delete aux->proximo;
				aux = inicio;
				tamanho--;	
		}
		
		umaFila.enfileira(inicio->dado);
		inicio = NULL;
		fim = NULL;
			
		umaFila.imprime();
}

bool fila::vazia(){
	return (inicio == NULL);
}



void fila::imprime(){
	
	fila umaFila;
	
	noh* aux = inicio;
	
	
		while(aux != NULL){
			cout << aux->dado << endl;
			aux = aux->proximo;
		}
	
	
}

int main()
{
    fila novaFila;
    
    Dado valor, tam;  
    
    cin >> tam;
    
    for (int i = 0; i < tam; i++)
	{
		cin >> valor;
		novaFila.enfileira(valor);
	}
	
	cout << endl;
	
	novaFila.imprime();
	
	cout << endl;
	
	novaFila.empilhando(tam);
	
	
    return 0;
}

