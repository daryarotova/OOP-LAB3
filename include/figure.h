#ifndef FIGURE_H
#define FIGURE_H

#include <iostream>

struct Point {
    double x;
    double y;
};

class Figure {
public:
    virtual ~Figure() {}
    virtual Point GeometricCenter() const = 0;
    virtual double Area() const = 0;
    virtual void Print(std::ostream& os) const = 0;
    virtual void Read(std::istream& is) = 0;
    virtual bool operator==(const Figure& other) const = 0;
    virtual Figure* Clone() const = 0;
    virtual operator double() const = 0;
};

inline std::ostream& operator<<(std::ostream& os, const Figure& f) {
    f.Print(os);
    return os;
}

inline std::istream& operator>>(std::istream& is, Figure& f) {
    f.Read(is);
    return is;
}

#endif
