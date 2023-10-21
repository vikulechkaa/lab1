#include <iostream>
#include <string>
#include <Windows.h>

class Complex
{
private:
    double real;
    double imaginary;

public:
    // ����������� �� �������������
    Complex() : real(0.0), imaginary(0.0) {}

    // ����������� � �����������
    Complex(double a, double b) : real(a), imaginary(b) {}

    // ����� �����������
    void Init(double a, double b)
    {
        real = a;
        imaginary = b;
    }

    // ����� �������� �� ���������
    void Read() 
    {
        std::cout << "������ ����� �������: ";
        std::cin >> real;
        std::cout << "������ ����� �������: ";
        std::cin >> imaginary;
    }

    // ����� �������� �� �����
    void Display()
    {
        std::cout << real;
        if (imaginary >= 0) 
        {
            std::cout << " + " << imaginary << "i";
        }
        else {
            std::cout << " - " << -imaginary << "i";
        }
        std::cout << std::endl;
    }

    // �������������� �������� ���������
    Complex operator+(const Complex& other) const
    {
        return Complex(real + other.real, imaginary + other.imaginary);
    }

    // �������������� �������� ��������
    Complex operator-(const Complex& other) const 
    {
        return Complex(real - other.real, imaginary - other.imaginary);
    }

    // �������������� �������� ��������
    Complex operator*(const Complex& other) const 
    {
        return Complex(real * other.real - imaginary * other.imaginary, real * other.imaginary + imaginary * other.real);
    }

    // �������������� �������� ������
    Complex operator/(const Complex& other) const
    {
        double denominator = other.real * other.real + other.imaginary * other.imaginary;
        return Complex((real * other.real + imaginary * other.imaginary) / denominator, (imaginary * other.real - real * other.imaginary) / denominator);
    }

    // �������������� �������� ���������
    bool operator==(const Complex& other) const
    {
        return (real == other.real) && (imaginary == other.imaginary);
    }

    // �������������� �������� ����������� ����������� �����
    Complex conj() const
    {
        return Complex(real, -imaginary);
    }

    // �������������� �������� ������������ � �����
    std::string toString() const 
    {
        std::string result = std::to_string(real);
        result += (imaginary >= 0) ? " + " : " - ";
        result += std::to_string(std::abs(imaginary)) + "i";
        return result;
    }
};

int main() 
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Complex c1, c2, result;
    c1.Read();
    c2.Read();

    result = c1 + c2;
    std::cout << "����: " << result.toString() << std::endl;

    result = c1 - c2;
    std::cout << "г�����: " << result.toString() << std::endl;

    result = c1 * c2;
    std::cout << "�������: " << result.toString() << std::endl;

    result = c1 / c2;
    std::cout << "������: " << result.toString() << std::endl;

    if (c1 == c2) 
    {
        std::cout << "����� ���." << std::endl;
    }
    else 
    {
        std::cout << "����� �� ���." << std::endl;
    }

    Complex conjugate = c1.conj();
    std::cout << "��������� �����: " << conjugate.toString() << std::endl;

    return 0;
}
