# 9. Inheritance

物件導向設計裡頭，有[三大特性](https://hackmd.io/aGisSDKGTV-gV-fPcxRnQg?both)：

- Encapsulation
- Inheritance
- Polymorphism

這邊主要先介紹 Inheritance 的觀念， Inheritance 主要的目的在於重用，我們可以基於一個類別生成另一個類別的物件，並讓後者擁有前者所擁有的成員，再加上它自己的成員。

透過繼承的方式，我們可以不用一再撰寫重複的程式碼，並提高程式的可讀性，我們可以透過繼承把多個 class 重複的程式碼寫在同一個 class 以減少「Class 之間」的重複程式碼之外，我們也可以利用繼承減少「class 內部」的重複程式碼。

舉例來說，Rectangle 和 Triangle 都是 Polygon，都有擁有某些共有的特性，此時，我們可以先定義 Polygon 這個 class，並基於這個 class，來繼承得到建構 Rectangle 和 Triangle 兩個 class。

此時，我們會稱 Rectangle 和 Triangle 兩個 class 為 Polygon 這個 base class 的 derived class。

宣告一個 class 為某個 base class 的 derived class 的語法為：

```
class derived_class_name: public base_class_name;
```

### 9.1 Inheritance between classes

下面為一個 inheritance 的例子：

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
	rect.set_values(4, 5);
	trgl.set_values(4, 5);
	cout << rect.area() << endl;
	cout << trgl.area() << endl;
	return 0;
}
```
這裡因為我們有定義了 Rectangle 和 Triangle 為 Polygon 的 derived class，並給予 public 的 permission label，

這裡的 Rectangle 和 Triangle 就繼承了 set_values 的 member function，可以直接使用以設定 width 和 height。

而因為 Polygon class 中的 width 和 height 都設定為 protected 的權限，因此，derived class 也可以繼承並存取得到 width 和 height。

在上面例子裡，Rectangle 和 Triangle 的 member 的存取權限會和繼承到的 Polygon 的存取權限相同：

```
CPolygon::width // protected
CRectangle::width // protected
CPolygon::set_values() // public
CRectangle::set_values() // public
```

這是因為我們在繼承時，是使用 Public 關鍵字：

```
class Rectangle: public Polygon {...}
```

這裡的關鍵字主要在規範說 derived class 從 base class 繼承的成員必須獲得最低的保護程度，以這邊的 public 為例，就不會改變繼承到的 member 的權限，

但如果我們在宣告 derived class 時使用：

```
class Rectangle: private Polygon {...}
```

我們就不能在外部使用 ```ret.set_values()```。

而在 C++ 中，如果沒有明確地在宣告 derived class 時給定繼承限制的話，使用 ```class``` 宣告會預設為 ```private```，使用 ```struct```會預設為 ```public```。

### 9.2 What is inherited from the base class?

Derived class 會繼承 base class 所有的 protected 和 public member，除了下面幾個 member：

- Constructor 和 Destructor
- operator() member
- friend

其中 ```friend``` 沒有預設繼承的原因為防止給予不該給予的 class 或 function 存取權限。

雖然 derived class 的 constructor 和 destructor 不會被自動繼承，但當宣告一個 derived class 時，會自動呼叫 base class 的預設 constructor 和 destructor，

而我們也可以在定義 derived class 時指定在宣告時要呼叫 overloading constructor 和 destructor，透過下面的方式指定：

```
derived_class_name (parameters) : base_class_name (parameters) {}
```

下面為一例：

```
#include <iostream>
#include <string>

using namespace std;

class Mom {
	string name;
	public:
		Mom () {
			cout << "I'm mom" << endl;
		}
		Mom(string name) {
			this->name = name;
		}
};

class Daughter: public Mom {
	public:
		Daughter(string name) {
			cout << "Daughter's name is " << name << endl;
		}
};

class Son: public Mom {
	public:
		Son(string name): Mom(name) {
			cout << "Son's name is " << name << endl;
		}
};

int main(void) {
	Mom mom("Jane");
	Daughter daughter("Kate");
	Son son("John");
	return 0;
}
```
會發現說，在生成一個 daughter object 時，會呼叫 ```Mom()```，而印出 ```I'm mom```，而因為 son object 有指定呼叫的 constructor，所以會呼叫 ```mom(name)```

### 9.3 Multiple inheritance

在 C++ 中，一個 derived class 可以同時繼承多個 base class 的 member，語法如下所示：

```
class Son: public Mom, public Dad {...}
```

下面為一個例子：

```
#include <iostream>
#include <string>

using namespace std;

class Dad {
	protected:
		string name;
	public:
		Dad(string n) : name(n) {}
		void print() { cout << name << endl; }
		void dad_call_son() { cout << "Son! I'm your dad!" << endl; }
};

class Mom {
	protected:
		string name;
	public:
		Mom(string n) : name(n) {}
		void print() { cout << name << endl; }
		void mom_call_son() { cout << "Son! I'm your mom!" << endl; }
};

class Son: public Dad, public Mom {
	public:
		Son(string n) : Dad(n), Mom(n) {}
};

int main(void) {
	Son son("John");
	son.dad_call_son();
	son.mom_call_son();
	return 0;
}
```

可以看到 ```Son``` 同時繼承了 ```Mom``` 和 ```Dad``` 的 member function。