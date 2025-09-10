#include "Intern.hpp"

Intern::Intern() : _size(3) {
    _formMappings = new FormMapping[_size];
    _formMappings[0].formName = ShrubberyCreationForm::getFormName();
    _formMappings[0].createFunc = &ShrubberyCreationForm::create;
    _formMappings[1].formName = RobotomyRequestForm::getFormName();
    _formMappings[1].createFunc = &RobotomyRequestForm::create;
    _formMappings[2].formName = PresidentialPardonForm::getFormName();
    _formMappings[2].createFunc = &PresidentialPardonForm::create;
}

Intern::~Intern() { delete[] _formMappings; }

Intern::Intern(Intern const &other) {
    _size = other._size;
    _formMappings = new FormMapping[_size];
    for (int i = 0; i < _size; ++i) {
        _formMappings[i] = other._formMappings[i];
    }
}

Intern &Intern::operator=(Intern const &other) {
    if (this != &other) {
        delete[] _formMappings;
        _size = other._size;
        _formMappings = new FormMapping[_size];
        for (int i = 0; i < _size; ++i) {
            _formMappings[i] = other._formMappings[i];
        }
    }
    return *this;
}

AForm *Intern::makeForm(
    std::string const &formName, std::string const &target) const {
    for (int i = 0; i < _size; ++i) {
        if (_formMappings[i].formName == formName) {
            std::cout << "Intern creates " << formName << std::endl;
            return _formMappings[i].createFunc(target);
        }
    }
    std::cout << "Intern Error: Intern could not find the form: " << formName
              << std::endl;
    return NULL;
}
