#include <iostream>
#include <string>
#include <stdexcept>
#include "OfficeBlock.hpp"

/*****************************************
************** OFFICEBLOCK ***************
*****************************************/

// Coplien methods

OfficeBlock::OfficeBlock():

// Getters

Bureaucrat* OfficeBlock::getSigner() const {
    return _signer
}

Bureaucrat* OfficeBlock::getExecutor() const {
    return _executor;
}

Intern*     OfficeBlock::getIntern() const {
    return _intern;
}

// Methods

void        OfficeBlock::doBureaucracy(std::string name, std::string target) {

    Form* form = _intern.MakeForm(name, target);
    _signer.signForm(form);
    _executor.executeForm(form);
}

