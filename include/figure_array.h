#ifndef FIGURE_ARRAY_H
#define FIGURE_ARRAY_H

#include <vector>
#include "figure.h"

class FigureArray {
private:
    std::vector<Figure*> figures;

public:
    FigureArray() = default;
    FigureArray(const FigureArray& other);
    FigureArray(FigureArray&& other) noexcept;
    FigureArray& operator=(const FigureArray& other);
    FigureArray& operator=(FigureArray&& other) noexcept;
    ~FigureArray();

    void Add(Figure* fig);
    void Remove(size_t index);
    void PrintAll() const;
    double TotalArea() const;
    size_t Size() const { return figures.size(); }
};

#endif
