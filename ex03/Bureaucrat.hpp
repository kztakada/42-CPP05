#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <exception>
#include <iostream>
#include <string>

const int HIGHEST_GRADE = 1;
const int LOWEST_GRADE = 150;

class AForm;

class Bureaucrat {
   public:
    Bureaucrat();
    Bureaucrat(std::string const &name, int grade);
    ~Bureaucrat();
    Bureaucrat(Bureaucrat const &other);
    Bureaucrat &operator=(Bureaucrat const &other);

    void promote();
    void demote();
    void signForm(AForm &form) const;
    void executeForm(AForm const &form) const;

    std::string const &getName() const;
    int getGrade() const;

    class GradeTooHighException : public std::exception {
       public:
        GradeTooHighException();
        virtual ~GradeTooHighException() throw();
        virtual const char *what() const throw();
    };

    class GradeTooLowException : public std::exception {
       public:
        GradeTooLowException();
        virtual ~GradeTooLowException() throw();
        virtual const char *what() const throw();
    };

   private:
    std::string const _name;
    int _grade;

    void _checkGrade(int grade);
};

// overload for std::ostream
std::ostream &operator<<(std::ostream &os, Bureaucrat const &b);

#endif /* BUREAUCRAT_HPP */
