#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

class RobotomyRequestForm : public AForm {
   public:
    RobotomyRequestForm();
    RobotomyRequestForm(std::string const &target);
    ~RobotomyRequestForm();
    RobotomyRequestForm(RobotomyRequestForm const &other);
    RobotomyRequestForm &operator=(RobotomyRequestForm const &other);

    void execute(Bureaucrat const &executor) const;

   private:
    static std::string const _formName;
    static int const _requiredGradeToSign = 72;
    static int const _requiredGradeToExecute = 45;
};

#endif /* ROBOTOMYREQUESTFORM_HPP */
