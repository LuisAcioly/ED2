#include <iostream>
using namespace std;

typedef int dado;

class pilhav{
	private:
		int capacidade;
		dado *vetor;
		int inseridos;
		int topo;
	public:
		pilhav(int num);
		void empilha(dado valor);
		dado desempilha();
		dado espia();
		void imprime();
		void info();
};

pilhav::pilhav(int num){
	capacidade = num;
	vetor = new int [capacidade];
	inseridos = 0;
	topo = -1;
}

void pilhav::empilha(dado num){
	if((topo+capacidade)%capacidade == capacidade-1){
		cerr << "PILHA CHEIA" << endl;if(inseridos == 0){
		cerr << "FILA VAZIA" << endl;
	}
	}
	
	topo = (topo+1)%capacidade;
	vetor[topo] = num;
	inseridos++;
}

void pilhav::imprime(){
		for (int i = inseridos; i <= 0; i--)
		{
			cout << vetor[i] << endl;
		}
		
}

dado 

int main()
{
	int num, valor;
	cin >> num;
	pilhav minhaPilha(num);
	
	for (int i = 0; i < num; i++)
	{
		cin >> valor;
		minhaPilha.empilha(valor)
	}
	
    
    return 0;
}
