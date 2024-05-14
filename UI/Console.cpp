//
// Created by Nicolaescu Raoul on 22.05.2023.
//

#include "Console.h"
#include "../Product/Product.h"
#include "../Utils/Validators/Validators.h"
#include <string.h>
#include <string>
#include <iostream>

void Console::add()
{
    Validators validator;

    std::string sum;
    std::string name;
    std::string id;

    std::cout << "Nume produs: ";
    std::cin >> name;
    std::cout << "\nPretul produsului: ";
    std::cin >> sum;
    std::cout << "\nId ul produsului: ";
    std::cin >> id;


    try {

        validator.validateProduct(name, sum, id);

        service.addProduct(Product(name,std::stoi(sum),std::stoi(id)));
    }
    catch (std::exception&  except) {

        if (strcmp(except.what(), "invalid stoi argument")==0) {
            std::cout << "\n Pretul si id-ul trebuie sa fie numere intregi\n";
        }
        else
        {
            std::cout << "\n"<<except.what()<<"\n\n";
        }
    }


}

void Console::del()
{
    std::string position;

    std::cout << "Pozitia produsului: ";
    std::cin >> position;
    try {
        service.delProduct(std::stoi(position));
    }
    catch (std::exception& except) {

        std::cout << except.what() <<"\n";
    }

}

void Console::update()
{
    Validators validator;

    std::string position;
    std::string sum;
    std::string name;
    std::string id;

    std::cout << "Pozitia produsului: ";
    std::cin >> position;

    std::cout << "Noul nume: ";
    std::cin >> name;

    std::cout << "Noul pret: ";
    std::cin >> sum;

    std::cout << "Noul id: ";
    std::cin >> id;

    try {
        validator.validateStringToInt(position);
        validator.validateProduct(name, sum, id);

        service.updateProduct(std::stoi(position),Product(name, std::stoi(sum), std::stoi(id)));


    }
    catch (std::out_of_range&  except) {
        std::cout << except.what()<<"\n";
    }
    catch (std::exception& except) {

        if (strcmp(except.what(), "invalid stoi argument") == 0) {
            std::cout << "\n Pretul si id-ul trebuie sa fie numere intregi\n";
        }
        else
        {
            std::cout<< except.what() << "\n";
        }
    }





}

void Console::printAll()
{
    std::vector<Product> list;

    list = service.getAllProduct();

    for (auto product : list) {
        std::cout << "Id produs: " << product.getId() << " ";
        std::cout << "Nume produs: " << product.getName() << " ";
        std::cout << "Pret produs: " << product.getPrice()<<"\n";
    }
    std::cout << "\n";
}

void Console::help()
{
    std::cout << "1. Adauga produs \n";
    std::cout << "2. Adauga tranzactie \n";
    std::cout << "3. Update produs \n";
    std::cout << "4. Delete produs \n";
    std::cout << "5. Cumpara produs \n";
    std::cout << "6. Afiseaza produse \n";
    std::cout << "7. Afiseaza bancnotele din tonomat \n";
    std::cout << "8. Afiseaza tranzactiile \n";
    std::cout << "x. exit \n";
    std::cout << "\n";
}

void Console::buyProduct()
{
    int idProduct,nrOfBills;

    Transaction newTransaction;
    newTransaction.setType((std::string)"in");

    std::vector<Currency> currency;

    std::cout << "Id produs: ";
    std::cin >> idProduct;

    std::cout << "Nr de bancnote: ";
    std::cin >> nrOfBills;

    for (int i = 0; i < nrOfBills; i++)
    {
        std::string value;
        std::string quantity;

        std::cout << "Valoare bancnota: ";
        std::cin >> value;
        std::cout << "Cantitate: ";
        std::cin>> quantity;

        try {

            currency.push_back(Currency(std::stoi(value), std::stoi(quantity)));

        }

        catch (std::exception&  except) {
            i--;
            std::cout << except.what()<<"\n";
        }

    }

    newTransaction.setCurrency(currency);

    service.buyProduct(idProduct, newTransaction);
}

void Console::showCurrency()
{
    std::vector<Currency> currencyList;

    currencyList = service.getCurrency();

    for (Currency currency : currencyList) {

        std::cout << "Valoare bancnote: " << currency.getValue() << " ";
        std::cout << "Cantitate: " << currency.getQuantity() << " \n";
    }
    std::cout << "\n";
}

void Console::showTransactions()
{
    std::vector<Transaction> transactionList;

    transactionList = service.getTransactions();

    for (Transaction transaction : transactionList) {


        std::cout << "Tip: " << transaction.getType() << "\n";

        std::vector<Currency> currencyList = transaction.getCurrency();

        for (Currency currency : currencyList)
        {
            std::cout << "	";
            std::cout << "Valoare: " << currency.getValue() << " ";
            std::cout << "Cantitate: " << currency.getQuantity() << " \n";
        }
        std::cout << "\n";
    }
    std::cout << "\n";
}

void Console::addTransaction()
{

    Transaction transaction;
    std::vector<Currency> currency;
    std::string type;
    int nrOfBills;
    std::cout << "Tipul tranzactiei: ";
    std::cin >> type;
    std::cout << "Numarul de bancnote: ";
    std::cin >> nrOfBills;

    for (int i = 0; i < nrOfBills; i++)
    {
        std::string value;
        std::string quantity;

        std::cout << "Valoare bancnota: ";
        std::cin >> value;
        std::cout << "Cantitate: ";
        std::cin >> quantity;

        try {

            currency.push_back(Currency(std::stoi(value), std::stoi(quantity)));
        }
        catch (std::exception& except) {
            i--;
            if (strcmp(except.what(), "invalid stoi argument") == 0) {
                std::cout << "\n Valoarea si cantitatea trebuie sa fie numere intregi\n";
            }
            else
            {
                std::cout << except.what() << "\n";
            }
        }


    }

    try {
        transaction.setType(type);
        transaction.setCurrency(currency);
        service.addTransaction(transaction);
    }
    catch (std::exception& exception) {
        std::cout << exception.what() << "\n";
    }

}

void Console::run()
{
    std::string option;

    service.load();

    while (true) {
        this->help();

        std::cout << "Introduceti optiunea: ";
        std::cin >> option;

        std::cout << "\n";

        if (option == "1") {
            this->add();
        }

        if (option == "2") {
            this->addTransaction();
        }

        if (option == "3") {
            this->update();
        }

        if (option == "4") {
            this->del();
        }

        if (option == "5") {
            this->buyProduct();
        }

        if (option == "6") {
            this->printAll();
        }

        if (option == "7") {
            this->showCurrency();
        }

        if (option == "8") {
            this->showTransactions();
        }

        if (option == "x") {
            service.unload();
            return;
        }



    }
}
