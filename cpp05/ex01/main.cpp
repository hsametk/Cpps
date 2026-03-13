#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {

    Bureaucrat samcu("Samet", 1);
    Bureaucrat sam("Sam", 150);
    Form doc("doc", 75, 50);
    std::cout << samcu << sam << doc;

    samcu.signForm(doc);
    sam.signForm(doc);

    try {
        Bureaucrat top("Top", 1);
        top.incrementGrade();
    } catch (std::exception &e) {
        std::cout << "Top.increment: " << e.what() << std::endl;
    }
    try {
        Bureaucrat low("Low", 150);
        low.decrementGrade();
    } catch (std::exception &e) {
        std::cout << "Low.decrement: " << e.what() << std::endl;
    }

    try {
        Bureaucrat bad1("Bad1", 0);
    } catch (std::exception &e) {
        std::cout << "Bad1 error: " << e.what() << std::endl;
    }
    try {
        Bureaucrat bad2("Bad2", 151);
    } catch (std::exception &e) {
        std::cout << "Bad2 error: " << e.what() << std::endl;
    }
    try {
        Form badF1("BadF1", 0, 10);
    } catch (std::exception &e) {
        std::cout << "BadF1 error: " << e.what() << std::endl;
    }
    try {
        Form badF2("BadF2", 10, 151);
    } catch (std::exception &e) {
        std::cout << "BadF2 error: " << e.what() << std::endl;
    }

    Bureaucrat copysamcu(samcu);
    Bureaucrat assignsam = sam;
    Form copyDoc(doc);
    Form assignDoc;
    assignDoc = doc;
    std::cout << "Copied/assigned objects:\n" << copysamcu << assignsam << copyDoc << assignDoc;

    return 0;
}