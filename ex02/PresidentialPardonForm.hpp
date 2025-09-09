#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
   public:
    PresidentialPardonForm();
    PresidentialPardonForm(std::string const &target);
    ~PresidentialPardonForm();
    PresidentialPardonForm(PresidentialPardonForm const &other);
    PresidentialPardonForm &operator=(PresidentialPardonForm const &other);

    void execute(Bureaucrat const &executor) const;

   private:
    static std::string const _formName;
    static int const _requiredGradeToSign = 25;
    static int const _requiredGradeToExecute = 5;
};

#endif /* PRESIDENTIALPARDONFORM_HPP */
