#ifndef HEAP_HPP
#define HEAP_HPP

typedef int data;

class maxHeap{
	private: 
		data* heap;
		int capacidade;
		int inseridos;
		inline int pai (int i);
		inline int esquerdo (int i);
		inline int direito (int i);
		void arruma();
		void corrigeDescendo(int i);
		void corrigeSubindo(int i);
	public:
		maxHeap(int cap);
		maxHeap(data vetor[], int tam, int cap = 0);
		void imprime();
		void insere(data dado);
		inline data espiaRaiz();
		data removeRaiz();
		void heapsort();
};

#endif
