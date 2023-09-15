# 2. Constructors and Destructors

通常我們在宣告 object 時，會去初始化變數和分配動態記憶體，但在上面例子中，我們沒有初始化 Point 中的 x, y 值，

因此，我們在 class 中可以包含一個 constructor 的 function，來讓宣告一個該 class 的 object 時，會自動調用該 constructor 的 function 以初始化變數和分配動態記憶體。

下面就是 constructor 的定義方法：

```
#include <iostream>

class Point {
		int x, y;
	public:
		Point (int, int);
		int distance_to_origin(void);
		int get_x(void) {return x;}
		int get_y(void) {return y;}
};

Point::Point(int a, int b) {
	x = a;
	y = b;
}

int Point::distance_to_origin(void) {
	return x*x + y*y;
}

int main(void) {
	Point new_point (3, 4);
	std::cout << new_point.distance_to_origin() << std::endl;
	return 0;
}
```

可以看到，這邊的 ```Point::Point``` 就是 constructor function 的定義，會在宣告 Point 時初始化 x, y 值。

特別注意 constructor function 的定義不會有返回值。

而 destructor 則是和 constructor 相反的功能，他會在 object 被記憶體釋放時自動調用，destructor 主要用於當我們希望物件存在的 scope 結束時，我們希望釋放該 object 使用的空間時。

下面為一使用 destructor 的例子：

```
#include <iostream>

class Point {
		int *x, *y;
	public:
		Point (int, int);
		~Point ();
		int distance_to_origin(void);
		int get_x(void) {return *x;}
		int get_y(void) {return *y;}
};

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
	Point new_point (3, 4);
	std::cout << new_point.distance_to_origin() << std::endl;
	return 0;
}
```