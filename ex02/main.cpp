#include <cassert>
#include <iostream>
#include <string>

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

const char *TOO_HIGH_MSG = "Grade is too high";
const char *TOO_LOW_MSG = "Grade is too low";
const char *NOT_SIGNED_MSG = "Form is not signed";

// Test cases for Form cases
int main() {
    // Test default constructor
    {
        PresidentialPardonForm form;
        assert(form.getName() == "Presidential Pardon Form");
        assert(form.getIsSigned() == false);
        assert(form.getGradeToSign() == 25);
        assert(form.getGradeToExecute() == 5);
        assert(form.getTarget() == "default target");

        RobotomyRequestForm rform;
        assert(rform.getName() == "Robotomy Request Form");
        assert(rform.getIsSigned() == false);
        assert(rform.getGradeToSign() == 72);
        assert(rform.getGradeToExecute() == 45);
        assert(rform.getTarget() == "default target");

        ShrubberyCreationForm sform;
        assert(sform.getName() == "Shrubbery Creation Form");
        assert(sform.getIsSigned() == false);
        assert(sform.getGradeToSign() == 145);
        assert(sform.getGradeToExecute() == 137);
        assert(sform.getTarget() == "default target");

        std::cout << "Default constructor test passed." << std::endl;
    }
    // Test parameterized constructor
    {
        RobotomyRequestForm form("TargetA");
        assert(form.getName() == "Robotomy Request Form");
        assert(form.getIsSigned() == false);
        assert(form.getGradeToSign() == 72);
        assert(form.getGradeToExecute() == 45);
        assert(form.getTarget() == "TargetA");

        RobotomyRequestForm rform("TargetA");
        assert(rform.getName() == "Robotomy Request Form");
        assert(rform.getIsSigned() == false);
        assert(rform.getGradeToSign() == 72);
        assert(rform.getGradeToExecute() == 45);
        assert(rform.getTarget() == "TargetA");

        ShrubberyCreationForm sform("TargetA");
        assert(sform.getName() == "Shrubbery Creation Form");
        assert(sform.getIsSigned() == false);
        assert(sform.getGradeToSign() == 145);
        assert(sform.getGradeToExecute() == 137);
        assert(sform.getTarget() == "TargetA");

        std::cout << "Parameterized constructor test passed." << std::endl;
    }
    // Test copy constructor
    {
        ShrubberyCreationForm form1("TargetB");
        form1.beSigned(Bureaucrat("Signer", 100));
        ShrubberyCreationForm form2(form1);
        assert(form2.getName() == form1.getName());
        assert(form2.getIsSigned() == form1.getIsSigned());
        assert(form2.getGradeToSign() == form1.getGradeToSign());
        assert(form2.getGradeToExecute() == form1.getGradeToExecute());
        assert(form2.getTarget() == form1.getTarget());

        RobotomyRequestForm rform1("TargetB");
        rform1.beSigned(Bureaucrat("Signer", 70));
        RobotomyRequestForm rform2(rform1);
        assert(rform2.getName() == rform1.getName());
        assert(rform2.getIsSigned() == rform1.getIsSigned());
        assert(rform2.getGradeToSign() == rform1.getGradeToSign());
        assert(rform2.getGradeToExecute() == rform1.getGradeToExecute());
        assert(rform2.getTarget() == rform1.getTarget());

        PresidentialPardonForm pform1("TargetB");
        pform1.beSigned(Bureaucrat("Signer", 20));
        PresidentialPardonForm pform2(pform1);
        assert(pform2.getName() == pform1.getName());
        assert(pform2.getIsSigned() == pform1.getIsSigned());
        assert(pform2.getGradeToSign() == pform1.getGradeToSign());
        assert(pform2.getGradeToExecute() == pform1.getGradeToExecute());
        assert(pform2.getTarget() == pform1.getTarget());

        std::cout << "Copy constructor test passed." << std::endl;
    }
    // Test assignment operator
    {
        PresidentialPardonForm form1("TargetC");
        form1.beSigned(Bureaucrat("Signer", 20));
        PresidentialPardonForm form2;
        form2 = form1;
        assert(form2.getName() == form1.getName());
        assert(form2.getIsSigned() == form1.getIsSigned());
        assert(form2.getGradeToSign() == form1.getGradeToSign());
        assert(form2.getGradeToExecute() == form1.getGradeToExecute());
        assert(form2.getTarget() == "default target");

        RobotomyRequestForm rform1("TargetC");
        rform1.beSigned(Bureaucrat("Signer", 70));
        RobotomyRequestForm rform2;
        rform2 = rform1;
        assert(rform2.getName() == rform1.getName());
        assert(rform2.getIsSigned() == rform1.getIsSigned());
        assert(rform2.getGradeToSign() == rform1.getGradeToSign());
        assert(rform2.getGradeToExecute() == rform1.getGradeToExecute());
        assert(rform2.getTarget() == "default target");

        ShrubberyCreationForm sform1("TargetC");
        sform1.beSigned(Bureaucrat("Signer", 100));
        ShrubberyCreationForm sform2;
        sform2 = sform1;
        assert(sform2.getName() == sform1.getName());
        assert(sform2.getIsSigned() == sform1.getIsSigned());
        assert(sform2.getGradeToSign() == sform1.getGradeToSign());
        assert(sform2.getGradeToExecute() == sform1.getGradeToExecute());
        assert(sform2.getTarget() == "default target");

        std::cout << "Assignment operator test passed." << std::endl;
    }
    // Test signing and executing forms
    {
        Bureaucrat signer("Signer", 1);
        Bureaucrat executor("Executor", 1);
        std::cout << "01---------------------------------" << std::endl;
        PresidentialPardonForm pform("TargetD");
        signer.signForm(pform);
        assert(pform.getIsSigned() == true);
        executor.executeForm(pform);
        std::cout << "02---------------------------------" << std::endl;
        RobotomyRequestForm rform("TargetD");
        signer.signForm(rform);
        assert(rform.getIsSigned() == true);
        executor.executeForm(rform);
        std::cout << "03---------------------------------" << std::endl;
        ShrubberyCreationForm sform("TargetD");
        signer.signForm(sform);
        assert(sform.getIsSigned() == true);
        executor.executeForm(sform);
        std::cout << "---------------------------------" << std::endl;
        std::cout << "Signing and executing forms test passed." << std::endl;
    }
    // Test exceptions for signing
    {
        Bureaucrat lowRanker("LowRanker", 150);
        PresidentialPardonForm pform("TargetE");
        try {
            pform.beSigned(lowRanker);
            assert(false);  // Should not reach here
        } catch (std::exception &e) {
            assert(std::string(e.what()) == TOO_LOW_MSG);
        }
    }
    {
        Bureaucrat lowRanker("LowRanker", 150);
        RobotomyRequestForm beSigned("TargetE");
        try {
            beSigned.beSigned(lowRanker);
            assert(false);  // Should not reach here
        } catch (std::exception &e) {
            assert(std::string(e.what()) == TOO_LOW_MSG);
        }
    }
    {
        Bureaucrat lowRanker("LowRanker", 150);
        ShrubberyCreationForm sform("TargetE");
        try {
            sform.beSigned(lowRanker);
            assert(false);  // Should not reach here
        } catch (std::exception &e) {
            assert(std::string(e.what()) == TOO_LOW_MSG);
        }
    }
    {
        std::cout << "01---------------------------------" << std::endl;
        Bureaucrat lowRanker("LowRanker", 150);
        PresidentialPardonForm pform("TargetE");
        lowRanker.signForm(pform);
    }
    {
        std::cout << "02---------------------------------" << std::endl;
        Bureaucrat lowRanker("LowRanker", 150);
        RobotomyRequestForm rform("TargetE");
        lowRanker.signForm(rform);
    }
    {
        std::cout << "03---------------------------------" << std::endl;
        Bureaucrat lowRanker("LowRanker", 150);
        ShrubberyCreationForm sform("TargetE");
        lowRanker.signForm(sform);
        std::cout << "---------------------------------" << std::endl;
    }
    std::cout << "Signing exceptions test passed." << std::endl;
    // Test exceptions for executing
    {
        Bureaucrat executor("Executor", 150);
        PresidentialPardonForm pform("TargetF");
        try {
            pform.execute(executor);
            assert(false);  // Should not reach here
        } catch (std::exception &e) {
            assert(std::string(e.what()) == NOT_SIGNED_MSG);
        }
    }
    {
        Bureaucrat executor("Executor", 150);
        RobotomyRequestForm rform("TargetF");
        try {
            rform.execute(executor);
            assert(false);  // Should not reach here
        } catch (std::exception &e) {
            assert(std::string(e.what()) == NOT_SIGNED_MSG);
        }
    }
    {
        Bureaucrat executor("Executor", 150);
        ShrubberyCreationForm sform("TargetF");
        try {
            sform.execute(executor);
            assert(false);  // Should not reach here
        } catch (std::exception &e) {
            assert(std::string(e.what()) == NOT_SIGNED_MSG);
        }
    }
    {
        std::cout << "01---------------------------------" << std::endl;
        Bureaucrat executor("Executor", 150);
        PresidentialPardonForm pform("TargetF");
        executor.executeForm(pform);
    }
    {
        std::cout << "02---------------------------------" << std::endl;
        Bureaucrat executor("Executor", 150);
        RobotomyRequestForm rform("TargetF");
        executor.executeForm(rform);
    }
    {
        std::cout << "03---------------------------------" << std::endl;
        Bureaucrat executor("Executor", 150);
        ShrubberyCreationForm sform("TargetF");
        executor.executeForm(sform);
        std::cout << "---------------------------------" << std::endl;
    }
    std::cout << "Executing exceptions test passed." << std::endl;

    std::cout << "All tests passed!" << std::endl;
    return 0;
}