#include <iostream>
using namespace std;

typedef float Dado;

class noh {
  friend class listadup;
  private:
    const Dado dado;
    noh* proximo;
    noh* anterior;
  public:
    noh(Dado d = 0) : dado(d) {
      proximo = NULL;
      anterior = NULL;
    }
};

// lista dinamicamente encadeada
class listadup {
  private:
    noh* primeiro;
    noh* ultimo;
    int tamanho;
  public:
    listadup() {
      // constrói uma lista inicialmente vazia
      tamanho = 0;
      primeiro = NULL;
      ultimo = NULL;
    };
    ~listadup() {
      // destroi a lista
      noh* atual = primeiro;
      while (atual != NULL) {
        noh* aux = atual;
        atual = atual->proximo;
        delete aux;
      }
    };
    inline void insere(Dado dado) {
      cout << "insere" << endl;

      noh* novo = new noh(dado);

      if(primeiro == NULL){
          cout << "primeiro elemento" << endl;
          primeiro = novo;
          ultimo = novo;
      }
      else{
          cout << "demais elementos" << endl;
          ultimo->proximo = novo;
          cout << "teste 1" << endl;
          novo->anterior = ultimo;
          ultimo = novo;
      }

        tamanho++;
    };
    listadup* separa(int n) {
      cout << "separa" << endl;
      if(n >= 0 && n < tamanho){
          listadup* listaTemp;
          noh* aux;
          
          for(int i = 0; i < n; i++)
          {
            cout << "transferencia1" << endl;
            aux = primeiro;
            cout << "transferencia2" << endl;
            cout << primeiro->dado << endl;
            listaTemp->insere(primeiro->dado);
            cout << "transferencia3" << endl;
            primeiro = primeiro->proximo;
            cout << "transferencia4" << endl;
            primeiro->anterior = NULL;
            cout << "transferencia5" << endl;
            aux->proximo = NULL;
            cout << "transferencia6" << endl;
            aux->anterior = NULL;
            cout << "transferencia7" << endl;
            delete aux;
            cout << "transferencia8" << endl;
            tamanho--;
            cout << "tranferencia9" << endl;
          }
          return listaTemp;
      }
      else{

        cout << "erro!" << endl;
        
        return NULL;
      }
    };
    void imprime() {
      // método básico que *percorre* uma lista, imprimindo seus elementos
      noh* aux = primeiro;
      
      if (aux == NULL) {
        cout << "vazio!";
      } else {
        while (aux != NULL) {
          cout << aux->dado << " ";
          aux = aux->proximo;
        }
      }
      
      cout << " <> ";
      
      // imprime reverso (para mostrar duplo encadeamento)
      aux = ultimo;
      if (aux == NULL) {
        cout << "vazio!";
      } else {
        while (aux != NULL) {
          cout << aux->dado << " ";
          aux = aux->anterior;
        }
      }
      
      cout << endl;
    };
};


// NÃO MODIFICAR
int main() {
  listadup* minhaLista = new listadup;
  
  char opcao;
  float valor;

  do {
    cin >> opcao;

    switch(opcao) {
      case 'I':
        cin >> valor;
        minhaLista->insere(valor);
        break;
      case 'S':
        cin >> valor;
        listadup* outraLista = minhaLista->separa(valor);
        if (outraLista != NULL) {
          outraLista->imprime();
          delete outraLista;
        } 
        break;
    }
  } while (opcao != 'Q');

  minhaLista->imprime();
  
  delete minhaLista;

  return 0;
}
