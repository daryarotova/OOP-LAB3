#ifndef OCTAGON_H
#define OCTAGON_H

#include "figure.h"
#include <vector>

class Octagon : public Figure {
private:
    std::vector<Point> vertices;
public:
    Octagon();
    Octagon(const std::vector<Point>& v);
    Octagon(const Octagon& other);
    Octagon& operator=(const Octagon& other);
    Point GeometricCenter() const override;
    double Area() const override;
    void Print(std::ostream& os) const override;
    void Read(std::istream& is) override;
    bool operator==(const Figure& other) const override;
    Figure* Clone() const override;
    operator double() const override;
};

#endif
