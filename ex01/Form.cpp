#include "Form.hpp"

Form::Form()
    : _name("Default"),
      _isSigned(false),
      _gradeToSign(LOWEST_GRADE),
      _gradeToExecute(LOWEST_GRADE) {}

Form::Form(std::string const &name, int gradeToSign, int gradeToExecute)
    : _name(name),
      _isSigned(false),
      _gradeToSign(gradeToSign),
      _gradeToExecute(gradeToExecute) {
    _checkGrade(gradeToSign);
    _checkGrade(gradeToExecute);
}

Form::~Form() {}

Form::Form(Form const &other)
    : _name(other._name),
      _isSigned(other._isSigned),
      _gradeToSign(other._gradeToSign),
      _gradeToExecute(other._gradeToExecute) {}

Form &Form::operator=(Form const &other) {
    if (this != &other) {
        _isSigned = other._isSigned;
    }
    return *this;
}

// ---------------------------------------------------------------
// Public member functions

std::string const &Form::getName() const { return _name; }

bool Form::getIsSigned() const { return _isSigned; }

int Form::getGradeToSign() const { return _gradeToSign; }

int Form::getGradeToExecute() const { return _gradeToExecute; }

void Form::beSigned(Bureaucrat const &b) {
    if (b.getGrade() > _gradeToSign) {
        throw GradeTooLowException();
    }
    _isSigned = true;
}

// GradeTooHighException
Form::GradeTooHighException::GradeTooHighException() {}

Form::GradeTooHighException::~GradeTooHighException() throw() {}

const char *Form::GradeTooHighException::what() const throw() {
    return "Grade is too high";
}

// GradeTooLowException
Form::GradeTooLowException::GradeTooLowException() {}

Form::GradeTooLowException::~GradeTooLowException() throw() {}

const char *Form::GradeTooLowException::what() const throw() {
    return "Grade is too low";
}

// ---------------------------------------------------------------
// Private member functions
void Form::_checkGrade(int grade) {
    if (grade < HIGHEST_GRADE) {
        throw GradeTooHighException();
    }
    if (grade > LOWEST_GRADE) {
        throw GradeTooLowException();
    }
}

// ---------------------------------------------------------------
// Overloaded operators

std::ostream &operator<<(std::ostream &os, Form const &f) {
    os << "Form name: " << f.getName()
       << ", is signed: " << (f.getIsSigned() ? "true" : "false")
       << ", grade to sign: " << f.getGradeToSign()
       << ", grade to execute: " << f.getGradeToExecute() << ".";
    return os;
}
