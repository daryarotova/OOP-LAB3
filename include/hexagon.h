#ifndef HEXAGON_H
#define HEXAGON_H

#include "figure.h"
#include <vector>

class Hexagon : public Figure {
private:
    std::vector<Point> vertices;
public:
    Hexagon();
    Hexagon(const std::vector<Point>& v);
    Hexagon(const Hexagon& other);
    Hexagon& operator=(const Hexagon& other);
    Point GeometricCenter() const override;
    double Area() const override;
    void Print(std::ostream& os) const override;
    void Read(std::istream& is) override;
    bool operator==(const Figure& other) const override;
    Figure* Clone() const override;
    operator double() const override;
};

#endif
