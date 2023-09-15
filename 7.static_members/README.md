# 7. Static Members

在 C++ 中，我們也可以去定義一個 static member，static member 可以是資料或函數。
一個 class 中的 static member 又可以被稱為 class variables，因為該變數不是綁定在 object 上，而是所有 class 都有相同的值。

舉例來說，我們可以利用 static member 來統計該 class 中宣告物件的總數：

```
#include <iostream>

using namespace std;

class Point {
	int x, y;
	public:
		static int count;
		Point() {
			x = 0;
			y = 0;
			count++;
		}
		~Point() {
			count--;
		}
		Point(int x, int y) {
			this->x = x;
			this->y = y;
			count++;
		}
		void print() {
			cout << "(" << x << ", " << y << ")" << endl;
		}
};

int Point::count = 0;

int main(void) {
	Point p1 = Point(1, 2);
	Point p2 = Point(3, 4);
	p1.print();
	p2.print();
	cout << "Number of points: " << Point::count << endl;
	return 0;
}
```

但為了避免多次重複宣告，根據 ANSI-C++ 標準，在 class 的宣告中只能包括 static member 的 prototype，而不能在 class 宣告中定義該 static member。

因此 static data 要在 class 宣告外做初始化，如上面的：

```
int Point::count = 0;
```

而因為該 static member 為所有的該 class 的 object 所共有，所以任何該 class 的 object 都能 access 到該 static member 如：```p1.count``` 或是直接用 ```Point::count``` 來存取。

最後，可以將 static member 視為就是跟在某一 class 後的 global variable，因為 static member 是綁定在 class 而不是 object 上，因此也不能使用 ```this``` 來引用物件指標。