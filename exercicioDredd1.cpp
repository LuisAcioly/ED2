#include <iostream>
#include <cstdlib>

using namespace std;

typedef int Dado;

class noh {
    friend class lista;
    private:
        const Dado dado;
        noh* proximo;
    public:
        noh(Dado d = 0);
};

noh::noh(Dado d) : dado(d) {
    proximo = NULL;
}

class lista {
    private:
        noh* primeiro;
        noh* ultimo;
        int tamanho;
    public:
        lista();
        ~lista();
        void insere(Dado dado);
        void insere(Dado dado, int pos);
        void remove(int posicao);
        int procura(Dado valor);
        void imprime();
        inline bool vazia();
};

// constrÃ³i uma lista inicialmente vazia
lista::lista() {
    tamanho = 0;
    primeiro = NULL;
    ultimo = NULL;
}

lista::~lista() {
    noh* iter = primeiro;
    noh* proximo = NULL;
    while (iter != NULL) {
        proximo = iter->proximo;
        delete iter;
        iter = proximo;
    }
}

// mÃ©todo bÃ¡sico que *percorre* a lista, imprimindo seus elementos
void lista::imprime() {
    noh* aux = primeiro;
    while (aux != NULL) {
        cout << aux->dado << " ";
        aux = aux->proximo;
    }
    cout << endl;
}

// insere por padrÃ£o no final da lista
void lista::insere(Dado dado) {
    noh* novo = new noh(dado);

    if(tamanho == 0){
        primeiro = novo;
        ultimo = novo;
    }
    else{
        ultimo->proximo = novo;
        ultimo = novo;
    }

    tamanho++;
}

// insere um dado em uma determinada posiÃ§Ã£o da lista
void lista::insere(Dado dado, int posicao) {
    noh* novo = new noh(dado);
    noh* aux = primeiro;
    int i = 0;
	if(posicao >= 0 && posicao < tamanho){	
		if(tamanho == 0){
			primeiro = novo;
			ultimo = novo;
		}
		else{
			while(i != posicao-1){
				aux = aux->proximo;
				i++;
			}

			novo->proximo = aux->proximo;
			aux->proximo = novo;
			
		}
	}

    tamanho++;
}

// remove o item da posiÃ§Ã£o passada por parÃ¢metro
// AtenÃ§Ã£o - o cÃ³digo deve tratar de posiÃ§Ã£o invÃ¡lidas
void lista::remove(int posicao) {
    noh* aux = primeiro;
    noh* removido;
    int i = 0;
     
    if(posicao >= 0 && posicao < tamanho){
		 if(posicao == 0){
			primeiro = primeiro->proximo;
			delete aux;
		 }
		 else if(posicao == tamanho-1){
			 while(i != tamanho-2){
				 aux = aux->proximo;
				 i++;
			 }
			 removido = ultimo;
			 ultimo = aux;
			 ultimo->proximo = NULL;
			 delete removido;
		 }
		 else{
			 while(i != posicao-1){
				aux = aux->proximo;
				i++;
			}
			
			removido = aux->proximo;
			aux->proximo = removido->proximo;
			delete removido;
			
		 }
		 
	 }
	 
	 tamanho--;
    
}

// procura por um elemento e retorna a posiÃ§Ã£o ou -1 se nÃ£o encontrado
int lista::procura(Dado valor) {
    noh* aux = primeiro;
    int i = 0;
    while(aux != NULL){
       if(aux->dado == valor){
           return i;
       }
       else{
            aux = aux->proximo;
            i++;
       }
    }
    
    return -1;
}

// verifica se a lista estÃ¡ vazia
inline bool lista::vazia() {
   return (primeiro == NULL);
}

int main() { // NÃƒO MODIFIQUE!
    lista minhaLista;
    char opcao;
    int valor, pos;
    cin >> opcao;
    while (opcao != 'Q') {
        switch(opcao) {
            case 'I':
                cin >> valor;
                minhaLista.insere(valor);
                break;
            case 'W':
                cin >> valor;
                cin >> pos;
                minhaLista.insere(valor, pos);
                break;
            case 'P':
                cin >> valor;
                cout << minhaLista.procura(valor) << endl;
                break;
            case 'R':
                cin >> pos;
                minhaLista.remove(pos);
                break;
            case 'V':
                cout << minhaLista.vazia() << endl;
                break;
        }
        cin >> opcao;
    }
    minhaLista.imprime();
    return 0;
}

