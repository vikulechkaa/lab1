#include <iostream>
#include <Windows.h>
#include <string>

class Complex
{
private:
    double real;
    double imag;

public:
    // ����������� �� �������������
    Complex() : real(0.0), imag(0.0) {}

    // �����������, ���� ������ ��� ������ �����
    Complex(double realPart, double imagPart) : real(realPart), imag(imagPart) {}

    // ����������� ���������
    Complex(const Complex& other) : real(other.real), imag(other.imag) {}

    void Init(double realPart, double imagPart)
    {
        real = realPart;
        imag = imagPart;
    }

    void Read()
    {
        std::cout << "������ ����� �������: ";
        std::cin >> real;
        std::cout << "������ ����� �������: ";
        std::cin >> imag;
    }

    void Display()
    {
        std::cout << "(" << real << ", " << imag << ")";
    }

    std::string toString()
    {
        return "(" + std::to_string(real) + ", " + std::to_string(imag) + ")";
    }

    Complex add(const Complex& other)
    {
        return Complex(real + other.real, imag + other.imag);
    }

    Complex sub(const Complex& other)
    {
        return Complex(real - other.real, imag - other.imag);
    }

    Complex mul(const Complex& other)
    {
        return Complex(real * other.real - imag * other.imag, real * other.imag + imag * other.real);
    }

    Complex div(const Complex& other)
    {
        double denominator = other.real * other.real + other.imag * other.imag;
        double newReal = (real * other.real + imag * other.imag) / denominator;
        double newImag = (imag * other.real - real * other.imag) / denominator;
        return Complex(newReal, newImag);
    }

    bool equ(const Complex& other)
    {
        return (real == other.real) && (imag == other.imag);
    }

    Complex conj()
    {
        return Complex(real, -imag);
    }
};

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Complex a, b, result;

    a.Read();
    b.Init(2.0, 3.0);

    result = a.add(b);
    std::cout << "��������� ���������: ";
    result.Display();
    std::cout << std::endl;

    result = a.sub(b);
    std::cout << "��������� ��������: ";
    result.Display();
    std::cout << std::endl;

    result = a.mul(b);
    std::cout << "��������� ��������: ";
    result.Display();
    std::cout << std::endl;

    result = a.div(b);
    std::cout << "��������� ������: ";
    result.Display();
    std::cout << std::endl;

    bool isEqual = a.equ(b);
    if (isEqual)
    {
        std::cout << "����� ���" << std::endl;
    }
    else
    {
        std::cout << "����� �� ���" << std::endl;
    }

    result = a.conj();
    std::cout << "��������� ����� a: ";
    result.Display();
    std::cout << std::endl;

    return 0;
}
