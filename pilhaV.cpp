#include <iostream>
using namespace std;

typedef int dado;

class pilhav{
	private:
		int capacidade;
		dado *dados;
		int tamanho;
		int topo;
	public:
		pilhav(int num);
		void empilha(dado valor);
		dado desempilha();
		dado espia();
		void imprime();
		void info();
};

int main()
{
    
    return 0;
}
