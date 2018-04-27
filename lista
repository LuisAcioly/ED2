#include <iostream>

using namespace std;

typedef int dados;

class noh {
	friend class lista;
	private:
		dados dado;	
		noh* proximo;
		noh* anterior;
	public:
		noh(dados d = 0);
};

noh::noh(dados d){
	dado = d;
	proximo = NULL;
	anterior = NULL;
}

class lista{
	private:
		noh* primeiro;
		noh* ultimo;
		int _tamanho;
		void imprimeReversoAux(noh* atual);
		
	public:
		lista();
		lista (const lista& copiaLista);
		lista& operator=(const lista &outraLista);
		lista& operator+(const lista &outraLista);
		lista& operator-(lista &outraLista);
		lista (dados vetor[], dados tam);
		void insereInicio(dados dado);
		void insereFim(dados dado);
		void inserePosicao(dados posicao, dados dado);
		void imprime();
		void remove(dados posicao);
		void procura(dados valor);
		void imprimeReverso();
		void troca(dados pos1, dados pos2);
		void removeTodos();
		void ordena();
		noh* acessaPos(dados pos);
		void removeRepetido();
		void divide(dados n, lista& outraLista);
		void inverte();
		 
};

lista::lista(){
	primeiro = NULL;
	ultimo = NULL;
	_tamanho = 0;
}
lista::lista(dados vetor[], dados tam){
	primeiro = NULL;
	ultimo = NULL;
	_tamanho = 0;
	
	for (int i = 0; i < tam; i++){
		insereFim(vetor[i]);
	}
	
}
lista::lista(const lista& copiaLista){
	primeiro = NULL;
	ultimo = NULL;
	_tamanho = 0;
	
	noh* aux = copiaLista.primeiro;
	
	while(aux != NULL){
		insereFim(aux->dado);
		aux = aux->proximo;
	}
}

noh* lista::acessaPos(dados pos){
	noh* aux;
	
	dados posAux = 0;
	
	if(pos == 0){
		aux = primeiro;
		return aux;
	}
	
	if(pos == _tamanho-1){
		aux = ultimo;
		return aux;
	}
	
	else{
		aux = primeiro;
		while(posAux != pos){
			aux = aux->proximo;
			posAux++;
		}
		
		return aux;
	}
}

lista& lista::operator=(const lista &outraLista){
	removeTodos();
	dados posAux = 0;
	noh* aux = outraLista.primeiro;
	
	while(posAux < outraLista._tamanho){
		insereFim(aux->dado);
		aux = aux->proximo;
		posAux++;
	}
	
	return *this;
}
lista& lista::operator + (const lista &outraLista){
	noh* aux = outraLista.primeiro;
	dados posAux = 0;
	
	while(posAux < outraLista._tamanho){
		insereFim(aux->dado);
		aux = aux->proximo;
		posAux++;
	}
	
	return *this;
}
lista& lista::operator -(lista& outraLista){
	noh* aux;
	noh* aux2;
	
	for (dados i = 0; i < _tamanho; i++){
		for (dados j = 0; j < _tamanho; j++)
		{
			aux = outraLista.acessaPos(i);
			aux2 = outraLista.acessaPos(j);
			if(aux->dado == aux2->dado){
				remove(i);
			}
		}
	}
	return *this;
}

void lista::divide(dados n, lista& outraLista){
	noh* aux;
	dados posAux = n+1;
	
	aux = outraLista.acessaPos(n+1);
	while(posAux < outraLista._tamanho){
		insereFim(aux->dado);
		aux = aux->proximo;
		posAux++;
	}
	
	posAux = n+1;
	aux = outraLista.acessaPos(n+1);
	
	while(aux != NULL){
		outraLista.remove(posAux);
		aux = aux->proximo;
	}

}

void lista::removeTodos(){
	dados posAux = 0;
	
	while(posAux < _tamanho){
		remove(posAux);
	}
	
}
void lista::ordena(){
	noh* aux;

	cout << endl;
	
	bool ordenou = true;
	
	while(ordenou){
		ordenou = false;
		for (int i = 0; i < _tamanho-1; i++)
		{
			aux = acessaPos(i);
			if(aux->dado > aux->proximo->dado){
				troca(i, i+1);
				ordenou = true;
			}
		}
		
	}

}

void lista::inverte(){

	int posAux1 = 0, posAux2 = _tamanho-1;
	
	while(posAux1 <= posAux2){
		troca(posAux1, posAux2);
		posAux1++;
		posAux2--;
	}
	
}

void lista::removeRepetido(){
	noh* aux;
	noh* aux2;
	
	for (int i = 0; i < _tamanho; i++)
	{
		for (int j = i+1; j < _tamanho; j++)
		{
			aux = acessaPos(i);
			aux2 = acessaPos(j);
			if(aux->dado == aux2->dado){
				remove(i);
			}
		}
		
	}
	
}


