#ifndef PILHA_H
#define PILHA_H

#include "no.hpp"

class Pilha
{
    public:
        Pilha();
        int getTamanho();
        bool vazia();
        No* getTopo();

        void empilha(No* no);
        No* desempilha();
        void limpa();

    private:
        int tamanho;
        int topo;
        static const int MAXTAM = 100;
        No* nos[MAXTAM];
};

#endif