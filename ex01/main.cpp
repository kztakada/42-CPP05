#include <cassert>
#include <iostream>
#include <string>

#include "Bureaucrat.hpp"
#include "Form.hpp"

const char *TOO_HIGH_MSG = "Grade is too high";
const char *TOO_LOW_MSG = "Grade is too low";

// Test cases for Form cases
int main()
{
    // Test default constructor
    Form f1;
    assert(f1.getName() == "Default");
    assert(f1.getIsSigned() == false);
    assert(f1.getGradeToSign() == 150);
    assert(f1.getGradeToExecute() == 150);
    std::cout << f1 << std::endl;

    // Test parameterized constructor with valid grades
    Form f2("FormA", 42, 84);
    assert(f2.getName() == "FormA");
    assert(f2.getIsSigned() == false);
    assert(f2.getGradeToSign() == 42);
    assert(f2.getGradeToExecute() == 84);
    std::cout << f2 << std::endl;

    // Test copy constructor
    Form f3(f2);
    assert(f3.getName() == "FormA");
    assert(f3.getIsSigned() == false);
    assert(f3.getGradeToSign() == 42);
    assert(f3.getGradeToExecute() == 84);
    std::cout << f3 << std::endl;

    // Test assignment operator
    Form f4;
    f4 = f2;
    assert(f4.getName() == "Default"); // Name is const, cannot be changed
    assert(f4.getIsSigned() == false);
    assert(f4.getGradeToSign() == 150);
    // GradeToSign is const, cannot be changed
    assert(f4.getGradeToExecute() == 150);
    // GradeToExecute is const, cannot be changed
    std::cout << f4 << std::endl;

    // Test parameterized constructor with invalid high grade to sign
    try
    {
        Form f5("FormB", 0, 50);
        assert(false); // Should not reach here
    }
    catch (const std::exception &e)
    {
        assert(std::string(e.what()) == TOO_HIGH_MSG);
    }

    // Test parameterized constructor with invalid low grade to sign
    try
    {
        Form f6("FormC", 151, 50);
        assert(false); // Should not reach here
    }
    catch (const std::exception &e)
    {
        assert(std::string(e.what()) == TOO_LOW_MSG);
    }

    // Test parameterized constructor with invalid high grade to execute
    try
    {
        Form f7("FormD", 50, 0);
        assert(false); // Should not reach here
    }
    catch (const std::exception &e)
    {
        assert(std::string(e.what()) == TOO_HIGH_MSG);
    }

    // Test parameterized constructor with invalid low grade to execute
    try
    {
        Form f8("FormE", 50, 151);
        assert(false); // Should not reach here
    }
    catch (const std::exception &e)
    {
        assert(std::string(e.what()) == TOO_LOW_MSG);
    }

    // Test parameterized constructor with both grades invalid
    try
    {
        Form f9("FormF", 0, 151);
        assert(false); // Should not reach here
    }
    catch (const std::exception &e)
    {
        assert(std::string(e.what()) == TOO_HIGH_MSG);
    }
    try
    {
        Form f9("FormF", 151, 0);
        assert(false); // Should not reach here
    }
    catch (const std::exception &e)
    {
        assert(std::string(e.what()) == TOO_LOW_MSG);
    }
    std::cout << "01---------------------------------" << std::endl;
    // Test beSigned with sufficient grade
    try
    {
        Bureaucrat b1("Alice", 40);
        Form f9("FormF", 42, 84);
        std::cout << f9 << std::endl;
        assert(f9.getIsSigned() == false);
        b1.signForm(f9);
        assert(f9.getIsSigned() == true);
        std::cout << f9 << std::endl;
    }
    catch (const std::exception &e)
    {
        assert(false); // Should not reach here
    }
    std::cout << "02---------------------------------" << std::endl;
    // Test beSigned with insufficient grade
    try
    {
        Bureaucrat b2("Bob", 50);
        Form f10("FormG", 42, 84);
        std::cout << f10 << std::endl;
        assert(f10.getIsSigned() == false);
        b2.signForm(f10);
        assert(f10.getIsSigned() == false);
        std::cout << f10 << std::endl;
    }
    catch (const std::exception &e)
    {
        assert(false); // Should not reach here
    }
    std::cout << "03---------------------------------" << std::endl;
    // Test beSigned on already signed form
    try
    {
        Bureaucrat b3("Charlie", 30);
        Form f11("FormH", 42, 84);
        std::cout << f11 << std::endl;
        assert(f11.getIsSigned() == false);
        b3.signForm(f11); // First signing
        assert(f11.getIsSigned() == true);
        std::cout << f11 << std::endl;
        b3.signForm(f11); // Attempt to sign again
        assert(f11.getIsSigned() == true);
        std::cout << f11 << std::endl;
    }
    catch (const std::exception &e)
    {
        assert(false); // Should not reach here
    }
    std::cout << "04---------------------------------" << std::endl;
    // Form unit test
    // Test beSigned with sufficient grade
    Bureaucrat b4("David", 40);
    Form f12("FormI", 42, 84);
    try
    {
        std::cout << f12 << std::endl;
        assert(f12.getIsSigned() == false);
        f12.beSigned(b4);
        assert(f12.getIsSigned() == true);
        std::cout << f12 << std::endl;
    }
    catch (const std::exception &e)
    {
        assert(false); // Should not reach here
    }
    std::cout << "05---------------------------------" << std::endl;
    // Form unit test
    // Test beSigned with insufficient grade
    Bureaucrat b5("Eve", 50);
    Form f13("FormJ", 42, 84);
    try
    {
        std::cout << f13 << std::endl;
        assert(f13.getIsSigned() == false);
        f13.beSigned(b5);
        assert(false); // Should not reach here
    }
    catch (const std::exception &e)
    {
        assert(std::string(e.what()) == TOO_LOW_MSG);
        assert(f13.getIsSigned() == false);
        std::cout << f13 << std::endl;
    }
    std::cout << "06---------------------------------" << std::endl;
    // Form unit test
    // Test beSigned on already signed form
    Bureaucrat b6("Frank", 30);
    Form f14("FormK", 42, 84);
    try
    {
        std::cout << f14 << std::endl;
        assert(f14.getIsSigned() == false);
        f14.beSigned(b6); // First signing
        assert(f14.getIsSigned() == true);
        f14.beSigned(b6); // Attempt to sign again
        assert(f14.getIsSigned() == true);
        std::cout << f14 << std::endl;
    }
    catch (const std::exception &e)
    {
        assert(false); // Should not reach here
    }
    std::cout << "---------------------------------" << std::endl;
    std::cout << "All tests passed!" << std::endl;

    return 0;
}