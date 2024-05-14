//
// Created by Nicolaescu Raoul on 22.05.2023.
//

#ifndef LAB_FINAL_EXCEPTIONS_H
#define LAB_FINAL_EXCEPTIONS_H


#include<exception>

class IdError : public std::exception {
public:

    const char* what() const noexcept override {
        return "Id-ul trebuie sa fie un numar natural nenul! \n";
    }
};


class ValueError : public std::exception {
public:

    const char* what() const noexcept override {
        return "Valuarea trebuie sa fie un numar natural nenul! \n";
    }
};



class InvalidName : public std::exception {
public:

    const char* what() const noexcept override {
        return "Numele trebuie sa aiba cel putin un caracter! \n";
    }
};



#endif //LAB_FINAL_EXCEPTIONS_H
