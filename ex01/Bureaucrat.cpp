#include "Bureaucrat.hpp"

#include "Form.hpp"

Bureaucrat::Bureaucrat() : _name("Default"), _grade(LOWEST_GRADE) {}

Bureaucrat::Bureaucrat(std::string const &name, int grade) : _name(name) {
    _checkGrade(grade);
    _grade = grade;
}

Bureaucrat::~Bureaucrat() {}

Bureaucrat::Bureaucrat(Bureaucrat const &other)
    : _name(other._name), _grade(other._grade) {}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &other) {
    if (this != &other) {
        // _name is const, so we don't assign it
        _grade = other._grade;
    }
    return *this;
}

// ---------------------------------------------------------------
// Public member functions

void Bureaucrat::promote() {
    _checkGrade(_grade - 1);
    _grade--;
}

void Bureaucrat::demote() {
    _checkGrade(_grade + 1);
    _grade++;
}

void Bureaucrat::signForm(Form &f) const {
    if (f.getIsSigned()) {
        std::cout << _name << " couldn't sign " << f.getName()
                  << " because form is already signed." << std::endl;
        return;
    }
    try {
        f.beSigned(*this);
        std::cout << _name << " signed " << f.getName() << std::endl;
    } catch (std::exception &e) {
        std::cout << _name << " couldn't sign " << f.getName() << " because "
                  << e.what() << std::endl;
        return;
    }
}

std::string const &Bureaucrat::getName() const { return _name; }

int Bureaucrat::getGrade() const { return _grade; }

// GradeTooHighException
Bureaucrat::GradeTooHighException::GradeTooHighException() {}

Bureaucrat::GradeTooHighException::~GradeTooHighException() throw() {}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
    return "Grade is too high";
}

// GradeTooLowException
Bureaucrat::GradeTooLowException::GradeTooLowException() {}

Bureaucrat::GradeTooLowException::~GradeTooLowException() throw() {}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
    return "Grade is too low";
}

// ---------------------------------------------------------------
// Private member functions

void Bureaucrat::_checkGrade(int grade) {
    if (grade < HIGHEST_GRADE) {
        throw GradeTooHighException();
    } else if (grade > LOWEST_GRADE) {
        throw GradeTooLowException();
    }
}

// ---------------------------------------------------------------
// Overloaded operators

std::ostream &operator<<(std::ostream &os, Bureaucrat const &b) {
    os << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
    return os;
}
