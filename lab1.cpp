#include <iostream>
#include<Windows.h>
struct Pair
{
    double first;
    int second;

    void Init(double price, int quantity)
    {
        if (price >= 0 && quantity >= 0)
        {
            first = price;
            second = quantity;
        }
        else
        {
            std::cout << "Помилка: Недопустимі значення для ціни та/або кількості." << std::endl;
        }
    }

    void Read()
    {
        double price;
        int quantity;

        std::cout << "Введіть ціну товару (дробове додатнє число): ";
        std::cin >> price;

        std::cout << "Введіть кількість одиниць товару (ціле додатнє число): ";
        std::cin >> quantity;

        Init(price, quantity);
    }

    void Display()
    {
        std::cout << "Ціна товару: " << first << std::endl;
        std::cout << "Кількість одиниць товару: " << second << std::endl;
    }

    double cost()
    {
        return first * second;
    }
};

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Pair product;

    product.Read();

    product.Display();

    double totalCost = product.cost();
    std::cout << "Вартість товару: " << totalCost << std::endl;

    return 0;
}
