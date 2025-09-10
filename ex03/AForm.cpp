#include "AForm.hpp"

AForm::AForm()
    : _name("Default"),
      _isSigned(false),
      _gradeToSign(LOWEST_GRADE),
      _gradeToExecute(LOWEST_GRADE),
      _target("Default") {}

AForm::AForm(std::string const &name, int gradeToSign, int gradeToExecute,
    std::string const &target)
    : _name(name),
      _isSigned(false),
      _gradeToSign(gradeToSign),
      _gradeToExecute(gradeToExecute),
      _target(target) {
    _checkGrade(gradeToSign);
    _checkGrade(gradeToExecute);
}

AForm::~AForm() {}

AForm::AForm(AForm const &other)
    : _name(other._name),
      _isSigned(other._isSigned),
      _gradeToSign(other._gradeToSign),
      _gradeToExecute(other._gradeToExecute),
      _target(other._target) {}

AForm &AForm::operator=(AForm const &other) {
    if (this != &other) {
        _isSigned = other._isSigned;
    }
    return *this;
}

// ---------------------------------------------------------------
// Public member functions

std::string const &AForm::getName() const { return _name; }

bool AForm::getIsSigned() const { return _isSigned; }

int AForm::getGradeToSign() const { return _gradeToSign; }

int AForm::getGradeToExecute() const { return _gradeToExecute; }

std::string const &AForm::getTarget() const { return _target; }

void AForm::beSigned(Bureaucrat const &b) {
    if (b.getGrade() > _gradeToSign) {
        throw AForm::GradeTooLowException();
    }
    _isSigned = true;
}

void AForm::execute(Bureaucrat const &executor) const {
    if (!_isSigned) {
        throw AForm::FormNotSignedException();
    }
    if (executor.getGrade() > _gradeToExecute) {
        throw AForm::GradeTooLowException();
    }
    // Actual execution logic would go here in derived classes
}

// GradeTooHighException
AForm::GradeTooHighException::GradeTooHighException() {}

AForm::GradeTooHighException::~GradeTooHighException() throw() {}

const char *AForm::GradeTooHighException::what() const throw() {
    return "Grade is too high";
}

// GradeTooLowException
AForm::GradeTooLowException::GradeTooLowException() {}

AForm::GradeTooLowException::~GradeTooLowException() throw() {}

const char *AForm::GradeTooLowException::what() const throw() {
    return "Grade is too low";
}

// FormNotSignedException
AForm::FormNotSignedException::FormNotSignedException() {}

AForm::FormNotSignedException::~FormNotSignedException() throw() {}

const char *AForm::FormNotSignedException::what() const throw() {
    return "Form is not signed";
}

// ---------------------------------------------------------------
// Private member functions
void AForm::_checkGrade(int grade) {
    if (grade < HIGHEST_GRADE) {
        throw AForm::GradeTooHighException();
    }
    if (grade > LOWEST_GRADE) {
        throw AForm::GradeTooLowException();
    }
}

// ---------------------------------------------------------------
// Overloaded operators

std::ostream &operator<<(std::ostream &os, AForm const &f) {
    os << "Form name: " << f.getName()
       << ", is signed: " << (f.getIsSigned() ? "true" : "false")
       << ", grade to sign: " << f.getGradeToSign()
       << ", grade to execute: " << f.getGradeToExecute() << ".";
    return os;
}
