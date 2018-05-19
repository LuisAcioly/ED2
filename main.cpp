#include <iostream>
#include "heap.cpp"
using namespace std;

int main()
{
    data vetor[16] = {12, 4, 5, 8, 51, 45 , 24, 9, 11, 31, 13, 19, 17, 2, 7, 18};
    
    int tam = 16*2-1;
    
    maxHeap heap(tam);
    
 
	heap.insereTAD(vetor, 16);
	
	heap.torneio();
	
	heap.imprime();
	
    return 0;
}
