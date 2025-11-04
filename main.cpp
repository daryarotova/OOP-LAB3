#include <iostream>
#include "include/figure_array.h"
#include "include/pentagon.h"
#include "include/hexagon.h"
#include "include/octagon.h"

int main() {
    FigureArray array;

    int n;
    std::cout << "Количество фигур для ввода: ";
    std::cin >> n;

    for (int i = 0; i < n; i++) {
        int choice;
        std::cout << "\nВыберите тип фигуры для ввода #" << i + 1 << ":\n";
        std::cout << "1 - Pentagon (5-угольник)\n";
        std::cout << "2 - Hexagon (6-угольник)\n";
        std::cout << "3 - Octagon (8-угольник)\n";
        std::cout << "Ваш вариант: ";
        std::cin >> choice;

        Figure* f = nullptr;

        switch (choice) {
            case 1:
                f = new Pentagon();
                break;
            case 2:
                f = new Hexagon();
                break;
            case 3:
                f = new Octagon();
                break;
            default:
                std::cout << "Неверно, повторите ввод.\n";
                i--;
                continue;
        }

        std::cout << "Введите координаты вершин фигуры через пробел (x y):\n";
        std::cin >> *f;

        array.Add(f);
    }

    std::cout << "\n - Введённые фигуры - \n";
    array.PrintAll();

    std::cout << "Общая площадь всех фигур: " << array.TotalArea() << "\n";

    char remove_choice;
    std::cout << "\nУдалить фигуру? (y/n): ";
    std::cin >> remove_choice;
    if (remove_choice == 'y' || remove_choice == 'Y') {
        size_t index;
        std::cout << "Введите индекс фигуры для удаления: ";
        std::cin >> index;
        array.Remove(index);
        std::cout << "Фигура удалена.\n";

        std::cout << "\n- Фигуры после удаления - \n";
        array.PrintAll();
        std::cout << "Общая площадь всех фигур: " << array.TotalArea() << "\n";
    }

    std::cout << "\n Конец.\n";

    return 0;
}