void lista::insereInicio(dados dado){
	noh* novo = new noh(dado);
	
	if(primeiro == NULL){
		primeiro = novo;
		ultimo = novo;
	}
	else{
		primeiro->anterior = novo;
		novo->proximo = primeiro;
		primeiro = novo;
	}
	_tamanho++;
}
void lista::insereFim(dados dado){
	noh* novo = new noh(dado);
	
	if(primeiro == NULL){
		primeiro = novo;
		ultimo = novo;
	}
	else{
		novo->anterior = ultimo;
		ultimo->proximo = novo;
		ultimo = novo;
	}
	_tamanho++;
}
void lista::inserePosicao(dados posicao, dados dado){
	noh* novo = new noh(dado);
	
	if(primeiro == NULL){
		primeiro = novo;
		ultimo = novo;
	}
	else if(posicao == 0 ){
		primeiro->anterior = novo;
		novo->proximo = primeiro;
		primeiro = novo;
	}
	
	else if(posicao == _tamanho){
		novo->anterior = ultimo;
		ultimo->proximo = novo;
		ultimo = novo;
	}
	else{
		noh* aux = primeiro;
		int posAux = 0;
		
		while(posAux < posicao-1){
			aux = aux->proximo;
			posAux++;
		}
		novo->anterior = aux;
		novo->proximo = aux->proximo;
		aux->proximo = novo;
	}
	_tamanho++;
}

void lista::imprime(){
	noh* aux = primeiro;
	while(aux != NULL){
		cout << aux->dado;
		aux = aux->proximo;
	}
}

void lista::imprimeReverso(){
	noh* atual = ultimo;
	
	while(atual != NULL) {
		cout << atual->dado << "  ";
		atual = atual->anterior;
	}
	//imprimeReversoAux(primeiro);
}

void lista::imprimeReversoAux(noh* atual){
	if(atual == NULL){
		return;
	}
	else{
		imprimeReversoAux(atual->proximo);
		cout << atual->dado << " ";
	}
}

void lista::troca(dados pos1, dados pos2){
	noh* auxPrimeiro;
	noh* auxProxPrimeiro;
	noh* auxUltimo;
	noh* auxPenUltimo;

	
	dados posAux = 0;
		
		if((pos1 == 0) and (pos2 == _tamanho-1)){
			auxPrimeiro = primeiro;
			auxProxPrimeiro = primeiro->proximo;
			auxUltimo = ultimo;
			auxPenUltimo = ultimo->anterior;
			auxPrimeiro->proximo = NULL;
			auxPrimeiro->anterior = auxPenUltimo;
			auxPrimeiro->anterior->proximo = auxPrimeiro;
			auxUltimo->proximo = auxProxPrimeiro;
			auxUltimo->anterior = NULL;
			auxUltimo->proximo->anterior = auxUltimo;
			ultimo = auxPrimeiro;
			primeiro = auxUltimo;
		}
		else if(pos1 == pos2-1){
		auxPrimeiro = primeiro;
		auxUltimo = primeiro;
			if(pos1 == 0){
				while(posAux != pos2){
					auxUltimo = auxUltimo->proximo;
					posAux++;
				}
				auxPrimeiro->proximo = auxUltimo->proximo;
				auxPrimeiro->anterior = auxUltimo;
				auxUltimo->anterior = NULL;
				auxUltimo->proximo = auxPrimeiro;
				auxPrimeiro->proximo->anterior = auxPrimeiro;
				
				primeiro = auxUltimo;
				
			}
			
			else if(pos2 == _tamanho-1){
				while(posAux != pos1){
					auxPrimeiro = auxPrimeiro->proximo;
					posAux++;
				}
				auxUltimo = ultimo;
				auxUltimo->proximo = auxPrimeiro;
				auxPrimeiro->proximo = NULL;
				auxUltimo->anterior = auxPrimeiro->anterior;
				auxPrimeiro->anterior = auxUltimo;
				auxUltimo->anterior->proximo = auxUltimo;
				  
					
				ultimo = auxPrimeiro;
				
			}
			else{
				while(posAux != pos1){
					auxPrimeiro = auxPrimeiro->proximo;
					posAux++;
				}
				posAux = 0;
				while(posAux != pos2){
					auxUltimo = auxUltimo->proximo;
					posAux++;
				}
				auxPrimeiro->proximo = auxUltimo->proximo;
				auxPrimeiro->proximo->anterior = auxPrimeiro;
				auxUltimo->anterior = auxPrimeiro->anterior;
				auxUltimo->anterior->proximo = auxUltimo;
				auxUltimo->proximo = auxPrimeiro;
				auxPrimeiro->anterior = auxUltimo;
			}
			
		}
		else{
			auxPrimeiro = primeiro;
			auxUltimo = primeiro;
			if(pos1 == 0){
				while(posAux != pos2){
					auxUltimo = auxUltimo->proximo;
					posAux++;
				}
				auxProxPrimeiro = auxPrimeiro->proximo;
				auxPrimeiro->proximo = auxUltimo->proximo;
				auxPrimeiro->proximo->anterior = auxPrimeiro;
				auxPrimeiro->anterior = auxUltimo->anterior;
				auxPrimeiro->anterior->proximo = auxPrimeiro;
				auxUltimo->anterior = NULL;
				auxUltimo->proximo = auxProxPrimeiro;
				auxUltimo->proximo->anterior = auxUltimo;
				
				primeiro = auxUltimo;
				
			}
			else if(pos2 == _tamanho-1){
				while(posAux != pos1){
					auxPrimeiro = auxPrimeiro->proximo;
					posAux++;
				}
				auxUltimo = ultimo;
				auxProxPrimeiro = auxPrimeiro->anterior;
				auxUltimo->proximo = auxPrimeiro->proximo;
				auxPrimeiro->proximo = NULL;
				auxUltimo->proximo->anterior = auxUltimo;
				auxPrimeiro->anterior = auxUltimo->anterior;
				auxPrimeiro->anterior->proximo = auxPrimeiro;
				auxUltimo->anterior = auxProxPrimeiro;
				auxUltimo->anterior->proximo = auxUltimo;
				
				
				ultimo = auxPrimeiro;
		
			}
			else{
				while(posAux != pos1){
					auxPrimeiro = auxPrimeiro->proximo;
					posAux++;
				}
				posAux = 0;
				while(posAux != pos2){
					auxUltimo = auxUltimo->proximo;
					posAux++;
				}
				
				auxProxPrimeiro = auxPrimeiro->proximo;
				auxPenUltimo = auxUltimo->anterior;
				auxPrimeiro->proximo = auxUltimo->proximo;
				auxPrimeiro->proximo->anterior = auxPrimeiro;
				auxUltimo->proximo = auxProxPrimeiro;
				auxUltimo->proximo->anterior = auxUltimo;
				auxUltimo->anterior = auxPrimeiro->anterior;
				auxUltimo->anterior->proximo = auxUltimo;
				auxPrimeiro->anterior = auxPenUltimo;
				auxPrimeiro->anterior->proximo = auxPrimeiro;
				
			}
		
		}
}


