#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

struct FormMapping {
    std::string formName;
    AForm *(*createFunc)(std::string const &target);
};

class Intern {
   public:
    template <int N>
    Intern(const FormMapping (&formMappings)[N]) {
        _size = N;
        _formMappings = new FormMapping[N];
        for (int i = 0; i < N; ++i) {
            _formMappings[i] = formMappings[i];
        }
    };
    Intern();
    ~Intern();
    Intern(Intern const &other);
    Intern &operator=(Intern const &other);

    AForm *makeForm(
        std::string const &formName, std::string const &target) const;

   private:
    FormMapping *_formMappings;
    int _size;
};

#endif /* INTERN_HPP */
