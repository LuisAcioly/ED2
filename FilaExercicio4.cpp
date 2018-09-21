#include <iostream>

typedef int Dado;

class Fila {
    public:
        Fila(unsigned cap = 80);
        ~Fila();
        // Remove e retorna o primeiro elemento da fila.
        Dado Desenfileira();
        // Insere um valor na fila. Retorna um booleano que informa se a inserção foi realmente
        // realizada.
        bool Enfileirar(const Dado& valor);
        // Escreve todo o conteúdo do armazenamento da fila na saída de dados.
        void EscreverConteudo(std::ostream& saida) const;
        // Retorna tamanho, capacidade, inicio e fim da fila.
        void Info(unsigned* ptTam, unsigned* ptCap, unsigned* ptIni, unsigned* ptFim) const;
        // Retorna o primeiro elemento da fila, sem removê-lo.
        Dado Proximo() const;
        // Retorna a quantidade de elementos na fila.
        unsigned Tamanho() const { return mTamanho; }
        // Consulta se a fila está vazia.
        bool Vazia() const;
    protected:
        unsigned mCapacidade;
        Dado* mDados;
        unsigned mPosInicio; // indica a posicao do primeiro
        unsigned mPosFim;    // indica a posicao do ultimo
        unsigned mTamanho;
};

using namespace std;

Fila::Fila(unsigned cap) { // cap tem valor default
	mCapacidade = cap;
	mDados = new Dado[cap];
	mPosInicio = -1;
	mPosFim = -1;
	mTamanho = 0;
}

Fila::~Fila() {
}
 
// Remove e retorna o primeiro elemento da fila.
Dado Fila::Desenfileira() {
	if(Vazia()){
		cerr << "Fila Vazia!" << endl;
		return -1;
	}
	else{
		Dado removido = mDados[mPosInicio];;
		if(mPosInicio == mPosFim){
			mPosInicio = -1;
			mPosFim = -1;
		}
		else{
			mPosInicio = (mPosInicio+1)%mCapacidade;
		}
		mTamanho--;
		return removido;
	}
}

// Insere um valor na fila. Retorna um booleano que informa se a inserção foi realmente realizada.
bool Fila::Enfileirar(const Dado& valor) {
	if((mPosFim+mCapacidade-mPosInicio)%mCapacidade == mCapacidade-1){
		return false;
	}
	else{
		if(mTamanho == 0){
			mPosInicio++;
		}
			
		mPosFim = (mPosFim+1)%mCapacidade;
		mDados[mPosFim] = valor;

		mTamanho++;
		return true;
	}
}

// Escreve todo o conteúdo do armazenamento (começando da posição zero) da fila na saída de dados.
void Fila::EscreverConteudo(ostream& saida) const {
	cout << mPosInicio << endl;
	cout << mPosFim << endl;
	for (unsigned i = mPosInicio; i < mPosFim+1 ; i++)
	{
		saida << mDados[i] << " ";
	}
	saida << endl;
}

// Retorna tamanho, capacidade, inicio e fim da fila.
void Fila::Info(unsigned* ptTam, unsigned* ptCap, unsigned* ptIni, unsigned* ptFim) const {
	*ptTam = this->mTamanho;
	*ptCap = this->mCapacidade;
	*ptIni = this->mPosInicio;
	*ptFim = this->mPosFim;
}

// Retorna o primeiro elemento da fila, sem removê-lo.
Dado Fila::Proximo() const {
	return mDados[mPosInicio];
}

// Consulta se a fila está vazia.
bool Fila::Vazia() const {
	if(mTamanho == 0){
		return true;
	}
	else{
		return false;
	}
}

int main() {
    unsigned tamanho, capacidade, inicio, fim;
    cin >> capacidade;
    Fila fila(capacidade);
    Dado valor;
    char comando;
    cin >> comando;
    while (comando != 't') {
        switch (comando) {
        case 'e': // enfileirar
            cin >> valor;
            if (not fila.Enfileirar(valor))
                cout << "FILA CHEIA!\n";
            break;
        case 'd': // desenfileirar
            if (fila.Vazia())
                cout << "ERRO\n";
            else {
                valor = fila.Desenfileira();
                cout << valor << endl;
            }
            break;
        case 'p': // proximo
            if (fila.Vazia())
                cout << "ERRO\n";
            else
                cout << fila.Proximo() << endl;
            break;
        case 'i': // informações sobre a fila
            fila.Info(&tamanho, &capacidade, &inicio, &fim);
            cout << "tamanho=" << tamanho << " capacidade=" << capacidade << " inicio=" << inicio
                 << " fim=" << fim << endl;
            fila.EscreverConteudo(cout);
            break;
        case 't':
            // vai testar novamente no while
            break;
        default:
            cout << "comando inválido\n";
        }
        cin >> comando;
    }
    return 0;
}
