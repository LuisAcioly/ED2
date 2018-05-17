#include <iostream>
#include "heap.cpp"
using namespace std;

int main()
{
    maxHeap heap(10);
    
    data num;
    
    for (int i = 0; i < 10; i++)
	{
		cin >> num;
		heap.insere(num);
	}
	
	heap.imprime();
	
	
    return 0;
}
