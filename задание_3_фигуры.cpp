#include <iostream>

using namespace std;

class Figure
{
protected:
    string name;
    int sides_count;

public:
    virtual bool check()
    {
        return true;
    }
    virtual void print() 
    {
        cout << "Фигура:" << endl;
        cout << name;
        cout << (check() ? "Правильная" : "Неправильная") << endl;
        cout << "Количество сторон: " << sides_count << endl;
    }

    Figure() : sides_count(0) {};

    string get_name()
    {
        return name;
    }

    int get_sides_counts() const
    {
        return sides_count;
    }

    void set_name(string name)
    {
        this->name = name;
    }
    
};



void print_info(Figure* fig)
{
    fig->get_sides_counts();
    fig->print();
}


class Triangle : public Figure
{
protected:
    double a, b, c;
    double A, B, C;

public:

    Triangle(double a, double b, double c, double A, double B, double C) : a(a), b(b), c(c), A(A), B(B), C(C)
    {
        name = "Треугольник";
        sides_count = 3;
    }
    void print() override
    {   
        cout << endl << name << ":" << endl;
        cout << (check() ? "Правильная" : "Неправильная") << endl;
        cout << "Колличетсво сторон: " << sides_count << endl;
        cout << "Стороны: a=" << a << " b=" << b << " c=" << c << endl << "Углы: A=" << A << " B=" << B << " C=" << C << endl;
    }

    bool check() override
    {
        if (A + B + C == 180)
            return true;
        else
            return false;
    }

};

class RightTriangle : public Triangle
{
public:
    RightTriangle(double a, double b, double c, double A, double B) : Triangle(a, b, c, A, B, 90)
    {
        name = "Прямоугольный треугольник";
    }
    bool check() override
    {
        if (C == 90)
            return true;
        else
            return false;
    }
};

class IsoscelesTriangle : public Triangle
{

public:
    IsoscelesTriangle(double a, double b, double A, double B) : Triangle(a, b, a, A, B, A)
    {
        name = "Равнобедренный треугольник";
    }
    bool check() override
    {
        if (A == C && a == c)
            return true;
        else
            return false;
    }
};

class EquilateralTriangle : public Triangle
{
public:
    EquilateralTriangle(double a) : Triangle(a, a, a, 60, 60, 60)
    {
        name = "Равносторонний треугольник";
    }
    bool check() override
    {
        if (a == c && a == b && A == 60 && B == 60 && C == 60)
            return true;
        else
            return false;
    }
};




class Quadrangle : public Figure
{
protected:
    double a, b, c, d;
    double A, B, C, D;

public:
    Quadrangle(double a, double b, double c, double d, double A, double B, double C, double D) : a(a), b(b), c(c), d(d), A(A), B(B), C(C), D(D)
    {
        sides_count = 4;
        name = "Четырехугольник";
        
    }
    void print() override
    {
        cout << endl << name << ":" << endl;
        cout << (check() ? "Правильная" : "Неправильная") << endl;
        cout << "Стороны: a=" << a << " b=" << b << " c=" << c << " d=" << d << endl << "Углы: A=" << A << " B=" << B << " C=" << C << " D=" << D << endl;
    }
    bool check() override
    {
        if (A + B + C + D == 360)
            return true;
        else
            return false;
    }

};

class Parallelogram : public Quadrangle
{
public:
    Parallelogram(double a, double b, double A, double B) : Quadrangle(a, b, a, b, A, B, A, B)
    {
        name = "Параллелограмм";
    }

    bool check() override
    {
        if (a + c == b + d && A + C == B + D)
            return true;
        else
            return false;
    }
};

class Rectangle : public Parallelogram
{
public:
    Rectangle(double a, double b) : Parallelogram(a, b, 90, 90)
    {
        name = "Прямоугольник";
    }

    bool check() override
    {
        if (a == c && b == d && A == 90 && B == 90 && C == 90 && D == 90)
            return true;
        else
            return false;
    }
};

class Square : public Rectangle
{
public:
    Square(double a) : Rectangle(a, a)
    {
        name = "Квадрат";
    }

    bool check() override
    {
        if (a == b && b == c && c == d && A == 90 && B == 90 && C == 90 && D == 90)
            return true;
        else
            return false;
    }
};

class Rhomb : public Parallelogram
{
public:
    Rhomb(double a, double A, double B) : Parallelogram(a, a, A, B)
    {
        name = "Ромб";
    }

    bool check() override
    {
        if (a == b && b == c && c == d && A == C && B == D)
            return true;
        else
            return false;
    }
};

int main()
{   
    Figure figure;
    print_info(&figure);
    

    Triangle triangle(10, 20, 30, 50, 60, 70);
    print_info(&triangle);

    RightTriangle right_triangle(10, 20, 30, 50, 60);
    print_info(&right_triangle);

    IsoscelesTriangle isosceles_triangle(10, 20, 50, 60);
    print_info(&isosceles_triangle);

    EquilateralTriangle equilateral_triangle(30);
    print_info(&equilateral_triangle);

    Quadrangle quandrangle(10, 20, 30, 40, 50, 60, 70, 80);
    print_info(&quandrangle);

    Rectangle rectangle(10, 20);
    print_info(&rectangle);

    Square square(10);
    print_info(&square);

    Parallelogram parellelogram(20, 30, 30, 40);
    print_info(&parellelogram);

    Rhomb rhomb(30, 30, 40);
    print_info(&rhomb);

    return 0;
}