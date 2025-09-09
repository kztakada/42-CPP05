#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm {
   public:
    ShrubberyCreationForm();
    ShrubberyCreationForm(std::string const &target);
    ~ShrubberyCreationForm();
    ShrubberyCreationForm(ShrubberyCreationForm const &other);
    ShrubberyCreationForm &operator=(ShrubberyCreationForm const &other);

    void execute(Bureaucrat const &executor) const;

   private:
    static std::string const _formName;
    static int const _requiredGradeToSign = 145;
    static int const _requiredGradeToExecute = 137;
};

#endif /* SHRUBBERYCREATIONFORM_HPP */
