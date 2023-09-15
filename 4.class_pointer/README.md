# 4. Class Pointer

Class 同樣可以使用 pointer 來存取，只要當 class 定義後，就是一種有效的 data type，可以直接用下面的方式宣告 class point：

```
Point *point;
```

和一般指標使用方式都相同，要利用 class pointer 來存取該 class 中的 member，可以使用 operator ```->```

如下例：

```
int main(void) {
	Point *p = new Point(3, 4);
	Point new_point = Point(5, 6);
	Point *pp = &new_point;
	std::cout << p->get_x() << std::endl;
	std::cout << p->get_y() << std::endl;
	std::cout << (*pp).get_x() << std::endl;
	std::cout << (*pp).get_y() << std::endl;
	return 0;
}
```

直接透過 operator ```p->member``` 來使用 Pointer 的 member function，也等價於使用：```(*p).member```