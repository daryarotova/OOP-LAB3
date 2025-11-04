#include "../include/hexagon.h"
#include <cmath>

Hexagon::Hexagon() : vertices(6) {}

Hexagon::Hexagon(const std::vector<Point>& v) : vertices(v) {}

Hexagon::Hexagon(const Hexagon& other) : vertices(other.vertices) {}

Hexagon& Hexagon::operator=(const Hexagon& other) {
    if (this != &other) {
        vertices = other.vertices;
    }
    return *this;
}

Point Hexagon::GeometricCenter() const {
    double cx = 0;
    double cy = 0;
    for (auto& p : vertices) {
        cx += p.x;
        cy += p.y;
    }
    return { cx / 6, cy / 6 };
}

double Hexagon::Area() const {
    double sum = 0;
    for (int i = 0; i < 6; i++) {
        const Point& p1 = vertices[i];
        const Point& p2 = vertices[(i + 1) % 6];
        sum += p1.x * p2.y - p2.x * p1.y;
    }
    return std::abs(sum) / 2;
}

void Hexagon::Print(std::ostream& os) const {
    os << "Hexagon: ";
    for (auto& p : vertices) {
        os << "(" << p.x << "," << p.y << ") ";
    }
    Point center = GeometricCenter();
    os << "\nCenter: " << center.x << "," << center.y;
    os << "\nArea: " << Area() << "\n";
}

void Hexagon::Read(std::istream& is) {
    for (auto& p : vertices) {
        is >> p.x >> p.y;
    }
}

bool Hexagon::operator==(const Figure& other) const {
    const Hexagon* o = dynamic_cast<const Hexagon*>(&other);
    if (!o) return false;
    for (int i = 0; i < 6; i++) {
        if (vertices[i].x != o->vertices[i].x ||
            vertices[i].y != o->vertices[i].y) {
            return false;
        }
    }
    return true;
}

Figure* Hexagon::Clone() const {
    return new Hexagon(*this);
}

Hexagon::operator double() const {
    return Area();
}
