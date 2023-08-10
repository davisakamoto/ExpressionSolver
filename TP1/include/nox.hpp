#ifndef NO_H
#define NO_H

#include "item.hpp"

class No
{
    public:
        No();

    private:
        Item item;
        No *esq;
        No *dir;

    friend class Arvore;
};

#endif