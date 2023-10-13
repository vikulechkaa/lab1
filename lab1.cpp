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
            std::cout << "�������: ���������� �������� ��� ���� ��/��� �������." << std::endl;
        }
    }

    void Read()
    {
        double price;
        int quantity;

        std::cout << "������ ���� ������ (������� ������ �����): ";
        std::cin >> price;

        std::cout << "������ ������� ������� ������ (���� ������ �����): ";
        std::cin >> quantity;

        Init(price, quantity);
    }

    void Display()
    {
        std::cout << "ֳ�� ������: " << first << std::endl;
        std::cout << "ʳ������ ������� ������: " << second << std::endl;
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
    std::cout << "������� ������: " << totalCost << std::endl;

    return 0;
}
