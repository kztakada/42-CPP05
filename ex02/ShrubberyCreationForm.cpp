#include "ShrubberyCreationForm.hpp"

#include <fstream>
#include <iostream>

std::string const ShrubberyCreationForm::_formName = "Shrubbery Creation Form";

ShrubberyCreationForm::ShrubberyCreationForm()
    : AForm(_formName, _requiredGradeToSign, _requiredGradeToExecute,
          "default target") {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target)
    : AForm(_formName, _requiredGradeToSign, _requiredGradeToExecute, target) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &other)
    : AForm(other) {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(
    ShrubberyCreationForm const &other) {
    AForm::operator=(other);
    return *this;
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const {
    AForm::execute(executor);
    std::ofstream ofs((getTarget() + "_shrubbery").c_str());
    if (!ofs) {
        std::cerr << "Error: Could not open file " << getTarget()
                  << "_shrubbery for writing." << std::endl;
        return;
    }
    ofs << "       _-_\n"
           "    /~~   ~~\\\n"
           " /~~         ~~\\\n"
           "{               }\n"
           " \\  _-     -_  /\n"
           "   ~  \\\\ //  ~\n"
           "_- -   | | _- _\n"
           "  _ -  | |   -_\n"
           "      // \\\\\n";
    ofs.close();
}
