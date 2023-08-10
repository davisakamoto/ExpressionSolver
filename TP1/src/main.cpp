#include <sstream>
#include <fstream>

#include "arvore.hpp"
#include "pilha.hpp"

//ESSE MÉTODO FAZ UMA PRIMEIRA ANÁLISE PARA IDENTIFICAR SE A EXPRESSÃO ESTÁ NA FORMA INFIXA OU POSFIXA, E JÁ IDENTIFICA POSSÍVEIS EXPRESSÕES INVÁLIDAS
std::string avaliaExpressao(std::string linha)
{
    std::string termo;
    std::istringstream termosExpressao(linha);

    Item* item = NULL;
    Item* ultimoItem = NULL;
    int operandos = 0, operadores = 0, parentEsq = 0, parentDir = 0;
    bool first = true;

    termosExpressao >> termo;
    termosExpressao >> termo;
    if(termo == "INFIXA")
    {
        while(termosExpressao >> termo)
        {
            item = new Item(termo);

            if(item->getTipo() == "String")
            {
                return "INVALID";
            }
            else if(item->getTipo() == "Numero")
            {
                if(!first && (ultimoItem->getTipo() == "Numero" || ultimoItem->getChave() == ")"))
                    return "INVALID";
                operandos++;
            }
            else if(item->getTipo() == "Operador")
            {
                if(!first && (ultimoItem->getTipo() == "Operador" || ultimoItem->getChave() == "("))
                    return "INVALID";
                operadores++;
                if(operadores > operandos)
                    return "INVALID";
            }
            else if(item->getChave() == "(")
            {
                if(!first && (ultimoItem->getTipo() == "Numero" || ultimoItem->getChave() == ")"))
                    return "INVALID";
                parentEsq++;
            }
            else if(item->getChave() == ")")
            {
                if(!first && (ultimoItem->getTipo() == "Operador" || ultimoItem->getChave() == "("))
                    return "INVALID";
                parentDir++;
                if(parentDir > parentEsq)
                    return "INVALID";
                
            }

            if(!first)
                delete ultimoItem;
            ultimoItem = new Item(termo);
            delete item;
            first = false;
        }

        delete ultimoItem;

        if(!((operadores + 1) == operandos) || operandos == 0 || operadores == 0 || parentEsq != parentDir || parentEsq != (operandos+operadores))
            return "INVALIDA";
        else
            return "INFIXA";
    }
    else if(termo == "POSFIXA")
    {
       while(termosExpressao >> termo)
        {
            item = new Item(termo);

            if(item->getTipo() == "String" || item->getTipo() == "Parenteses")
                return "INVALID";
            else if(item->getTipo() == "Numero")
                operandos++;
            else if(item->getTipo() == "Operador")
                operadores++;

            if(operadores >= operandos)
                return "INVALID";
        }

        if(!((operadores + 1) == operandos) || operandos == 0 || operadores == 0)
            return "INVALID";
        else
            return "POSFIXA"; 
    }
    return "INVALID";
}



int main(int argc, char *argv[]) 
{
    if (argc < 2) 
    {
        std::cerr << "Usage: " << argv[0] << " FILENAME\n";
        return 1;
    }

    //ABRE ARQUIVO DE ENTRADA
    std::ifstream arquivo;
    arquivo.open(argv[1]);
    if(arquivo.fail()) {
        std::cout << "Unable to open file";
        return -1;
    }

    //CRIA ARVORE PARA GUARDAR TERMOS DA EXPRESSÃO
    Arvore *expressao = NULL;
    std::string tipoExpressao;


    //LÊ CADA LINHA DO ARQUIVO E ANALISA O QUE DEVE SER FEITO
    std::string linha;
    while(std::getline(arquivo, linha))
    {
        if (!linha.empty())
        {
            std::string comando;

            //LENDO VALORES ENTRE ESPAÇOS
            std::istringstream fluxoString(linha);
            fluxoString >> comando;

            //DEFINE COMANDO
            if(comando == "LER")
            {
                tipoExpressao = avaliaExpressao(linha);
                if(tipoExpressao == "INVALID")
                {
                    std::cout << "ERRO: ";
                    std::string termo;
                    while(fluxoString >> termo)
                    {
                        std::cout << termo << " ";
                    }
                    std::cout << "NÃO VÁLIDA" << std::endl;
                }
                else
                {
                    if(expressao != NULL)
                        delete expressao;
                    expressao = new Arvore();

                    std::cout << "EXPRESSAO OK: ";
                    std::string termo;
                    fluxoString >> termo;
                    while(fluxoString >> termo)
                    {
                        std::cout << termo << " ";
                    }
                    std::cout << std::endl;

                    if(tipoExpressao == "INFIXA")
                        expressao->constroiInfixa(linha);
                    else if(tipoExpressao == "POSFIXA")
                        expressao->constroiPosfixa(linha);
                }
            }
            else if(comando == "INFIXA")
            {
                if(expressao == NULL)
                {
                    std::cout << "ERRO: EXP NAO EXISTE\n";
                }
                else
                {
                    std::cout << "INFIXA: ";
                    expressao->imprimeInf();
                }
            }
            else if(comando == "POSFIXA")
            {
                if(expressao == NULL)
                {
                    std::cout << "ERRO: EXP NAO EXISTE\n";
                }
                else
                {
                    std::cout << "POSFIXA: ";
                    expressao->imprimePosf();
                }
            }
            else if(comando == "RESOLVE")
            {
                if(expressao == NULL)
                {
                    std::cout << "ERRO: EXP NAO EXISTE\n";
                }
                else
                {
                    expressao->calcula();
                }
            }
            else
            {
                std::cout << "Comando inválido \n";
            }
        }
    }
    
    delete expressao;

    arquivo.close();

    return 0;
}