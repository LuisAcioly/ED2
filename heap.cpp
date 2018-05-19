#include "heap.hpp"
#include <iostream>
#include <cstdlib>

using namespace std;
maxHeap::maxHeap(int cap){
	
	heap = new data[cap];
	capacidade = cap;
	inseridos = 0;
	
}

void maxHeap::insere(data dado){
	if(inseridos == capacidade){
		cout << "Erro ao inserir" << endl;
		exit(EXIT_FAILURE);
	}
	
	heap[inseridos] = dado;
	corrigeSubindo(inseridos);
	inseridos++;
}
void maxHeap::inserePos(data dado, int i){
	if(inseridos == capacidade){
		cout << "Erro ao inserir" << endl;
		exit(EXIT_FAILURE);
	}
	
	heap[i] = dado;
	inseridos++;
}

void maxHeap::corrigeSubindo(int i){
	int p = pai(i);
	
	if(heap[i] > heap[p]){
		swap(heap[i], heap[p]);
		corrigeSubindo(p);
	}
}

int maxHeap::pai(int i){
	return (i-1)/2;
}
int maxHeap::esquerdo(int i){
	return i*2+1;
}
int maxHeap::direito(int i){
	return i*2+2;
}

data maxHeap::removeRaiz(){
	if(inseridos == 0){
		cout << "Erro ao remover" << endl;
		exit(EXIT_FAILURE);
	}
	int aux = heap[0];
	swap(heap[0], heap[inseridos-1]);
	inseridos--;
	corrigeDescendo(0);
	return aux;
}

void maxHeap::corrigeDescendo(int i){
	int esq = esquerdo(i);
	int dir = direito(i);
	int maior;
	
	if(esq < inseridos and heap[esq] > heap[i]){
		maior = esq;
	}
	else{
		maior = i;
	}
	
	if(dir < inseridos and heap[dir] > heap[maior]){
		maior = dir;
	}
	
	if(maior != i){
		swap(heap[i], heap[maior]);
		corrigeDescendo(maior);
	}
}

data maxHeap::espiaRaiz(){
	return heap[0];
}

void maxHeap::imprime(){
	arruma();
	
	for (int i = 0; i < capacidade; i++)
	{
		cout << "[" << heap[i] << "]";
	}
	cout << endl;
}

void maxHeap::arruma(){
	for (int i = inseridos/2-1; i >= 0; i--)
	{
		corrigeDescendo(i);
	}
	
}
void maxHeap::torneio(){
	int esq, dir,maior;
	for (int i = capacidade/2-1; i >= 0; i--)
	{
		esq = esquerdo(i);
		dir = direito(i);
		maior = i;
		if(heap[esq] > heap[dir]){
			maior = esq;
		}
		else{
			maior = dir;
		}
		heap[i] = heap[maior];
	}
	
}

void maxHeap::insereTAD(data vetor[], int tam){
	int aux, j;
	aux = (capacidade-1)-(tam-1);
	j = 0;
	for (int i = aux; i < capacidade; i++)
	{
		inserePos(vetor[j], i);
		j++;
	}
	
}

void maxHeap::heapsort(){
	while(inseridos != 1){
			swap(heap[0], heap[inseridos-1]);
			inseridos--;
			corrigeDescendo(0);
	}
}
