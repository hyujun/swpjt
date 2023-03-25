#include <iostream>
#include <string>
#include <forward_list>

struct citizen{
    std::string name;
    int age;
};

std::ostream &operator<<(std::ostream &os, const citizen &c)
{
    return (os << "[" << c.name << ", " << c.age << "]");
}

int main()
{
    std::forward_list<citizen> citizens = {
        {"KIM", 22}, {"Lee", 25}, {"Park", 18}, {"Jin", 16}
    };

    auto citizens_copy = citizens;

    std::cout << "all citizens: ";
    for(const auto &c : citizens)
    {
        std::cout << c << " ";
    }
    std::cout << std::endl;

    citizens.remove_if([](const citizen &c){
        return (c.age < 19);
    });

    std::cout << "has votes: ";
    for(const auto &c : citizens)
    {
        std::cout << c << " ";
    }
    std::cout << std::endl;

    return 0;
}