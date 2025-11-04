#include "../include/figure_array.h"
#include <iostream>

FigureArray::FigureArray(const FigureArray& other) {
    for (auto f : other.figures) {
        figures.push_back(f->Clone());
    }
}

FigureArray::FigureArray(FigureArray&& other) noexcept
    : figures(std::move(other.figures)) {}

FigureArray& FigureArray::operator=(const FigureArray& other) {
    if (this != &other) {
        for (auto f : figures) {
            delete f;
        }
        figures.clear();
        for (auto f : other.figures) {
            figures.push_back(f->Clone());
        }
    }
    return *this;
}

FigureArray& FigureArray::operator=(FigureArray&& other) noexcept {
    if (this != &other) {
        for (auto f : figures) {
            delete f;
        }
        figures = std::move(other.figures);
    }
    return *this;
}

FigureArray::~FigureArray() {
    for (auto f : figures) {
        delete f;
    }
}

void FigureArray::Add(Figure* f) {
    figures.push_back(f);
}

void FigureArray::Remove(size_t index) {
    if (index >= figures.size()) return;
    delete figures[index];
    figures.erase(figures.begin() + index);
}

void FigureArray::PrintAll() const {
    for (size_t i = 0; i < figures.size(); i++) {
        std::cout << "[" << i << "] ";
        figures[i]->Print(std::cout);
    }
}

double FigureArray::TotalArea() const {
    double total = 0;
    for (auto f : figures) {
        total += static_cast<double>(*f);
    }
    return total;
}
