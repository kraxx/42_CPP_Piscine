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

    // Exceptions

    class MissingInternException : public std::exception {

    public:

        MissingInternException() {};
        MissingInternException(MissingInternException const& rhs);
        MissingInternException& operator=(MissingInternException const& rhs);
        virtual ~MissingInternException() throw() {};

        virtual const char* what() const throw();
    };

    class MissingSignerException : public std::exception {

    public:

        MissingSignerException() {};
        MissingSignerException(MissingSignerException const& rhs);
        MissingSignerException& operator=(MissingSignerException const& rhs);
        virtual ~MissingSignerException() throw() {};

        virtual const char* what() const throw();
    };

    class MissingExecutorException : public std::exception {

    public:

        MissingExecutorException() {};
        MissingExecutorException(MissingExecutorException const& rhs);
        MissingExecutorException& operator=(MissingExecutorException const& rhs);
        virtual ~MissingExecutorException() throw() {};

        virtual const char* what() const throw();
    };

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