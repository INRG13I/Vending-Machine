//
// Created by Nicolaescu Raoul on 22.05.2023.
//

#include "Currency.h"
#include "../Utils/Exceptions/Exceptions.h"

Currency::Currency()
{
    this->setValue(0);
    this->setQuantity(0);
}

Currency::Currency(int newValue, int newQuantity)
{
    try {
        this->setValue(newValue);
        this->setQuantity(newQuantity);

    }
    catch (std::invalid_argument& exception) {
        throw exception;
    }
}

Currency::Currency(const Currency& newCurrency)
{
    this->setValue(newCurrency.getValue());
    this->setQuantity(newCurrency.getQuantity());
}

int Currency::getValue() const
{
    return value;
}

int Currency::getQuantity() const
{
    return quantity;
}

void Currency::setValue(int newValue)
{
    if (newValue < 0) {
        throw ValueError();
    }
    value = newValue;
}

void Currency::setQuantity(int newQuantity)
{
    if (newQuantity < 0) {
        throw ValueError();
    }
    quantity = newQuantity;
}

int Currency::getSum() const
{
    return this->getValue()*this->getQuantity();
}

Currency& Currency::operator=(const Currency& rCurrency)
{
    if (this != &rCurrency) {

        this->setValue(rCurrency.getValue());
        this->setQuantity(rCurrency.getQuantity());

    }



    return *this;
}

bool Currency::operator==(const Currency& rCurrency)
{
    return this->getValue()==rCurrency.getValue();
}

bool Currency::operator<(const Currency& rCurrency) const
{
    if (this->getValue() < rCurrency.getValue())return false;
    return true;
}

std::ostream& operator<<(std::ostream& os, const Currency& currency){

    os << currency.getValue() << " " << currency.getQuantity();

    return os;
}

std::istream& operator>>(std::istream& is, Currency& currency){

    is >> currency.value >> currency.quantity;

    return is;
}
