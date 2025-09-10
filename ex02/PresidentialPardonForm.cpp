#include "PresidentialPardonForm.hpp"

#include <iostream>

std::string const PresidentialPardonForm::_formName = "presidential pardon";

PresidentialPardonForm::PresidentialPardonForm()
    : AForm(_formName, _requiredGradeToSign, _requiredGradeToExecute,
          "default target") {}

PresidentialPardonForm::PresidentialPardonForm(std::string const &target)
    : AForm(_formName, _requiredGradeToSign, _requiredGradeToExecute, target) {}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm::PresidentialPardonForm(
    PresidentialPardonForm const &other)
    : AForm(other) {}

PresidentialPardonForm &PresidentialPardonForm::operator=(
    PresidentialPardonForm const &other) {
    AForm::operator=(other);
    return *this;
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const {
    AForm::execute(executor);
    std::cout << getTarget() << " has been pardoned by Zaphod Beeblebrox."
              << std::endl;
}
