#ifndef AFORM_HPP
#define AFORM_HPP

#include <exception>
#include <iostream>
#include <string>

#include "Bureaucrat.hpp"

class AForm {
   public:
    AForm();
    AForm(std::string const &name, int gradeToSign, int gradeToExecute,
        std::string const &target);
    ~AForm();
    AForm(AForm const &other);
    AForm &operator=(AForm const &other);

    std::string const &getName() const;
    bool getIsSigned() const;
    int getGradeToSign() const;
    int getGradeToExecute() const;
    std::string const &getTarget() const;

    void beSigned(Bureaucrat const &b);
    virtual void execute(Bureaucrat const &executor) const = 0;

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

    class FormNotSignedException : public std::exception {
       public:
        FormNotSignedException();
        virtual ~FormNotSignedException() throw();
        virtual const char *what() const throw();
    };

   private:
    std::string const _name;
    bool _isSigned;
    int const _gradeToSign;
    int const _gradeToExecute;
    std::string const _target;

    void _checkGrade(int grade);
};

// overload for std::ostream
std::ostream &operator<<(std::ostream &os, AForm const &f);

#endif /* AFORM_HPP */
