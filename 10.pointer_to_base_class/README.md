# 10. Pointer to Base Class

透過繼承，我們可以將 Pointer 設給不同繼承相同 base class 的 derived class，

以下面為例：

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
};

class Rectangle: public Polygon {
	public:
		int area() {
			return width * height;
		}
};

class Triangle: public Polygon {
	public:
		int area() {
			return width * height / 2;
		}
};

int main(void) {
	Rectangle rect;
	Triangle trgl;
	Polygon *ppoly1 = &rect;
	Polygon *ppoly2 = &trgl;
	ppoly1->set_values(4, 5);
	ppoly2->set_values(4, 5);
	cout << rect.area() << endl;
	cout << trgl.area() << endl;
	return 0;
}
```

可以看到，雖然 rect 和 trgl 為兩種不同的 class type，但因為都是繼承於 Polygon，可以指定給 Polygon class pointer 而是有效的。

但差別在於，因為 ppoly 為 pointer to Polygon，無法使用到 Triangle 或 Rectangle 裡的 member function ```area```，如：

```
ppoly1->area()
```

會出現 compilation error，因為 ppoly1 為 Polygon class