#ifndef CENTRALBUREAUCRACY_HPP
# define CENTRALBUREAUCRACY_HPP

# define WAITSPACE 100

# include <iostream>
# include <stdexcept>
# include <string>
# include "Bureaucrat.hpp"
# include "Intern.hpp"
# include "OfficeBlock.hpp"

class CentralBureaucracy {

private:

    OfficeBlock* _ob;
    Bureaucrat*  _waitSpace[WAITSPACE];
    static int   _idx;
    static bool  _seeded;

public:

    // Exceptions

    class WaitSpaceFullException : public std::exception {

    public:

        WaitSpaceFullException() {};
        WaitSpaceFullException(WaitSpaceFullException const& rhs);
        WaitSpaceFullException& operator=(WaitSpaceFullException const& rhs);
        virtual ~WaitSpaceFullException() throw() {};

        virtual const char* what() const throw();
    };

    // Coplien methods

    CentralBureaucracy();
    CentralBureaucracy(CentralBureaucracy const& rhs);
    CentralBureaucracy& operator=(CentralBureaucracy const& rhs);
    ~CentralBureaucracy() {};

    // Getters

    OfficeBlock&     getOfficeBlock(int i) const;
 
    // Methods

    void             feedBureaucracy(Bureaucrat& b);
    void             queueUp(std::string target);

};

#endif