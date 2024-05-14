//
// Created by Nicolaescu Raoul on 22.05.2023.
//

#ifndef LAB_FINAL_TRANSACTION_H
#define LAB_FINAL_TRANSACTION_H


#include"../Currency/Currency.h"
#include <string>
#include <vector>

class Transaction
{
private:

    std::string type;
    std::vector<Currency> currencyList;

public:

    Transaction();
    Transaction(const Transaction& newTransaction);

    ~Transaction() = default;

    std::string getType()const;
    std::vector<Currency> getCurrency()const;

    void setType(std::string newType);
    void setCurrency(std::vector<Currency> newCurrencyList);

    void addCurrency(Currency newCurrency);

    int getTransactionSum()const;

    Transaction& operator=(const Transaction& rTransaction);

    bool operator==(const Transaction& rTransaction);

    friend std::ostream& operator<<(std::ostream& os, const Transaction& transaction);
    friend std::istream& operator>>(std::istream& is, Transaction& transaction);

};



#endif //LAB_FINAL_TRANSACTION_H
