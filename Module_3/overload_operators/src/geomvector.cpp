#include "geomvector.hpp"

// Implement operators here


GeomVector GeomVector::operator+(const GeomVector& a) {
    return GeomVector(a.x_ + x_, a.y_ + y_, a.z_ + z_);
}

GeomVector operator/(const GeomVector& a,double b) {
    return GeomVector(a.x_/b, a.y_/b, a.z_/b);
}

bool operator>(const GeomVector& a,const GeomVector& b) {
    bool result = a.Length() > b.Length();
    return result;
}

bool operator<(const GeomVector& a,const GeomVector& b) {
    bool result = a.Length() < b.Length();
    return result;
}

bool operator==(const GeomVector& a,const GeomVector& b) {
    if (a.x_ == b.x_ and a.y_ == b.y_ and a.z_ == b.z_) {
        return true;
    } else {
        return false;
    }
}

bool operator!=(const GeomVector& a,const GeomVector& b) {
    if (a.x_ == b.x_ and a.y_ == b.y_ and a.z_ ==b.z_) {
        return false;
    } 
    else {
        return true;
    }
}

GeomVector operator*(double a, const GeomVector& b) {
    return GeomVector(a * b.x_, a * b.y_, a * b.z_);
}

std::ostream &operator<<(std::ostream& out, const GeomVector& a) {
    out << "(" << a.x_ << ", " << a.y_ << ", " << a.z_ << ")";
    return out;
}

double GeomVector::Length() const {
    return sqrt(pow(x_, 2) + pow(y_, 2) + pow(z_, 2));
}