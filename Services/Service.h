//
// Created by Nicolaescu Raoul on 22.05.2023.
//

#ifndef LAB_FINAL_SERVICE_H
#define LAB_FINAL_SERVICE_H



#include "../Product/Product.h"
#include "../Trasnactions/Transaction.h"
#include "../Currency/Currency.h"
#include "../Repositories/Repository.h"
#include "../Repositories/FileRepository.h"
#include "../Utils/Validators/Validators.h"

#include <string>


class Service
{
private:

    FileRepository<Product> productsList;
    FileRepository<Transaction> transactionList;
    FileRepository<Currency> currencyList;
    Validators validators;


public:

    Service() = default;
    ~Service() = default;

    void addProduct(Product product);
    void delProduct(int position);
    void updateProduct(int position, Product newProduct);

    int findProduct(Product product)const;

    Product getProductFromPosition(int position);
    std::vector<Product> getAllProduct()const;
    std::vector<Currency>getCurrency()const;
    std::vector<Transaction>getTransactions()const;


    void addTransaction(Transaction transaction);
    void buyProduct(int idProduct, Transaction transaction);

    void unload();
    void load();
};




#endif //LAB_FINAL_SERVICE_H
