//
// Created by Nicolaescu Raoul on 22.05.2023.
//

#include "Product.h"
#include "../Utils/Exceptions/Exceptions.h"

Product::Product()
{
    this->setPrice(0);
    this->setId(0);
}

Product::Product(str name, int price, int id)
{
    try {
        this->setName(name);
        this->setPrice(price);
        this->setId(id);
    }
    catch (std::invalid_argument& exception) {
        throw exception;
    }
}

Product::Product(const Product& product)
{
    this->setId(product.getId());
    this->setName(product.getName());
    this->setPrice(product.getPrice());
}

void Product::setName(str newName)
{
    if (newName == "") {
        throw InvalidName();
    }
    name = newName;
}

void Product::setId(int newId)
{
    if (newId < 0) {
        throw IdError();
    }
    id = newId;
}

void Product::setPrice(int newPrice)
{
    if (newPrice < 0) {
        throw ValueError();
    }
    price = newPrice;
}

str Product::getName() const
{
    return name;
}

int Product::getId() const
{
    return id;
}

int Product::getPrice()const
{
    return price;
}

Product& Product::operator=(const Product& rProduct)
{
    if (this != &rProduct) {

        this->setPrice(rProduct.getPrice());
        this->setName(rProduct.getName());
        this->setId(rProduct.getId());
    }


    return *this;
}

bool Product::operator==(const Product& rProduct)
{
    if (this->getId() == rProduct.getId())return true;
    return false;
}


std::ostream& operator<<(std::ostream& os, const Product& product){

    os << product.getName() << " " << product.getPrice() << " " << product.getId();
    return os;
}
std::istream& operator>>(std::istream& is, Product& product){

    is >> product.name>> product.price>> product.id;
    return is;
}


