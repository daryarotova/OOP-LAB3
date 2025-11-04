#include "../include/pentagon.h"
#include <cmath>

Pentagon::Pentagon() : vertices(5) {}

Pentagon::Pentagon(const std::vector<Point>& v) : vertices(v) {}

Pentagon::Pentagon(const Pentagon& other) : vertices(other.vertices) {}

Pentagon& Pentagon::operator=(const Pentagon& other) {
    if (this != &other) {
        vertices = other.vertices;
    }
    return *this;
}

Point Pentagon::GeometricCenter() const {
    double cx = 0;
    double cy = 0;
    for (auto& p : vertices) {
        cx += p.x;
        cy += p.y;
    }
    return { cx / 5, cy / 5 };
}

double Pentagon::Area() const {
    double sum = 0;
    for (int i = 0; i < 5; i++) {
        const Point& p1 = vertices[i];
        const Point& p2 = vertices[(i + 1) % 5];
        sum += p1.x * p2.y - p2.x * p1.y;
    }
    return std::abs(sum) / 2;
}

void Pentagon::Print(std::ostream& os) const {
    os << "Pentagon: ";
    for (auto& p : vertices) {
        os << "(" << p.x << "," << p.y << ") ";
    }
    Point center = GeometricCenter();
    os << "\nCenter: " << center.x << "," << center.y;
    os << "\nArea: " << Area() << "\n";
}

void Pentagon::Read(std::istream& is) {
    for (auto& p : vertices) {
        is >> p.x >> p.y;
    }
}

bool Pentagon::operator==(const Figure& other) const {
    const Pentagon* o = dynamic_cast<const Pentagon*>(&other);
    if (!o) return false;
    for (int i = 0; i < 5; i++) {
        if (vertices[i].x != o->vertices[i].x ||
            vertices[i].y != o->vertices[i].y) {
            return false;
        }
    }
    return true;
}

Figure* Pentagon::Clone() const {
    return new Pentagon(*this);
}

Pentagon::operator double() const {
    return Area();
}