void lista::remove(dados posicao){
	noh* aux, *remover;
	
	aux = acessaPos(posicao);

	if(posicao == 0){
		aux->proximo->anterior = NULL;
		primeiro = aux->proximo;
		delete aux;
	}
	else if(posicao == _tamanho-1){
			 aux = acessaPos(posicao-1);
			 remover = aux->proximo;
			 aux->proximo = NULL;
			 ultimo = aux;
			 delete remover;
			 
	}
	else{
		aux->anterior->proximo = aux->proximo;
		aux->proximo->anterior = aux->anterior;
		delete aux;
	}
		
	_tamanho--;
}

void lista::procura(dados valor){
	noh* aux = primeiro;
	dados posAux = 0;
	while(aux->dado != valor){
		aux = aux->proximo;
		posAux++;
	}
	cout << posAux;
}

int main(){
	int num, dado, pos, pos2, vetor[5];
	lista novaLista;
	lista Lista2;
	
	cin >> num;
	
	for (int i = 0; i < num; i++){
		cin >> dado;
		novaLista.insereFim(dado);
	}
	
	lista listaCopiada(novaLista);
	
	//novaLista + novaLista;
	
	//~ novaLista.imprime();
	
	//cout << endl;
	
	//cin >> pos;
	//cin >> dado;
	
	//novaLista.inserePosicao(pos, dado);
	
	//novaLista.imprime();
	
	//cout << endl;
	
	//cin >> pos;
	
	//novaLista.remove(pos);
	
	//novaLista.imprime();
	
	//cout << endl;
	
	//cin >> dado;
	
	//novaLista.procura(dado);
	
	//cout << endl;
	
	//novaLista.imprimeReverso();
	
	//cout << endl;
	
	//novaLista.troca();
	
	//cout << endl;
	
	//novaLista.imprime();
	
	//cin >> pos >> pos2;
	
	//novaLista.troca(pos, pos2);


	//cout << endl;
	
	
	//novaLista.imprime();
	
	//cout << endl;
	
	//Lista2 = novaLista;
	
	//novaLista.ordena();
	
	//cout << endl;
	
	//novaLista.removeRepetido();
	
	//cout << endl;
	
	//novaLista.imprime();


	//~ Lista2.divide(3, novaLista);
	
	//~ cout << endl;
	
	//~ Lista2.imprime();
	
	//~ cout << endl;
	
	//~ novaLista.imprime();
	
	//~ cout << endl;

	//~ novaLista.remove(3);
	
	novaLista.inverte();
	
	 novaLista.imprime();
}
 
