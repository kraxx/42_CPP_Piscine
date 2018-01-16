#ifndef OFFICEBLOCK_HPP
# define OFFICEBLOCK_HPP

# include <iostream>
# include <stdexcept>
# include <string>
# include "Bureaucrat.hpp"
# include "Intern.hpp"
class OfficeBlock {

private:

    Bureaucrat* _signer;
    Bureaucrat* _executor;
    Intern*     _intern;

public:

    // Coplien methods

    OfficeBlock();
    OfficeBlock(Bureaucrat* signer, Bureaucrat* executor, Intern* intern);
    ~OfficeBlock() {};

    // Getters

    Bureaucrat* getSigner() const;
    Bureaucrat* getExecutor() const;
    Intern*     getIntern() const;

    // Setters

    void        setSigner(Bureaucrat& signer);
    void        setExecutor(Bureaucrat& executor);
    void        setIntern(Intern& intern);
 
    // Methods

    void doBureaucracy(std::string name, std::string target);

};

#endif