//
// Created by Nicolaescu Raoul on 22.05.2023.
//

#include "TestService.h"
#include "../Services/Service.h"
#include "../Product/Product.h"
#include <assert.h>

typedef std::string str;

void TestService::testAdd()
{
    Service service;

    service.addProduct(Product((str)"Covrig", 10, 1));

    assert(service.getAllProduct().size() == 1);
}

void TestService::testDel()
{
    Service service;

    service.addProduct(Product((str)"Covrig", 10, 1));

    service.delProduct(0);

    assert(service.getAllProduct().size() == 0);
}

void TestService::testUpdate()
{
    Service service;

    service.addProduct(Product((str)"Covrig", 10, 1));

    service.updateProduct(0, Product((str)"Crisps", 20, 2));

    assert(service.getProductFromPosition(0).getId() == 2);
}

void TestService::testFind()
{
    Service service;

    service.addProduct(Product((str)"Covrig", 10, 1));

    assert(service.findProduct(Product((str)"Covrig", 10, 1)) == 0);
}

void TestService::testGetFromPosition()
{
    Service service;

    service.addProduct(Product((str)"Covrig", 10, 1));

    service.updateProduct(0, Product((str)"Crisps", 20, 2));

    assert(service.getProductFromPosition(0).getId() == 2);
}

void TestService::testGetAll()
{
    Service service;

    service.addProduct(Product((str)"Covrig", 10, 1));

    service.addProduct(Product((str)"Crisps", 20, 2));

    assert(service.getAllProduct().size() == 2);
}

void TestService::testAll()
{
    this->testAdd();
    this->testDel();
    this->testUpdate();
    this->testFind();
    this->testGetFromPosition();
    this->testGetAll();
}
