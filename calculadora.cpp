#include <iostream>
using namespace std;

typedef int dado;

class calculadora{
	private:
		int capacidade;
		dado *vetor;
		char* operadores;
		int numerosInseridos;
		int operadoresInseridos;
		int topo;
	public:
		calculadora(int num);
		void empilha(dado valor);
		dado desempilha();
		dado espia();
		void imprime();
		void info();
};

calculadora::calculadora(int num){
	capacidade = 100;
	vetor = new int [capacidade];
	operadores = new char [capacidade];
	numerosInseridos = 0;
	operadoresInseridos = 0;
	topo1 = -1;
	topo2 = -1;
}

void calculadora::empilha(dado num){
	if((capacidade)%capacidade == capacidade-1){
		cerr << "PILHA CHEIA" << endl;
	}
	
	topo = (topo-1)%capacidade;
	vetor[topo] = num;
	numerosInseridos++;
}
void calculadora::empilhaOperador(char operador){
	if((capacidade)%capacidade == capacidade-1){
		cerr << "PILHA CHEIA" << endl;
	}
	
	topo = (topo-1)%capacidade;
	operadores[topo] = operador;
	operadoresInseridos++;
}

void calculadora::imprime(){
		for (int i = numerosInseridos; i <= 0; i--)
		{
			cout << vetor[i] << endl;
		}
		
}

dado calculadora::desempilha(){
	if(numerosInseridos == 0){
		cerr << "PILHA VAZIA" << endl;
	}
	
	dado aux = vetor[topo];
	
	if(topo == 0){
		topo = -1;
	}
	else{
		topo = (topo-1)%capacidade;
	}
	
	numerosInseridos--;
	
	return aux;
}

int main()
{
	int num, valor;
	cin >> num;
	calculadora minhaPilha(num);
	
	for (int i = 0; i < num; i++)
	{
		cin >> valor;
		minhaPilha.empilha(valor);
	}
	
    
    return 0;
}
