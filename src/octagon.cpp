#include "../include/octagon.h"
#include <cmath>

Octagon::Octagon() : vertices(8) {}

Octagon::Octagon(const std::vector<Point>& v) : vertices(v) {}

Octagon::Octagon(const Octagon& other) : vertices(other.vertices) {}

Octagon& Octagon::operator=(const Octagon& other) {
    if (this != &other) {
        vertices = other.vertices;
    }
    return *this;
}

Point Octagon::GeometricCenter() const {
    double cx = 0;
    double cy = 0;
    for (auto& p : vertices) {
        cx += p.x;
        cy += p.y;
    }
    return { cx / 8, cy / 8 };
}

double Octagon::Area() const {
    double sum = 0;
    for (int i = 0; i < 8; i++) {
        const Point& p1 = vertices[i];
        const Point& p2 = vertices[(i + 1) % 8];
        sum += p1.x * p2.y - p2.x * p1.y;
    }
    return std::abs(sum) / 2;
}

void Octagon::Print(std::ostream& os) const {
    os << "Octagon: ";
    for (auto& p : vertices) {
        os << "(" << p.x << "," << p.y << ") ";
    }
    Point center = GeometricCenter();
    os << "\nCenter: " << center.x << "," << center.y;
    os << "\nArea: " << Area() << "\n";
}

void Octagon::Read(std::istream& is) {
    for (auto& p : vertices) {
        is >> p.x >> p.y;
    }
}

bool Octagon::operator==(const Figure& other) const {
    const Octagon* o = dynamic_cast<const Octagon*>(&other);
    if (!o) return false;
    for (int i = 0; i < 8; i++) {
        if (vertices[i].x != o->vertices[i].x ||
            vertices[i].y != o->vertices[i].y) {
            return false;
        }
    }
    return true;
}

Figure* Octagon::Clone() const {
    return new Octagon(*this);
}

Octagon::operator double() const {
    return Area();
}
