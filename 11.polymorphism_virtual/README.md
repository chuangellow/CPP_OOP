# 11. Polymorphism: Virtual Members

在第 10 單元中，有看到一例為在 derived class 中才定義的 member function，無法使用到 base class pointer 存取，

因此，一種方式是在 base class 裡宣告它，而不是 derived class，具體作法是利用 C++ 裡的 virtual 關鍵字，

virtual 關鍵字可以讓我們在 base class 中定義的 member 在 derived class 裡再細化。

下面為一例：

```
#include <iostream>

using namespace std;

class Polygon {
	protected:
		int width, height;
	public:
		void set_values(int a, int b) {
			width = a;
			height = b;
		}
		virtual int area(void) {
			return 0;
		}
};

class Rectangle: public Polygon {
	public:
		int area(void) {
			return width * height;
		}
};

class Triangle: public Polygon {
	public:
		int area(void) {
			return (width * height / 2);
		}
};

int main(void) {
	Polygon poly;
	Rectangle rect;
	Triangle trgl;
	Polygon *ppoly1 = &rect;
	Polygon *ppoly2 = &trgl;
	Polygon *ppoly3 = &poly;
	ppoly1->set_values(4, 5);
	ppoly2->set_values(4, 5);
	ppoly3->set_values(4, 5);
	cout << ppoly1->area() << endl;
	cout << ppoly2->area() << endl;
	cout << ppoly3->area() << endl;
	return 0;
}
```

可以看到，因為在 Polygon 宣告中有額外加入 virtual function 的 definition，
所以可以直接使用：``` ppoly1->area()``` 而不會報錯。

而因為加了 ```virtual``` 關鍵字，```area()``` 這個 member function 我們又可以在 derived class 裡再細化它的定義，所以在調用不同 dervied class 時可以使用到對應的 ```Triangle::area()``` 和 ```Rectangle::area()```

一但拿掉 ```virtual``` 後，會一律呼叫 ```Polygon::area()```，因此一律得到 0 值。

因此，使用 ```virtual``` 關鍵字是讓當使用 base class pointer 時，可以適當地呼叫 derived class 中的 member function 定義。