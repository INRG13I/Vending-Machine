//
// Created by Nicolaescu Raoul on 22.05.2023.
//

#ifndef LAB_FINAL_FILEREPOSITORY_H
#define LAB_FINAL_FILEREPOSITORY_H


#include<string>
#include <fstream>
#include "Repository.h"

template<typename Type>
class FileRepository:public Repository<Type>
{

private:
    std::string filePath;

public:

    FileRepository();

    ~FileRepository() = default;

    void fileLoad();
    void fileUnload();

};

template<typename Type>
inline FileRepository<Type>::FileRepository()
{
    filePath = typeid(Type).name();
    filePath.append(".txt");

    //FileRepository<Currency> filePath = "Currency.txt"
}


template<typename Type>
inline void FileRepository<Type>::fileLoad()
{

    std::ifstream file(filePath);

    Type e;

    while (file >> e) {

        this->add(e);
    }

    file.close();

}


template<typename Type>
inline void FileRepository<Type>::fileUnload(){

    std::vector<Type> entityList;

    entityList = this->getAll();

    std::ofstream file(filePath);

    for (auto entity : entityList) {
        file << entity << "\n";
    }

    file.close();

}


#endif //LAB_FINAL_FILEREPOSITORY_H
