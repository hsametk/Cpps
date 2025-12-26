
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include "WrongAnimal.hpp"
int main()
{
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound(); //will output the cat sound!
    j->makeSound();
    meta->makeSound();

    delete meta;
    delete j;
    delete i;

    std::cout << "----- WrongAnimal Test -----" << std::endl;
    WrongAnimal* wa = new WrongAnimal();
    WrongAnimal* wcat_as_base = new WrongCat();
    std::cout << wcat_as_base->getType() << std::endl;
    wcat_as_base->makeSound(); // prints WrongAnimal sound (NOT WrongCat)
    delete wa;
    delete wcat_as_base;
    return 0;
}