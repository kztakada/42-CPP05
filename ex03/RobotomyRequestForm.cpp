#include "RobotomyRequestForm.hpp"

#include <cstdlib>
#include <ctime>
#include <iostream>

std::string const RobotomyRequestForm::_formName = "robotomy request";

AForm *RobotomyRequestForm::create(std::string const &target) {
    return new RobotomyRequestForm(target);
}

std::string const RobotomyRequestForm::getFormName() { return _formName; }

RobotomyRequestForm::RobotomyRequestForm()
    : AForm(_formName, _requiredGradeToSign, _requiredGradeToExecute,
          "default target") {}

RobotomyRequestForm::RobotomyRequestForm(std::string const &target)
    : AForm(_formName, _requiredGradeToSign, _requiredGradeToExecute, target) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &other)
    : AForm(other) {}

RobotomyRequestForm &RobotomyRequestForm::operator=(
    RobotomyRequestForm const &other) {
    AForm::operator=(other);
    return *this;
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const {
    AForm::execute(executor);
    static bool seeded = false;
    if (!seeded) {
        std::srand(std::time(0));
        seeded = true;
    }
    std::cout << "Bzzzzzz... Vrrrrrr... (drilling noises)" << std::endl;
    if (std::rand() % 2) {
        std::cout << getTarget() << " has been robotomized successfully."
                  << std::endl;
    } else {
        std::cout << "Failed to robotomize " << getTarget() << "." << std::endl;
    }
}
