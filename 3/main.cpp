#include <iostream>

class Figure
{
public:
	Figure() : m_corner(0) {};
	int getCornerCount()
	{
		return m_corner;
	}

	virtual bool isRight()
	{
		return true;
	}

	virtual void printCorners()
	{
		return;
	}

	void print_info()
	{
		std::cout << m_name << ":\n";
		std::cout << (isRight() ? "Правильная" : "Неправильная") << "\n";
		std::cout << "Количество сторон: " << m_corner << "\n";
		if (m_corner > 0)
		{
			printCorners();
		}
		std::cout << "\n";
	}
protected:
	Figure(int corners)
	{
		m_corner = corners;
	}
	std::string m_name = "Фигура";

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

		m_name = "Производный треугольник";
	};

	int getCornerA() { return m_cornerA; }
	int getCornerB() { return m_cornerB; }
	int getCornerC() { return m_cornerC; }

	int getSideA() { return m_sideA; }
	int getSideB() { return m_sideB; }
	int getSideC() { return m_sideC; }

	void printCorners() override
	{
		std::cout << "Стороны: a=" << getSideA() << " b=" << getSideB() << " c=" << getSideC() << "\n";
		std::cout << "Углы: A=" << getCornerA() << " B=" << getCornerB() << " C=" << getCornerC() << "\n";
	}

	bool isRight() override
	{
		return m_cornerA + m_cornerB + m_cornerC == 180;
	}

protected:
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
			sideA, sideB, sideC) {
		m_name = "Прямоугольный треугольник";
	};
	bool isRight() override
	{
		return m_cornerC == 90 && Triangle::isRight();
	}
};

class IsoscelesTriangle : public Triangle
{
public:
	IsoscelesTriangle(int cornerA, int cornerBC,
		int sideA, int sideBC)
		: Triangle(cornerA, cornerBC, cornerBC,
			sideA, sideBC, sideBC) {
		m_name = "Равнобедренный треугольник";
	};
	bool isRight() override
	{
		return m_cornerB == m_cornerC &&
			m_sideB == m_sideC && Triangle::isRight();
	}
};

class EquilateralTriangle : public IsoscelesTriangle
{
public:
	EquilateralTriangle(int side)
		: IsoscelesTriangle(60, 60, side, side) {
		m_name = "Равносторонний треугольник";
	};
	bool isRight() override
	{
		return m_sideA == m_sideB && m_sideB == m_sideC &&
			m_cornerA == 60 && m_cornerB == 60 && IsoscelesTriangle::isRight();
	}
};



class Quadrilateral : public Figure
{
public:
	Quadrilateral(int cornerA, int cornerB, int cornerC, int cornerD,
		int sideA, int sideB, int sideC, int sideD)
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
		m_name = "Производный четырехугольник";
	};

	int getCornerA() { return m_cornerA; }
	int getCornerB() { return m_cornerB; }
	int getCornerC() { return m_cornerC; }
	int getCornerD() { return m_cornerD; }

	int getSideA() { return m_sideA; }
	int getSideB() { return m_sideB; }
	int getSideC() { return m_sideC; }
	int getSideD() { return m_sideD; }

	void printCorners() override
	{
		std::cout << "Стороны: a=" << getSideA() << " b=" << getSideB() << " c=" << getSideC() << " d=" << getSideD() << "\n";
		std::cout << "Углы: A=" << getCornerA() << " B=" << getCornerB() << " C=" << getCornerC() << " D=" << getCornerD() << "\n";
	}

	bool isRight() override
	{
		return m_cornerA + m_cornerB + m_cornerC + m_cornerD == 360;
	}

protected:
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
		: Quadrilateral(90, 90, 90, 90, sideAC, sideBD, sideAC, sideBD) {
		m_name = "Параллелограмм";
	}
	bool isRight() override
	{
		return m_sideA == m_sideC
			&& m_sideB == m_sideD
			&& m_cornerA == m_cornerC
			&& m_cornerB == m_cornerD
			&& Quadrilateral::isRight();
	}
};

class Rectangle : public Parallelogram
{
public:
	Rectangle(int sideAC, int sideBD)
		: Parallelogram(90, 90, sideAC, sideBD) {
		m_name = "Прямоугольник";
	};
	bool isRight() override
	{
		return m_sideA == m_sideC
			&& m_sideB == m_sideD
			&& m_cornerA == 90
			&& m_cornerB == 90
			&& m_cornerC == 90
			&& Quadrilateral::isRight();
	}
};

class Rhomb : public Parallelogram
{
public:
	Rhomb(int cornerAC, int cornerBD, int side)
		: Parallelogram(cornerAC, cornerBD, side, side) {
		m_name = "Ромб";
	};
	bool isRight() override
	{
		return m_sideA == m_sideB
			&& m_cornerA == 90
			&& m_cornerB == 90
			&& m_cornerC == 90
			&& Parallelogram::isRight();
	}
};

class Square : public Rectangle
{
public:
	Square(int side)
		: Rectangle(side, side) {
		m_name = "Квадрат";
	};
	bool isRight() override
	{
		return m_sideA == m_sideB
			&& Rectangle::isRight();
	}
};

int main()
{
	setlocale(LC_ALL, "russian");

	Figure f;
	f.print_info();

	Triangle t(60, 20, 100, 14, 10, 5);
	t.print_info();

	RightTriangle rt(30, 60, 3, 4, 5);
	rt.print_info();

	IsoscelesTriangle it(100, 41, 10, 21);
	it.print_info();

	EquilateralTriangle et(43);
	et.print_info();

	Quadrilateral q(10, 20, 30, 40, 4, 64, 34, 9);
	q.print_info();

	Parallelogram p(40, 50, 20, 30);
	p.print_info();

	Rectangle r(20, 30);
	r.print_info();

	Square s(30);
	s.print_info();

	Rhomb rh(30, 60, 15);
	rh.print_info();
}


