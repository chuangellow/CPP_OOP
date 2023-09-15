#include <iostream>

class Point {
		int *x, *y;
	public:
		Point ();
		Point (int, int);
		~Point ();
		int distance_to_origin(void);
		int get_x(void) {return *x;}
		int get_y(void) {return *y;}
};

Point::Point () {
	x = new int;
	y = new int;
	*x = 0;
	*y = 0;
}

Point::Point(int a, int b) {
	x = new int;
	y = new int;
	*x = a;
	*y = b;
}

Point::~Point() {
	delete x;
	delete y;
}

int Point::distance_to_origin(void) {
	return (*x)*(*x) + (*y)*(*y);
}

int main(void) {
	Point p;
	Point new_point (7, 8);
	std::cout << p.get_x() << " " << p.get_y() << std::endl;
	std::cout << new_point.distance_to_origin() << std::endl;
	return 0;
}
