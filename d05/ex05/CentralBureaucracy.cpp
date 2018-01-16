#include <ctime>
#include <iostream>
#include <string>
#include <stdexcept>
#include "CentralBureaucracy.hpp"

int  CentralBureaucracy::_idx = 0;
bool CentralBureaucracy::_seeded = false;

/*****************************************
************** EXCEPTIONS ****************
*****************************************/

CentralBureaucracy::WaitSpaceFullException::WaitSpaceFullException(WaitSpaceFullException const& rhs) {
    *this = rhs;
};

CentralBureaucracy::WaitSpaceFullException& CentralBureaucracy::WaitSpaceFullException::operator=(WaitSpaceFullException const& rhs) {
    (void)rhs;
    return *this;
};

const char* CentralBureaucracy::WaitSpaceFullException::what() const throw() {
    return "Exception: No more space for additional bureaucrats";
}

/*****************************************
*********CENTRALBUREAUCRACYy *************
*****************************************/

// Coplien methods

CentralBureaucracy::CentralBureaucracy() {

    if (_seeded == false) {
        _seeded = true;
        srand(time(nullptr));
    }

    _ob = new OfficeBlock[20];
    for (int i = 0; i < 20; i++) {
        Intern* intern = new Intern();
        _ob[i].setIntern(*intern);
    }
}

CentralBureaucracy::CentralBureaucracy(CentralBureaucracy const& rhs) {
    *this = rhs;
}

CentralBureaucracy& CentralBureaucracy::operator=(CentralBureaucracy const& rhs) {

    for (int i = 0; i < 20; i++) {
        _ob[i] = rhs._ob[i];
    }
    for (int i = 0; i < WAITSPACE; i++) {
        _waitSpace[i] = rhs._waitSpace[i];
    }
    return *this;
}

// Getters

OfficeBlock&        CentralBureaucracy::getOfficeBlock(int i) const {
    return _ob[i];
}

// Methods

void              CentralBureaucracy::feedBureaucracy(Bureaucrat& b) {

    for (int i = 0; i < 20; i++) {
        if (_ob[i].getSigner() == nullptr) {
            _ob[i].setSigner(b);
            return;
        } else if (_ob[i].getExecutor() == nullptr) {
            _ob[i].setExecutor(b);
            return;
        }
    }
    for (int i = 0; i < WAITSPACE; i++) {
        _waitSpace[i] = &b;
        return;
    }

    throw WaitSpaceFullException();
}

void             CentralBureaucracy::queueUp(std::string target) {

    std::string formArr[3] = {
        "ShrubberyCreationForm",
        "RobotomyRequestForm",
        "PresidentialPardonForm"
    };

    bool success = false;
    int  errorCount = 0;

    while (success == false) {
        try {
            _ob[_idx].doBureaucracy(formArr[rand() % 3], target);
            success = true;
        } catch (std::exception& e) {
            std::cerr << "CentralBureaucracy>doBureaucracy; " << e.what() << std::endl;
            errorCount += 1;
            if (errorCount == 20) {
                std::cerr << "No OfficeBlock capable of processing form for " << target << std::endl;
                exit(1);
            }
        }
        _idx = (_idx == 19) ? 0 : _idx + 1;
    }
    std::cout << "Successful queue, great job!" << std::endl;
}; 
