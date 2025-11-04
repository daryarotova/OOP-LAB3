#ifndef PENTAGON_H
#define PENTAGON_H

#include "figure.h"
#include <vector>

class Pentagon : public Figure {
private:
    std::vector<Point> vertices;
public:
    Pentagon();
    Pentagon(const std::vector<Point>& v);
    Pentagon(const Pentagon& other);
    Pentagon& operator=(const Pentagon& other);
    Point GeometricCenter() const override;
    double Area() const override;
    void Print(std::ostream& os) const override;
    void Read(std::istream& is) override;
    bool operator==(const Figure& other) const override;
    Figure* Clone() const override;
    operator double() const override;
};

#endif
