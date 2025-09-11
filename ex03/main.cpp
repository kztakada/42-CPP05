#include <cassert>
#include <iostream>
#include <string>

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
    std::cout << "01---------------------------------" << std::endl;
    // Test default constructor
    {
        Intern someRandomIntern;
        AForm *rrf;
        AForm *scf;
        AForm *ppf;
        AForm *unknown = NULL;

        rrf = someRandomIntern.makeForm("robotomy request", "Bender");
        scf = someRandomIntern.makeForm("shrubbery creation", "Home");
        ppf = someRandomIntern.makeForm("presidential pardon", "Alice");
        unknown = someRandomIntern.makeForm("unknown", "Target");
        assert(rrf->getName() == "robotomy request");
        assert(rrf->getIsSigned() == false);
        assert(rrf->getGradeToSign() == 72);
        assert(rrf->getGradeToExecute() == 45);
        assert(rrf->getTarget() == "Bender");
        assert(scf->getName() == "shrubbery creation");
        assert(scf->getIsSigned() == false);
        assert(scf->getGradeToSign() == 145);
        assert(scf->getGradeToExecute() == 137);
        assert(scf->getTarget() == "Home");
        assert(ppf->getName() == "presidential pardon");
        assert(ppf->getIsSigned() == false);
        assert(ppf->getGradeToSign() == 25);
        assert(ppf->getGradeToExecute() == 5);
        assert(ppf->getTarget() == "Alice");
        assert(unknown == NULL);
        delete rrf;
        delete scf;
        delete ppf;
        delete unknown;
    }
    std::cout << "02---------------------------------" << std::endl;
    // Test parameterized constructor
    {
        const FormMapping formMappings[] = {
            {ShrubberyCreationForm::getFormName(),
             &ShrubberyCreationForm::create},
            {RobotomyRequestForm::getFormName(), &RobotomyRequestForm::create}};
        Intern someRandomIntern(formMappings);
        AForm *rrf;
        AForm *scf;
        AForm *ppf = NULL;
        AForm *unknown = NULL;

        rrf = someRandomIntern.makeForm("robotomy request", "Bender");
        scf = someRandomIntern.makeForm("shrubbery creation", "Home");
        ppf = someRandomIntern.makeForm("presidential pardon", "Alice");
        unknown = someRandomIntern.makeForm("unknown", "Target");
        assert(rrf->getName() == "robotomy request");
        assert(rrf->getIsSigned() == false);
        assert(rrf->getGradeToSign() == 72);
        assert(rrf->getGradeToExecute() == 45);
        assert(rrf->getTarget() == "Bender");
        assert(scf->getName() == "shrubbery creation");
        assert(scf->getIsSigned() == false);
        assert(scf->getGradeToSign() == 145);
        assert(scf->getGradeToExecute() == 137);
        assert(scf->getTarget() == "Home");
        assert(ppf == NULL);
        assert(unknown == NULL);
        delete rrf;
        delete scf;
        delete ppf;
        delete unknown;
    }
    std::cout << "03---------------------------------" << std::endl;
    // Test copy constructor
    {
        Intern intern1;
        Intern intern2(intern1);
        AForm *form1 = intern1.makeForm("robotomy request", "Bender");
        AForm *form2 = intern2.makeForm("robotomy request", "Bender");
        assert(form1->getName() == form2->getName());
        assert(form1->getIsSigned() == form2->getIsSigned());
        assert(form1->getGradeToSign() == form2->getGradeToSign());
        assert(form1->getGradeToExecute() == form2->getGradeToExecute());
        assert(form1->getTarget() == form2->getTarget());
        delete form1;
        delete form2;
        std::cout << "---------------------------------" << std::endl;
    }
    {
        const FormMapping formMappings[] = {
            {ShrubberyCreationForm::getFormName(),
             &ShrubberyCreationForm::create},
            {RobotomyRequestForm::getFormName(), &RobotomyRequestForm::create}};
        Intern intern1(formMappings);
        Intern intern2(intern1);
        AForm *form1 = intern1.makeForm("robotomy request", "Bender");
        AForm *form2 = intern2.makeForm("robotomy request", "Bender");
        assert(form1->getName() == form2->getName());
        assert(form1->getIsSigned() == form2->getIsSigned());
        assert(form1->getGradeToSign() == form2->getGradeToSign());
        assert(form1->getGradeToExecute() == form2->getGradeToExecute());
        assert(form1->getTarget() == form2->getTarget());
        delete form1;
        delete form2;
        std::cout << "Copy constructor test passed." << std::endl;
    }
    std::cout << "04---------------------------------" << std::endl;
    // Test assignment operator
    {
        Intern intern1;
        Intern intern2;
        intern2 = intern1;
        AForm *form1 = intern1.makeForm("robotomy request", "Bender");
        AForm *form2 = intern2.makeForm("robotomy request", "Bender");
        assert(form1->getName() == form2->getName());
        assert(form1->getIsSigned() == form2->getIsSigned());
        assert(form1->getGradeToSign() == form2->getGradeToSign());
        assert(form1->getGradeToExecute() == form2->getGradeToExecute());
        assert(form1->getTarget() == form2->getTarget());
        delete form1;
        delete form2;
        std::cout << "---------------------------------" << std::endl;
    }
    {
        const FormMapping formMappings[] = {
            {ShrubberyCreationForm::getFormName(),
             &ShrubberyCreationForm::create},
            {RobotomyRequestForm::getFormName(), &RobotomyRequestForm::create}};
        Intern intern1(formMappings);
        Intern intern2;
        intern2 = intern1;
        AForm *form1 = intern1.makeForm("robotomy request", "Bender");
        AForm *form2 = intern2.makeForm("robotomy request", "Bender");
        assert(form1->getName() == form2->getName());
        assert(form1->getIsSigned() == form2->getIsSigned());
        assert(form1->getGradeToSign() == form2->getGradeToSign());
        assert(form1->getGradeToExecute() == form2->getGradeToExecute());
        assert(form1->getTarget() == form2->getTarget());
        delete form1;
        delete form2;
        std::cout << "Assignment operator test passed." << std::endl;
    }
    std::cout << "---------------------------------" << std::endl;
    std::cout << "All tests passed!" << std::endl;
    return 0;
}