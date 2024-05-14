//
// Created by Nicolaescu Raoul on 22.05.2023.
//

#include "TestProduct.h"
#include "../Product/Product.h"

#include <assert.h>

typedef std::string str;

void TestProduct::testGetName()
{
    Product product((str)"covrig",10,1);

    assert(product.getName() == "covrig");
}

void TestProduct::testGetId()
{
    Product product((str)"covrig", 10, 1);

    assert(product.getId() == 1);
}

void TestProduct::testGetPrice()
{
    Product product((str)"covrig", 10, 1);

    assert(product.getPrice() == 10);
}

void TestProduct::testSetName()
{
    Product product((str)"pizza", 10, 1);

    product.setName((str)"covrig");

    assert(product.getName() == "covrig");
}

void TestProduct::testSetId()
{
    Product product((str)"covrig", 10, 2);

    product.setId(1);
    assert(product.getId() == 1);
}

void TestProduct::testSetPrice()
{
    Product product((str)"covrig", 20, 1);

    product.setPrice(10);

    assert(product.getPrice() == 10);
}

void TestProduct::testEqualityOperator()
{
    Product product((str)"covrig", 10, 1);
    Product newProduct((str)"pizza", 20, 1);

    assert(product == newProduct);
}

void TestProduct::testAssignmentOperato()
{
    Product product((str)"covrig", 10, 1);
    Product newProduct;

    newProduct = product;

    assert(product == newProduct);
}

void TestProduct::testAll()
{
    this->testGetName();
    this->testGetId();
    this->testGetPrice();

    this->testSetName();
    this->testSetId();
    this->testSetPrice();

    this->testEqualityOperator();
    this->testAssignmentOperato();
}
