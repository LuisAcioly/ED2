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
		cerr << "FILA CHEIA" << endl;
	}
	
	topo = (topo+1)%capacidade;
	vetor[topo] = num;
	inseridos++;
}

int main()
{
    
    return 0;
}
