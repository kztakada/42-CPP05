#ifndef FORM_HPP
#define FORM_HPP

#include <exception>
#include <iostream>
#include <string>

#include "Bureaucrat.hpp"

class Form {
   public:
    Form();
    Form(std::string const &name, int gradeToSign, int gradeToExecute);
    ~Form();
    Form(Form const &other);
    Form &operator=(Form const &other);

    std::string const &getName() const;
    bool getIsSigned() const;
    int getGradeToSign() const;
    int getGradeToExecute() const;

    void beSigned(Bureaucrat const &b);

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
    bool _isSigned;
    int const _gradeToSign;
    int const _gradeToExecute;

    void _checkGrade(int grade);
};

// overload for std::ostream
std::ostream &operator<<(std::ostream &os, Form const &f);

#endif /* FORM_HPP */
