#include <cassert>
#include <iostream>
#include <string>

#include "Bureaucrat.hpp"

const char *TOO_HIGH_MSG = "Grade is too high";
const char *TOO_LOW_MSG = "Grade is too low";

int main() {
    // Test default constructor
    Bureaucrat b1;
    assert(b1.getName() == "Default");
    assert(b1.getGrade() == 150);
    std::cout << b1 << std::endl;

    // Test parameterized constructor with valid grade
    Bureaucrat b2("Alice", 42);
    assert(b2.getName() == "Alice");
    assert(b2.getGrade() == 42);
    std::cout << b2 << std::endl;

    // Test copy constructor
    Bureaucrat b7(b2);
    assert(b7.getName() == "Alice");
    assert(b7.getGrade() == 42);
    std::cout << b7 << std::endl;

    // Test assignment operator
    Bureaucrat b8;
    b8 = b2;
    assert(b8.getName() == "Default");  // Name is const, cannot be changed
    assert(b8.getGrade() == 42);
    std::cout << b8 << std::endl;

    // Test parameterized constructor with invalid high grade
    try {
        Bureaucrat b3("Bob", 0);
        assert(false);  // Should not reach here
    } catch (const std::exception &e) {
        assert(std::string(e.what()) == TOO_HIGH_MSG);
    }

    // Test parameterized constructor with invalid low grade
    try {
        Bureaucrat b4("Charlie", 151);
        assert(false);  // Should not reach here
    } catch (const std::exception &e) {
        assert(std::string(e.what()) == TOO_LOW_MSG);
    }

    // Test incrementing grade
    Bureaucrat b5("Dave", 3);
    b5.promote();
    assert(b5.getGrade() == 2);
    b5.promote();
    assert(b5.getGrade() == 1);
    try {
        b5.promote();
        assert(false);  // Should not reach here
    } catch (const std::exception &e) {
        assert(std::string(e.what()) == TOO_HIGH_MSG);
    }

    // Test decrementing grade
    Bureaucrat b6("Eve", 149);
    b6.demote();
    assert(b6.getGrade() == 150);
    try {
        b6.demote();
        assert(false);  // Should not reach here
    } catch (const std::exception &e) {
        assert(std::string(e.what()) == TOO_LOW_MSG);
    }

    std::cout << "All tests passed!" << std::endl;

    return 0;
}