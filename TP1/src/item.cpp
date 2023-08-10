#include "item.hpp"

Item::Item()
{
    chave = "";
}

Item::Item(std::string c)
{
    chave = c;
    if (isParentese())
    {
        tipo = "Parentese";
    }
    else if (isOperator())
    {
        tipo = "Operador";
    }
    else
    {
        try 
        {
            double numero = std::stod(chave);
            tipo = "Numero";
        }
        catch (const std::invalid_argument& ia)
        {
            tipo = "String";
        }
    }
}

bool Item::isParentese()
{
    if ((chave == "(") || (chave == ")") )
        return true;
    else 
        return false;
}

bool Item::isOperator()
{
    if ((chave == "+") || (chave == "-") || (chave == "*") || (chave == "/") )
        return true;
    else
        return false;
}

void Item::setChave(std::string c)
{
    chave = c;
}

std::string Item::getChave()
{
    return chave;
}

std::string Item::getTipo()
{
    return tipo;
}

void Item::imprime()
{
    std::cout << chave << " ";
}

Item& Item::operator=(Item const& item)
{
    chave = item.chave;
    tipo = item.tipo;

    return *this;
}

bool Item::operator==(const std::string& str) const 
{
    return this->chave == str;
}

bool Item::operator!=(const std::string& str) const 
{
    return this->chave != str;
}