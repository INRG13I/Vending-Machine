//
// Created by Nicolaescu Raoul on 22.05.2023.
//

#include "Service.h"

#include <algorithm>

void Service::addProduct(Product product)
{
    validators.validateProduct(product.getName(),std::to_string(product.getPrice()),std::to_string(product.getId()));
    productsList.add(product);
}

void Service::delProduct(int position)
{
    try {

        productsList.del(position);
    }
    catch (std::exception& exception) {
        throw exception;
    }
}

void Service::updateProduct(int position, Product newProduct)
{
    productsList.update(position, newProduct);
}

int Service::findProduct(Product product) const
{
    return productsList.find(product);
}

Product Service::getProductFromPosition(int position)
{
    return productsList.getFromPosition(position);
}

std::vector<Product> Service::getAllProduct() const
{
    return productsList.getAll();
}

std::vector<Currency> Service::getCurrency() const
{
    return currencyList.getAll();
}

std::vector<Transaction> Service::getTransactions() const
{
    return transactionList.getAll();
}

void Service::addTransaction(Transaction transaction)
{
    if (transaction.getType() == "in")
    {
        std::vector<Currency> transactionCurrency;

        transactionCurrency = transaction.getCurrency();

        for (Currency tCurrency : transactionCurrency)
        {
            if (currencyList.find(tCurrency) == -1) {
                currencyList.add(tCurrency);
            }
            else
            {
                int newQuantity = tCurrency.getQuantity();

                newQuantity += currencyList.getFromPosition(currencyList.find(tCurrency)).getQuantity();

                tCurrency.setQuantity(newQuantity);

                currencyList.update(currencyList.find(tCurrency), tCurrency);
            }
        }
    }
    else
    {
        std::vector<Currency> transactionCurrency;

        transactionCurrency = transaction.getCurrency();

        for (Currency tCurrency : transactionCurrency)
        {
            if (currencyList.find(tCurrency) == -1) {
                return;
            }
            else
            {
                if (tCurrency.getQuantity() > currencyList.getFromPosition(currencyList.find(tCurrency)).getQuantity()) {
                    return;
                }
            }

        }


        for (Currency tCurrency : transactionCurrency) {

            int newQuantity = currencyList.getFromPosition(currencyList.find(tCurrency)).getQuantity();

            newQuantity -= tCurrency.getQuantity();

            tCurrency.setQuantity(newQuantity);

            currencyList.update(currencyList.find(tCurrency), tCurrency);
        }
    }

    transactionList.add(transaction);
}

void Service::buyProduct(int idProduct, Transaction transaction)
{
    int position = productsList.find(Product((std::string)"N/A", 0, idProduct));


    if (position != -1 && transaction.getTransactionSum()>=productsList.getFromPosition(position).getPrice()) {

        this->addTransaction(transaction);

        Product boughtProduct = productsList.getFromPosition(position);

        std::vector<Currency> currentCurrency;

        currentCurrency = currencyList.getAll();

        std::sort(currentCurrency.begin(), currentCurrency.end());

        int difference = transaction.getTransactionSum() - boughtProduct.getPrice();

        int currentSum = 0;

        Transaction newTransaction;

        newTransaction.setType((std::string)"out");

        for (Currency currency : currentCurrency)
        {
            if (currentSum >= difference) {
                break;
            }

            int quantity = 0;

            while (currentSum + (quantity+1)*currency.getValue() <= difference && quantity+1<=currency.getQuantity())
            {
                quantity++;
            }

            currentSum += currency.getValue() * quantity;

            if (quantity != 0) {

                newTransaction.addCurrency(Currency(currency.getValue(), quantity));
            }
        }

        if (newTransaction.getCurrency().size() != 0) {

            this->addTransaction(newTransaction);
        }
    }
}


void Service::unload(){

    productsList.fileUnload();
    currencyList.fileUnload();
    transactionList.fileUnload();
}

void Service::load(){

    productsList.fileLoad();
    currencyList.fileLoad();
    transactionList.fileLoad();
}
