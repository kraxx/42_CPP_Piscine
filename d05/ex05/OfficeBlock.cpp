#include <iostream>
#include <string>
#include <stdexcept>
#include "OfficeBlock.hpp"

/*****************************************
************** EXCEPTIONS ****************
*****************************************/

OfficeBlock::MissingSignerException::MissingSignerException(MissingSignerException const& rhs) {
    *this = rhs;
};

OfficeBlock::MissingSignerException& OfficeBlock::MissingSignerException::operator=(MissingSignerException const& rhs) {
    (void)rhs;
    return *this;
};

const char* OfficeBlock::MissingSignerException::what() const throw() {
    return "Exception: No signer assigned";
}


OfficeBlock::MissingExecutorException::MissingExecutorException(MissingExecutorException const& rhs) {
    *this = rhs;
};

OfficeBlock::MissingExecutorException& OfficeBlock::MissingExecutorException::operator=(MissingExecutorException const& rhs) {
    (void)rhs;
    return *this;
};

const char* OfficeBlock::MissingExecutorException::what() const throw() {
    return "Exception: No executor assigned";
}


OfficeBlock::MissingInternException::MissingInternException(MissingInternException const& rhs) {
    *this = rhs;
};

OfficeBlock::MissingInternException& OfficeBlock::MissingInternException::operator=(MissingInternException const& rhs) {
    (void)rhs;
    return *this;
};

const char* OfficeBlock::MissingInternException::what() const throw() {
    return "Exception: No intern assigned";
}

/*****************************************
************** OFFICEBLOCK ***************
*****************************************/

// Coplien methods

OfficeBlock::OfficeBlock():
_signer(nullptr), _executor(nullptr), _intern(nullptr) {};

OfficeBlock::OfficeBlock(Bureaucrat* signer, Bureaucrat* executor, Intern* intern):
_signer(signer), _executor(executor), _intern(intern) {};

// Getters

Bureaucrat* OfficeBlock::getSigner() const {
    return _signer;
}

Bureaucrat* OfficeBlock::getExecutor() const {
    return _executor;
}

Intern*     OfficeBlock::getIntern() const {
    return _intern;
}

// Setters

void        OfficeBlock::setSigner(Bureaucrat& signer) {
    _signer = &signer;
}

void        OfficeBlock::setExecutor(Bureaucrat& executor) {
    _executor = &executor;
}

void        OfficeBlock::setIntern(Intern& intern) {
    _intern = &intern;
}

// Methods

void        OfficeBlock::doBureaucracy(std::string name, std::string target) {

    Form* form;

    if (_signer != nullptr) {
        form = _intern->makeForm(name, target);
    } else {
        throw OfficeBlock::MissingSignerException();        
    } 
    if (_executor != nullptr) {
        _signer->signForm(*form);
    } else {
        throw OfficeBlock::MissingExecutorException();
    }
    if (_intern != nullptr) {
        _executor->executeForm(*form);
    } else {
        throw OfficeBlock::MissingInternException();
    }
}

