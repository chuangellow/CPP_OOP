# 12. Polymorphism: Abstract Base Classes

Abstract base class 可以讓我們在定義一個多型的 member function 時不做定義，下面是他的語法：

```
virtual int area (void) =0;
```

可以看到的是，在 virtual function 後加入 ```=0``` 來代替 function 的具體 implementation，而這種 function 又會被稱作 **pure virtual function**

所有有包含  **pure virtual function** 的 base class 就會稱為 **abstract base class**。

而 **abstract base class** 和一般的 base class 的差別在於不能 instantiate 一個 **abstract base class** 的 object，但我們可以定義一個 class pointer 指向 **abstract base class** 。

像下面的例子：

```
class Polygon {
	protected:
		int width, height;
	public:
		void set_values(int a, int b) {
			width = a;
			height = b;
		}
		virtual int area(void) = 0;
};
```

我們無法使用：

```
Polygon poly;
```
而只能使用：

```
Polygon* ppoly;
```

這是因為 abstract base class 中的 pure virtual function 還沒被實現，後面討論到 design pattern 時，也會介紹到 abstract base class 的好處。

原因主要在於物件導向設計的一大精神為：
> 針對介面寫程式，不要針對實作寫程式
		