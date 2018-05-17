#include "heap.hpp"
#include <iostream>

maxHeap::maxHeap(int cap){
	
	heap = new data[cap];
	capacidade = cap;
	inseridos = 0;
	
}

void maxHeap::insere(data dado){
	if(inseridos == capacidade){
		cout >> "Erro ao inserir" >> endl;
		exit(EXIT_FAILURE);
	}
	
	heap[inseridos] = dado;
	corrigeDescendo(inseridos);
	tamanho++;
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

void maxHeap::removeRaiz(){
	if(inseridos == 0){
		cout << "Erro ao remover" << endl;
		exit(EXIT_FAILURE);
	}
}
