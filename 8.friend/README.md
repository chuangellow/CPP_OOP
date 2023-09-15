# 8. Friend

前面有提到 class 中的 member 可以分成不同的 permission label，其中 protected 和 private 的 member 都不能被所在 class 中被 access，

但如果我們想在其他的 class access 這些 member data 或 function 怎麼辦？ C++ 有提供使用定義 friend class 來允許一個外部 function 或 class 來存取這些 member 的方式。

### 8.1 Friend Functions

下面為一使用到 friend function 的例子：

```
#include <iostream>

using namespace std;

class Point {
	int x, y;
	public:
		Point();
		Point(int x, int y);
		friend int getDistance(Point p1, Point p2);
};

Point::Point() {
	x = 0;
	y = 0;
}

Point::Point(int x, int y) {
	this->x = x;
	this->y = y;
}

int getDistance(Point p1, Point p2) {
	return (p1.x - p2.x) * (p1.x - p2.x) +
		(p1.y - p2.y) * (p1.y - p2.y);
}

int main(void) {
	Point p1(1, 1);
	Point p2(4, 5);
	cout << getDistance(p1, p2) << endl;
	return 0;
}
```

然而，使用 friend function 可能有違我們物件導向設計的精神，因為我們事實上可以將 ```getDistance()``` 放在 class 的宣告和定義中，視為是 class 的 member function，來讓物件和物件互動就好，不需要使用到 external function。

### 8.2 Friend Classes

如同上述所說，我們同樣可以將某個其他 class 加入為 friend，以存取該 class 的 member：

```
#include <iostream>

using namespace std;

class Square;

class Rectangle {
	int width, height;
	public:
		int area() {
			return width * height;
		}
		void convert(Square a);
};

class Square {
	friend class Rectangle;
	private:
		int side;
	public:
		Square(int a) : side(a) {}
};

void Rectangle::convert(Square a) {
	width = a.side;
	height = a.side;
}

int main(void) {
	Rectangle rect;
	Square sqr(6);
	rect.convert(sqr);
	cout << rect.area() << endl;
	return 0;
}
```

可以看到的是，因為我們有宣告 Rectangle classs 為 Square class 的 friend，Rectangle 中的 member function 可以直接 access 到 Square::side。

而要注意的是 class 間的 friend 定義為單向的，以上面的例子來說，Rectangle 是 Square 的 friend，但沒有特別指明，Square 就不為 Rectangle 的 friend。