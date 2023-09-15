# 6. This

我們可以透過 ```this``` 關鍵字來在 class 內部取得該 class 的 object 的記憶體位址，```this``` 就是一個 pointer，指向該 class 建構的 object 的記憶體位址。

如下所示：


下面就是使用到 this 的一個例子：

```
#include <iostream>

using namespace std;

class A {
	public:
		int isitme(A *ptr) {
			if (ptr == this) return 1;
			else return 0;
		}
		int* get_address_of_this() {
			return (int*)this;
		}
};

int main(void) {
	A obj;
	A obj2;
	cout << ((obj.isitme(&obj))? "It's me!": "It's not me.") << endl;
	cout << ((obj.isitme(&obj2))? "It's me!": "It's not me.") << endl;
	cout << "&obj: " << &obj << endl;
	cout << "This: " << obj.get_address_of_this() << endl;
	return 0;
}
```

而 ```this``` 關鍵字也常常用於 assignation operator overloading 中，如下所示：

```
Point& Point::operator=(const Point& param) {
	x = param.x;
	y = param.y;
	return *this;
} 
```