#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

typedef string Data;

class node{
    
    friend class trie;

    private:
        int key;
        Data value;
    public:
        node();
};

node::node(){
    key = -1;
}

class trie{
    private:
        int capacity;
        node* trieArray;
        int size;
        unsigned int father(int i);
        unsigned int left(int i);
        unsigned int rigth(int i);
        int* convertToBinary(int position,int *bits);
    public:
        trie();
        void insert(Data word, int position);
        void spyPosition(int position);
};

trie::trie(){
    capacity = 100;
    trieArray = new node[capacity];
    trieArray[0].key = -1;
    size = 0;
}

unsigned int trie::father(int i){
    return (i-1)/2;
}

unsigned int trie::left(int i){
    return 2*i+1;
}

unsigned int trie::rigth(int i){
    return 2*i+2;
}

void trie::insert(Data word, int position){
    int bits = 4, j = 0;
   int* triePosition = convertToBinary(position, &bits);

    
    for(int i = 0; i < bits; i++)
    {
        //cout << triePosition[i] << endl;
        if(triePosition[i] == 1){
            j = rigth(j);
            if(trieArray[j].key == -1){
                trieArray[j].key = 1;
            }
            //cout << j << "/ " << trieArray[j].key << endl;
        }
        else if(triePosition[i] == 0){
            j = left(j);
            if(trieArray[j].key == -1){
                trieArray[j].key = 0;
            }
            //cout << j << "/ " << trieArray[j].key << endl;
        }
    }

    trieArray[j].value = word;
}

void trie::spyPosition(int position){
    int bits = 4, j = 0;
   int* triePosition = convertToBinary(position, &bits);

    
    for(int i = 0; i < bits; i++)
    {
        if(trieArray[j].key == -1){
            cout << "Position don't exist" << endl;
            exit(EXIT_FAILURE);
        }
        if(triePosition[i] == 1){
            j = rigth(j);
        }
        else if(triePosition[i] == 0){
            j = left(j);
        }
    }

    cout << trieArray[j].value << endl;
}

int* trie::convertToBinary(int position, int* bits){
    *bits = log2(position+1);

    int* BinArray = new int[*bits];
    
    for(int i = 0; i < *bits; i++)
    {
        BinArray[i] = position % 2;
        cout << i << ": " << position%2 << "/";
        cout << position/2 << endl;
        position = position/2;
    }

    return BinArray;
    
}

int main(){

    int position;
    Data word;

    cin >> position >> word;

    trie myTrie;

    myTrie.insert(word, position);

    cout << endl;

    cin >> position;

    myTrie.spyPosition(position);

    return 0;
}
