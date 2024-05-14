//
// Created by Nicolaescu Raoul on 22.05.2023.
//

#include "TestRepository.h"

#include "../Repositories/Repository.h"
#include <assert.h>

void TestRepository::testAdd()
{
    Repository<int> repo;

    repo.add(1);

    assert(repo.getAll().size() == 1);
}

void TestRepository::testDel()
{
    Repository<int> repo;

    repo.add(1);
    repo.add(2);

    repo.del(0);

    assert(repo.getAll().size() == 1);
}

void TestRepository::testUpdate()
{
    Repository<int> repo;

    repo.add(1);

    repo.update(0, 2);

    assert(repo.getFromPosition(0) == 2);
}

void TestRepository::testFind()
{
    Repository<int> repo;

    repo.add(1);

    assert(repo.find(1) == 0);
    assert(repo.find(2) == -1);
}

void TestRepository::testGetFromPosition()
{
    Repository<int> repo;

    repo.add(1);

    repo.update(0, 2);

    assert(repo.getFromPosition(0) == 2);
}

void TestRepository::testGetAll()
{
    Repository<int> repo;

    repo.add(1);
    repo.add(2);

    assert(repo.getAll().size() == 2);
}

void TestRepository::testAll()
{

    this->testAdd();
    this->testDel();
    this->testUpdate();
    this->testFind();
    this->testGetFromPosition();
    this->testGetAll();
}
