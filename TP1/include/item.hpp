#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include <string>

class Item
{
    public:
        Item();
        Item(std::string c);

        void setChave(std::string c);
        std::string getChave();
        std::string getTipo();

        bool isParentese();
        bool isOperator();
        void imprime();

        Item& operator=(const Item& item);
        bool operator==(const std::string& str) const;
        bool operator!=(const std::string& str) const;

    private:
        std::string chave;
        std::string tipo;
};

#endif