#include <iostream>
#include <Windows.h>
class Complex 
{
private:
    double real;
    double imag;
public:
    Complex() : real(0.0), imag(0.0) {}

    Complex(double realPart, double imagPart) : real(realPart), imag(imagPart) {}

    void Init(double realPart, double imagPart) 
    {
        real = realPart;
        imag = imagPart;
    }

    void Read() 
    {
        std::cout << "Введіть дійсну частину: ";
        std::cin >> real;
        std::cout << "Введіть уявну частину: ";
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
        double newReal = (real * other.real) - (imag * other.imag);
        double newImag = (real * other.imag) + (imag * other.real);
        return Complex(newReal, newImag);
    }

    Complex div(const Complex& other) 
    {
        double denominator = (other.real * other.real) + (other.imag * other.imag);
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
    Complex num1, num2, result;

    num1.Read();
    num2.Read();

    result = num1.add(num2);
    std::cout << "Додавання: ";
    result.Display();
    std::cout << std::endl;

    result = num1.sub(num2);
    std::cout << "Віднімання: ";

    result.Display();
    std::cout << std::endl;

    result = num1.mul(num2);
    std::cout << "Множення: ";
    result.Display();
    std::cout << std::endl;

    result = num1.div(num2);
    std::cout << "Ділення: ";
    result.Display();
    std::cout << std::endl;

    if (num1.equ(num2)) 
    {
        std::cout << "Числа рівні" << std::endl;
    }
    else 
    {
        std::cout << "Числа не рівні" << std::endl;
    }

    result = num1.conj();
    std::cout << "Спряжене число до першого: ";
    result.Display();
    std::cout << std::endl;

    return 0;
}
