# 3. Overloading Constructor

在 C++ 中有提供 function overload 的功能，可以提供一個統一名稱的 function，但不同的 arguments 來讓 compiler 選擇要對應使用的 function。

當我們定義 class 卻沒有定義 constructor 時，編譯器會自動假設兩個 overload constructor 為：

- empty constructor：沒有任何參數的 constructor，被定義為 nop，什麼都不會做。

```
Point::Point () {};
```

- copy constructor：只有一個參數的 constructor，這個參數為該 class 的 object，並將被傳入的 object 中所有 non-static member 的值都複製給這個 object。

```
Point::Point (const Point& point) {
	x=point.x; y=point.y;
}
```

要特別注意的是如果有定義 constructor 後，上面兩個預設的 overload constructor 就不存在了，必須自己定義。

我們也可以自己定義 overload constructor 如下：

```
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

Point::Point() {
	x = new int;
	y = new int;
	*x = 3;
	*y = 4;
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
	Point new_point (3, 4);
	std::cout << new_point.distance_to_origin() << std::endl;
	return 0;
}
```
