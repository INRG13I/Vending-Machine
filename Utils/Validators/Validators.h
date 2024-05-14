//
// Created by Nicolaescu Raoul on 22.05.2023.
//

#ifndef LAB_FINAL_VALIDATORS_H
#define LAB_FINAL_VALIDATORS_H


#include <stdexcept>
#include <string>
#include "../Exceptions/Exceptions.h"
class Validators
{
public:

    void validateString(std::string string) {

        if(string ==""){
            throw InvalidName();
        }
    }

    void validateValue(int value) {

        if (value < 0) {
            throw ValueError();
        }
    }

    void validateStringToInt(std::string string) {

        try {
            std::stoi(string);
        }
        catch (std::invalid_argument&) {
            throw ValueError();
        }
    }


    void validateCurrency(std::string value, std::string quantity) {

        try {
            this->validateStringToInt(value);
            this->validateStringToInt(quantity);
            this->validateValue(std::stoi(value));
            this->validateValue(std::stoi(quantity));

        }
        catch (std::exception& exception) {
            throw exception;
        }

    }
    void validateProduct(std::string name,std::string price,std::string id) {

        try {
            this->validateStringToInt(price);
            this->validateStringToInt(id);
            this->validateValue(std::stoi(price));
            this->validateValue(std::stoi(id));
            this->validateString(name);
        }
        catch (std::exception& exception) {
            throw exception;
        }
    }


};



#endif //LAB_FINAL_VALIDATORS_H
