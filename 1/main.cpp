#include <iostream>

class Figure
{
public:
	Figure() : m_corner(0) {};
	int getCornerCount()
	{
		return m_corner;
	}

protected:
	Figure(int corners)
	{
		m_corner = corners;
	}

private:
	int m_corner;
};

class Triangle : public Figure
{
public:
	Triangle() : Figure(3) {};
};

class Quadrilateral : public Figure
{
public:
	Quadrilateral() : Figure(4) {};
};

int main()
{
	setlocale(LC_ALL, "russian");
	std::cout << "Количество сторон:\n";
	
	Figure f;
	std::cout << "Фигура: " << f.getCornerCount() << "\n";

	Triangle t;
	std::cout << "Треугольник: " << t.getCornerCount() << "\n";

	Quadrilateral q;
	std::cout << "Четырехугольник: " << q.getCornerCount() << "\n";
}


