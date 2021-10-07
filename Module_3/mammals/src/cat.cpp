#include "cat.hpp"

std::string Cat::sound_ = "Meow";

const std::string& Cat::GetName() const {
    return name_;
}
