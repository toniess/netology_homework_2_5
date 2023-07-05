#include <iostream>

class Figure
{
public:
	Figure() : m_corner(0)
	{
		m_type = "Фигура";
	};
	int getCornerCount()
	{
		return m_corner;
	}
	std::string type()
	{
		return m_type;
	}

protected:
	Figure(int corners)
	{
		m_corner = corners;
	}
	std::string m_type;

private:
	int m_corner;
};

class Triangle : public Figure
{
public:
	Triangle() : Figure(3)
	{
		m_type = "Треугольник";
	};
};

class Quadrilateral : public Figure
{
public:
	Quadrilateral() : Figure(4)
	{
		m_type = "Четырехугольник";
	};
};

void print_info(Figure& f)
{
	std::cout << f.type() << ": " << f.getCornerCount() << "\n";
}

int main()
{
	setlocale(LC_ALL, "russian");
	std::cout << "Количество сторон:\n";
	
	Figure f;
	print_info(f);

	Triangle t;
	print_info(t);

	Quadrilateral q;
	print_info(q);

}


