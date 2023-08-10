#ifndef ARVORE_H
#define ARVORE_H

#include "no.hpp"

class Arvore
{
    public:
        Arvore();
        ~Arvore();

        //void caminha(int tipo);
        void limpa();
        void constroiInfixa(std::string linha);
        void constroiPosfixa(std::string linha);
        void imprimeInf();
        void imprimePosf();
        void calcula();

    private:
        void apagaRecursivo(No* p);
        void inOrdem(No* p);
        void posOrdem(No* p);
        double calculaPosOrdem(No* p);
        
        No *raiz;
};

#endif
