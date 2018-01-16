#include <iostream>
#include <string>
#include <stdexcept>
#include "OfficeBlock.hpp"

/*****************************************
************** OFFICEBLOCK ***************
*****************************************/

// Coplien methods

OfficeBlock::OfficeBlock():
_signer(NULL), _executor(NULL), _intern(NULL) {};

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

    Form* form = _intern->makeForm(name, target);
    _signer->signForm(*form);
    _executor->executeForm(*form);
}

