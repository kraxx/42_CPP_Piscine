#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <stdexcept>
# include <string>

class Bureaucrat {

private:

    const std::string _name;
    int               _grade;

public:

    class GradeTooHighException : public std::exception {

    public:

        GradeTooHighException() {};
        GradeTooHighException(GradeTooHighException const& rhs);
        GradeTooHighException& operator=(GradeTooHighException const& rhs);
        virtual ~GradeTooHighException() throw() {};

        virtual const char* what() const throw();
    };

    class GradeTooLowException : public std::exception {

    public:

        GradeTooLowException() {};
        GradeTooLowException(GradeTooLowException const& rhs);
        GradeTooLowException& operator=(GradeTooLowException const& rhs);
        virtual ~GradeTooLowException() throw() {};

        virtual const char* what() const throw();
    };

    Bureaucrat();
    Bureaucrat(std::string name, int grade);
    Bureaucrat(Bureaucrat const& rhs);
    Bureaucrat& operator=(Bureaucrat const& rhs);
    ~Bureaucrat() {};

    const std::string getName() const ;
    int               getGrade() const ;
    void              incrementGrade(int n);
    void              decrementGrade(int n);
};

std::ostream&   operator<<(std::ostream& output, Bureaucrat const& rhs);

#endif