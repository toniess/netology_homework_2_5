#include <iostream>

class Figure
{
public:
	Figure() : m_corner(0) 
	{
		m_type = "Фигура";
	}
	int getCornerCount()
	{
		return m_corner;
	}
	virtual void print_info()
	{
		std::cout << m_type << ":\n";
		std::cout << "Сторон: нет\n";
		std::cout << "Углов: нет\n";
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
	Triangle(int cornerA, int cornerB, int cornerC,
		int sideA, int sideB, int sideC)
		: Figure(3) 
	{
		m_cornerA = cornerA;
		m_cornerB = cornerB;
		m_cornerC = cornerC;

		m_sideA = sideA;
		m_sideB = sideB;
		m_sideC = sideC;
		m_type = "Треугольник";
	};
	void print_info() override
	{
		std::cout << m_type << ": \n";
		std::cout << "Стороны: a=" << getSideA() << " b=" << getSideB() << " c=" << getSideC() << "\n";
		std::cout << "Углы: A=" << getCornerA() << " B=" << getCornerB() << " C=" << getCornerC() << "\n";
	}

	int getCornerA() { return m_cornerA; }
	int getCornerB() { return m_cornerB; }
	int getCornerC() { return m_cornerC; }

	int getSideA() { return m_sideA; }
	int getSideB() { return m_sideB; }
	int getSideC() { return m_sideC; }

private:
	int m_cornerA;
	int m_cornerB;
	int m_cornerC;

	int m_sideA;
	int m_sideB;
	int m_sideC;
};

class RightTriangle : public Triangle
{
public:
	RightTriangle(int cornerA, int cornerB,
		int sideA, int sideB, int sideC)
		: Triangle(cornerA, cornerB, 90,
			sideA, sideB, sideC)
	{
		m_type = "Прямоугольный треугольник";
	};
};

class IsoscelesTriangle : public Triangle
{
public:
	IsoscelesTriangle(int cornerA, int cornerBC,
		int sideA, int sideBC)
		: Triangle(cornerA, cornerBC, cornerBC,
			sideA, sideBC, sideBC)
	{
		m_type = "Равнобедренный треугольник";
	};
};

class EquilateralTriangle : public IsoscelesTriangle
{
public:
	EquilateralTriangle(int side)
		: IsoscelesTriangle(60, 60, side, side)
	{
		m_type = "Равносторонний треугольник";
	};
};



class Quadrilateral : public Figure
{
public:
	Quadrilateral(int cornerA, int cornerB, int cornerC, int cornerD,
		int sideA, int sideB, int sideC, int sideD )
		: Figure(4) 
	{
		m_cornerA = cornerA;
		m_cornerB = cornerB;
		m_cornerC = cornerC;
		m_cornerD = cornerD;

		m_sideA = sideA;
		m_sideB = sideB;
		m_sideC = sideC;
		m_sideD = sideD;

		m_type = "Четырехугольник";
	};

	void print_info() override
	{
		std::cout << m_type << ": \n";
		std::cout << "Стороны: a=" << getSideA() << " b=" << getSideB() << " c=" << getSideC() << " d=" << getSideD() << "\n";
		std::cout << "Углы: A=" << getCornerA() << " B=" << getCornerB() << " C=" << getCornerC() << " D=" << getCornerD() << "\n";
	}

	int getCornerA() { return m_cornerA; }
	int getCornerB() { return m_cornerB; }
	int getCornerC() { return m_cornerC; }
	int getCornerD() { return m_cornerD; }

	int getSideA() { return m_sideA; }
	int getSideB() { return m_sideB; }
	int getSideC() { return m_sideC; }
	int getSideD() { return m_sideD; }

private:
	int m_cornerA;
	int m_cornerB;
	int m_cornerC;
	int m_cornerD;

	int m_sideA;
	int m_sideB;
	int m_sideC;
	int m_sideD;
};

class Parallelogram : public Quadrilateral
{
public:
	Parallelogram(int cornerAC, int cornerBD, int sideAC, int sideBD)
		: Quadrilateral(cornerAC, cornerBD, cornerAC, cornerBD, sideAC, sideBD, sideAC, sideBD) 
	{
		m_type = "Параллелограм";
	};
};

class Rectangle : public Parallelogram
{
public:
	Rectangle(int sideAC, int sideBD)
		: Parallelogram(90, 90, sideAC, sideBD)
	{
		m_type = "Прямоугольник";
	};
};

class Rhomb : public Parallelogram
{
public:
	Rhomb(int cornerAC, int cornerBD, int side)
		: Parallelogram(cornerAC, cornerBD, side, side)
	{
		m_type = "Ромб";
	};
};

class Square : public Rectangle
{
public:
	Square(int side)
		: Rectangle(side, side)
	{
		m_type = "Квадрат";
	};
};

void print(Figure &f)
{
	f.print_info();
	std::cout << "\n";
}

int main()
{
	setlocale(LC_ALL, "russian");
	
	Triangle t(60, 20, 100, 14, 10, 5);
	print(t);

	RightTriangle rt(30, 60, 3, 4, 5);
	print(rt);

	IsoscelesTriangle it(100, 40, 10, 20);
	print(it);

	EquilateralTriangle et(43);
	print(et);

	Quadrilateral q(10, 20, 30, 40, 4, 64, 34, 9);
	print(q);

	Parallelogram p(40, 50, 20, 30);
	print(p);

	Rectangle r(20, 30);
	print(r);

	Square s(30);
	print(s);

	Rhomb rh(30, 60, 15);
	print(rh);

}


