//
// Created by Nicolaescu Raoul on 22.05.2023.
//

#include "Transaction.h"


Transaction::Transaction()
{
    type = "";
}

Transaction::Transaction(const Transaction& newTransaction)
{
    type = newTransaction.getType();
    currencyList = newTransaction.getCurrency();
}

std::string Transaction::getType() const
{
    return type;
}

std::vector<Currency> Transaction::getCurrency() const
{
    return currencyList;
}

void Transaction::setType(std::string newType)
{
    if (newType != "in" && newType != "out") {
        throw std::invalid_argument("Tipul tranzactiei trebuie sa fie in sau out\n");
    }
    type = newType;
}

void Transaction::setCurrency(std::vector<Currency> newCurrencyList)
{
    currencyList = newCurrencyList;
}

void Transaction::addCurrency(Currency newCurrency)
{
    currencyList.push_back(newCurrency);
}

int Transaction::getTransactionSum() const
{
    int sum = 0;

    for (Currency currency : currencyList) {

        sum += currency.getSum();

    }
    return sum;
}

Transaction& Transaction::operator=(const Transaction& rTransaction)
{
    if (this != &rTransaction) {

        this->setType(rTransaction.getType());
        this->setCurrency(rTransaction.getCurrency());
    }


    return *this;
}

bool Transaction::operator==(const Transaction& rTransaction)
{
    return false;
}


std::ostream& operator<<(std::ostream& os, const Transaction& transaction){

    os << transaction.getType() << " ";
    os << transaction.getCurrency().size()<<" ";

    for(auto currency : transaction.getCurrency()){
        os << currency << " ";
    }

    return os;

}
std::istream& operator>>(std::istream& is, Transaction& transaction){

    is >> transaction.type;

    int n;

    is >> n;

    for(int i =0;i<n;i++){

        Currency currency;

        is >> currency;

        transaction.addCurrency(currency);
    }

    return is;

}