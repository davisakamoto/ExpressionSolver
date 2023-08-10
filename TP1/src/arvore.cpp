#include <sstream>

#include "arvore.hpp"
#include "pilha.hpp"

Arvore::Arvore()
{
    raiz = NULL;
}

Arvore::~Arvore()
{
    limpa();
}

void Arvore::imprimeInf()
{
    inOrdem(raiz);
    std::cout << std::endl;
}

void Arvore::imprimePosf()
{
    posOrdem(raiz);
    std::cout << std::endl;
}

void Arvore::constroiInfixa(std::string linha) 
{
    Pilha pilha;

    std::string termo;
    std::istringstream termosExpressao(linha);

    //Remove a instrução (LER) e o tipo da expressão (INFIXA)
    termosExpressao >> termo;
    termosExpressao >> termo;

    // Percorre a expressão termo por termo
    while(termosExpressao >> termo) 
    {
        Item *item = new Item(termo);

        // Se o caracter é um dígito, é um operando
        if (item->getTipo() == "Numero") 
        {
            // Cria um nó folha para o operando
            No* novoNo = new No();
            novoNo->item = *item;

            // Empilha o nó folha
            pilha.empilha(novoNo);
        }
        // Se o caracter é um operador ou um parêntese
        else if (item->getTipo() == "Operador" || *item == "(") 
        {
            // Cria um nó para o operador/parêntese
            No* novoNo = new No();
            novoNo->item = *item;

            // Se for um parêntese de abertura, empilha o nó
            if (*item == "(") 
            {
                pilha.empilha(novoNo);
            }
            // Se for um operador, desempilha os operandos e adiciona como filhos do nó
            else 
            {
                // Desempilha o operando da esquerda
                No* esquerda = pilha.desempilha();

                // Adiciona os operandos como filhos do nó
                novoNo->esq = esquerda;

                // Empilha o nó
                pilha.empilha(novoNo);
            }
        }
        // Se o caracter é um parêntese de fechamento
        else if (*item == ")") {
            // Desempilha os operadores até encontrar o parêntese de abertura correspondente
            if (!pilha.vazia() && pilha.getTopo()->item != "(") 
            {
                No* direita = pilha.desempilha();

                No* novoNo = pilha.desempilha();

                if(novoNo->item == "(")
                {
                    pilha.empilha(direita);
                    delete novoNo;
                }
                else
                {
                    novoNo->dir = direita;

                    // Remove o parêntese de abertura da pilha
                    if (!pilha.vazia()) 
                    {
                        pilha.desempilha();
                    }

                    // Empilha o nó
                    pilha.empilha(novoNo);
                }
            }
        }
    }

    // A raiz da árvore é o último nó da pilha
    if (!pilha.vazia()) 
    {
        while (pilha.getTamanho() > 1)
        {
            No* direita = pilha.desempilha();

            No* novoNo = pilha.desempilha();
            novoNo->dir = direita;

            // Remove parêntese de abertura se existir
            if (!pilha.vazia() && pilha.getTopo()->item == "(") 
            {
                pilha.desempilha();
            }

            // Empilha o nó
            pilha.empilha(novoNo);

        }
        raiz = pilha.desempilha();
    }
}

void Arvore::constroiPosfixa(std::string linha)
{
    Pilha pilha;

    std::string termo;
    std::istringstream termosExpressao(linha);

    //Remove a instrução (LER) e o tipo (POSFIXA)
    termosExpressao >> termo;

    // Percorre a expressão termo por termo
    while(termosExpressao >> termo) 
    {
        Item *item = new Item(termo);

        if(item->getTipo() == "Numero")
        {
            No* novoNo = new No();
            novoNo->item = *item;

            pilha.empilha(novoNo);
        }
        else if(item->getTipo() == "Operador")
        {
            No* novoNo = new No();
            novoNo->item = *item;

            No* direita = pilha.desempilha();
            No* esquerda = pilha.desempilha();

            novoNo->dir = direita;
            novoNo->esq = esquerda;

            pilha.empilha(novoNo);
        }
    }

    if(!pilha.vazia())
        raiz = pilha.desempilha();
}

void Arvore::inOrdem(No *p){
    if(p!=NULL)
    {
        if(p->esq == NULL)
        {
            std::cout << "( ";
            p->item.imprime();
            std::cout << ") ";
            inOrdem(p->dir);
        }
        else
        {
            std::cout << "( ";
            inOrdem(p->esq);

            p->item.imprime();

            inOrdem(p->dir);
            std::cout << ") ";
        }
    }
}


void Arvore::posOrdem(No *p)
{
    if(p!=NULL)
    {
        if(p->esq == NULL)
        {
            p->item.imprime();
            posOrdem(p->dir);
        }
        else
        {
            posOrdem(p->esq);
            posOrdem(p->dir);
            p->item.imprime();
        }
    }
}

void Arvore::limpa()
{
    apagaRecursivo(raiz);
    raiz = NULL;
}


void Arvore::apagaRecursivo(No *p)
{
    if(p!=NULL){
        apagaRecursivo(p->esq);
        apagaRecursivo(p->dir);
        delete p;
    }
}

void Arvore::calcula()
{
    try
    {
        double resultado = calculaPosOrdem(raiz);
        std::cout << "VAL: " << resultado << std::endl;
    }
    catch(const std::exception &e)
    {
        std::cout << "ERRO: " << e.what() << std::endl; 
    }
}

double Arvore::calculaPosOrdem(No* p)
{
    if(p!=NULL)
    {
        if(p->item.getTipo() == "Numero")
        {
            return std::stod(p->item.getChave());
        }
        else
        {
            double num1 = calculaPosOrdem(p->esq);
            double num2 = calculaPosOrdem(p->dir);
            if(p->item == "+")
                return num1 + num2;
            else if(p->item == "-")
                return num1 - num2;
            else if(p->item == "*")
                return num1 * num2;
            else if(p->item == "/")
            {
                if (num2 == 0)
                    throw std::runtime_error("DIVISAO POR ZERO");
                else
                    return num1 / num2;
            }
        }
    }

}