#include <iostream>
using namespace std;

typedef int dados;
class fila{
	private: 
		int capacidade;
		dados* vetor;
		int inseridos;
		int inicio;
		int fim;
	public:
		fila(int tamanho = 5);
		void enfileira(int num);
		void info();
		dados desenfileira();
		dados espia();
		void depura();
};

fila::fila(int tamanho){
	capacidade = tamanho;
	vetor = new dados [capacidade];
	inicio = -1;
	fim = -1;
	inseridos = 0;
}
void fila::enfileira(int num){
	if((fim+capacidade-inicio)%capacidade == capacidade-1){
		cerr << "FILA CHEIA" << endl;
	}
	if(inicio == -1){
		inicio++;
	}
	
	fim = (fim+1)%capacidade;
	vetor[fim] = num;
	inseridos++;
}

dados fila::desenfileira(){
	if(inseridos == 0){
		cerr << "FILA VAZIA" << endl;
	}
	dados aux = vetor[inicio];
	if(inicio == fim){
		inicio = -1;
		fim = -1;
	}
	else{
		inicio = (inicio+1)%capacidade;
	}
	
	inseridos--;
	
	return aux;
}

dados fila::espia(){
		return vetor[inicio];
}

void fila::depura(){
	for (int i = inicio; i < fim+1; i++)
	{
		cout << vetor[i] << endl;
	}
	
}

void fila::info(){
	cout << "Inicio: " << vetor[inicio] << endl;
	cout << "Fim: " << vetor[fim] << endl;
	cout << "Tamanho: " << capacidade << endl;
	cout << "Inseridos: " << inseridos << endl;
}
int main()
{
    fila novaFila;
    
	dados num;
	
	for (int i = 0; i < 5; i++)
	{
		cin >> num;
		novaFila.enfileira(num);
	}
	
	cout << endl << novaFila.espia();
	
    return 0;
}

