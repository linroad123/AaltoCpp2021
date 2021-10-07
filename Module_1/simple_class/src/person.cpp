#include "person.hpp"
#include <string>

// define your Person class' functions here
Person::Person(std::string name, int birthyear) : name_(name), birthyear_(birthyear) {}

int Person::GetAge(int birthyear) {
    return birthyear - birthyear_;
}

std::string& Person::GetName() {
    return name_;
}


