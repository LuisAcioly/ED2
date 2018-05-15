#include <iostream>
using namespace std;

typedef int dado;

class noh{
	friend class calculadora;
	private :
		char valor;
		noh* proximo;
	public :
		noh();
};

noh::noh(){
	valor = '0';
	proximo = NULL;
}

class calculadora{
	private:
		noh* topo;
		int _tamanho;
	public:
		calculadora(int tam = 0);
		void empilha(char num);
		char desempilha();
		void reempilha(calculadora temporario);
		void imprime();
		void calculo();
};

calculadora::calculadora(int tam){
	topo = NULL;
	_tamanho = tam;
}

void calculadora::empilha(char num){
	noh* aux = new noh;
	
	aux->valor = num;
	aux->proximo = topo;
	topo = aux;
	_tamanho++;
	
}

void calculadora::reempilha(calculadora temporario){
	for (int i = 4; i >= 0; i--)
	{
		empilha(temporario.desempilha());
	}
}

char calculadora::desempilha(){
	noh* aux;
	char removido;
	
	if(_tamanho == 1){
		removido = topo->valor;
		aux = topo;
		topo = NULL;
		delete aux;
		_tamanho = 0;
	}
	else{
		removido = topo->valor;
		aux = topo;
		topo = topo->proximo;
		delete aux;
		_tamanho--;
	}
	return removido;
	
}

void calculadora::imprime(){

	
	for (int i = 0; i < 5; i++)
	{
		cout << topo->valor << endl;
		desempilha();
	}
	
}

void calculadora::calculo(){
	int result, num, tam = _tamanho;
	
	result = desempilha() - 48;
	
	for(int i = 0; i < tam; i++){
		cout << _tamanho << "tamanho" << endl;
		
		if(topo->valor == '+'){
			result = result + num;
			cout << result  << endl;
		}
		if(topo->valor == '-'){
			result = result - num;
		}
		if(topo->valor == '*'){
			result = result * num;
		}
		if(topo->valor == '/'){
			result = result / num;
		}
		else{
			num = desempilha() - 48;
			
		}
	}
}

int main()
{
	char num;
	
	calculadora pilhaTemp;
	calculadora pilhaCal;
    
    for (int i = 0; i < 5; i++)
	{
		cin >> num;
		pilhaTemp.empilha(num);
	}
	
	pilhaCal.reempilha(pilhaTemp);
	pilhaCal.calculo();
	
    
    return 0;
}
