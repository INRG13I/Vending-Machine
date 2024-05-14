//
// Created by Nicolaescu Raoul on 22.05.2023.
//

#ifndef LAB_FINAL_CONSOLE_H
#define LAB_FINAL_CONSOLE_H


#include "../Services/Service.h"

class Console
{

private:

    Service service;

    void add();
    void del();
    void update();
    void printAll();
    void help();
    void buyProduct();
    void showCurrency();
    void showTransactions();
    void addTransaction();



public:

    void run();
};


#endif //LAB_FINAL_CONSOLE_H
