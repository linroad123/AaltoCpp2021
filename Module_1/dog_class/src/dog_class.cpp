# include "dog_class.hpp"
# include <string>
//Definitions of class functions with some errors
using namespace std;

Dog::Dog(int a, string n) { 
    age_ = a; 
    name_ = n; 
}

void Dog::SetAge(int a){
    age_ = a;
}


int Dog::GetAge() {
    return age_; 
}


void Dog::SetName(string n) {
    name_ = n; 
}


string Dog::GetName() {
    return name_; 
}


