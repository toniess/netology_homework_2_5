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
	};

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
			sideA, sideB, sideC) {};
};

class IsoscelesTriangle : public Triangle
{
public:
	IsoscelesTriangle(int cornerA, int cornerBC,
		int sideA, int sideBC)
		: Triangle(cornerA, cornerBC, cornerBC,
			sideA, sideBC, sideBC) {};
};

class EquilateralTriangle : public IsoscelesTriangle
{
public:
	EquilateralTriangle(int side)
		: IsoscelesTriangle(60, 60, side, side) {};
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
	};

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
		: Quadrilateral(90, 90, 90, 90, sideAC, sideBD, sideAC, sideBD) {};
};

class Rectangle : public Parallelogram
{
public:
	Rectangle(int sideAC, int sideBD)
		: Parallelogram(90, 90, sideAC, sideBD) {};
};

class Rhomb : public Parallelogram
{
public:
	Rhomb(int cornerAC, int cornerBD, int side)
		: Parallelogram(cornerAC, cornerBD, side, side) {};
};

class Square : public Rectangle
{
public:
	Square(int side)
		: Rectangle(side, side) {};
};


void print(Figure &f, std::string type)
{
	std::cout << type << ":\n";
	if (f.getCornerCount() == 3)
	{
		Triangle &t = static_cast<Triangle&>(f);
		std::cout << "Стороны: a=" << t.getSideA() << " b=" << t.getSideB() << " c=" << t.getSideC() << "\n";
		std::cout << "Углы: A=" << t.getCornerA() << " B=" << t.getCornerB() << " C=" << t.getCornerC() << "\n";
	}
	else
	{
		Quadrilateral& t = static_cast<Quadrilateral&>(f);
		std::cout << "Стороны: a=" << t.getSideA() << " b=" << t.getSideB() << " c=" << t.getSideC() << " d=" << t.getSideD() << "\n";
		std::cout << "Углы: A=" << t.getCornerA() << " B=" << t.getCornerB() << " C=" << t.getCornerC() << " D=" << t.getCornerD() << "\n";
	}
	std::cout << "\n";
}

int main()
{
	setlocale(LC_ALL, "russian");
	
	Triangle t(60, 20, 100, 14, 10, 5);
	print(t, "Производный треугольник");

	RightTriangle rt(30, 60, 3, 4, 5);
	print(rt, "Прямоугольный треугольник");

	IsoscelesTriangle it(100, 40, 10, 20);
	print(it, "Равнобедренный треугольник");

	EquilateralTriangle et(43);
	print(et, "Равносторонний треугольник");

	Quadrilateral q(10, 20, 30, 40, 4, 64, 34, 9);
	print(q, "Произвольный четырехугольник");

	Parallelogram p(40, 50, 20, 30);
	print(p, "Паралелограмм");

	Rectangle r(20, 30);
	print(r, "Прямоугольник");

	Square s(30);
	print(s, "Квадрат");

	Rhomb rh(30, 60, 15);
	print(rh, "Ромб");

}


