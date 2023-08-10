#include "pilha.hpp"

Pilha::Pilha()
{
    tamanho = 0;
    topo = -1;
}

int Pilha::getTamanho() 
{
    return tamanho;
}
        
bool Pilha::vazia() 
{
    return tamanho == 0;
}

No* Pilha::getTopo()
{
    No* aux;
    aux = nos[topo];
    return aux;
}

void Pilha::empilha(No* no){
    if(tamanho == MAXTAM)
        throw "A pilha está cheia!";

    topo++;
    nos[topo] = no;
    tamanho++;

};

No* Pilha::desempilha(){
    No* aux;
    
    if(tamanho == 0)
        throw "A pilha está vazia!";
    
    aux = nos[topo];
    topo--;
    tamanho--;
    return aux;;
};

void Pilha::limpa(){
    topo = -1;
    tamanho = 0;
};


