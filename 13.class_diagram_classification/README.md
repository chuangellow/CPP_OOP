# 13. Class Diagram

在實際做 coding 之前，我們應先將 class 和 class 間的關係設計好，而一個好的視覺化該設計的方式就是利用 UML 裡的 class diagram。

## Why we need UML class diagram?

透過先做設計再實作設計的方式，可以大幅度地幫助下面幾件事：

1. 可以在 high-level 角度用人類語言釐清設計上會遇到的問題。
2. 可以透過 class diagram 視覺化，比繁雜地 trace code 更能釐清架構。
3. 與人溝通的成本降低，可以用自然語言描述該設計，而對方不用有程式語言的先備知識。
4. 幫助未來實作時，更好掌握模組間的關係。

## Classification

在遇到一個需求要設計一個系統時，必須先做 classification，搞清楚目前系統中有哪些 classifier，

classifier 就為一群具有相同性質的事物，我們將其抽象化，成為一個 classifier，舉例來說，貓和狗，我們可以 classify 為動物這個 classifier。

而常見的 classifier 共有下面幾種：

1. Class
2. Abstract Class
3. Interface

## Class

Class 定義了一個 object 的行為，裡頭必須包含下面幾個定義：

1. attribute: object 所包含有的 data
2. operation: object 可以進行的行為
3. visiability: access 這個 object 的 attribute 和 operation 的方式

object 會稱為 class 的 instance，而創建一個 class 的 object 稱為 instantiation。

而一般，class 在 UML class diagram，會包含三個資訊，Class Name、Attribute 和 Operation。

## Abstract Class

Abstract class 為在 class 中有一些 operation 只有提供 signature 而沒有實作，可能會留到 sub-class 中才讓這些 sub-class overide 這些 operation 的實作。

可以以 Java Code 為例：

```
abstract class Animal {
	abstract public void move(); // OK!
	public void eatFood(); // Compilation Error!
	public void makeSound() {
		Console.WriteLine("Hi");
	}
}

class Dog: Animal {
	public override void eatFood() {
		Console.WriteLine("I'm eating meat!!!");
	}
}
```

裡頭可以看到 ```public void makeSound();``` 實際執行會發生 CE，原因在於 abstract class 中如有沒實作的 operation，需要加上```abstract``` keyword。

但在 abstract class 中是可以對某些 operation 實作的。

而之後如果有他的子類別要實作 abstract operation 的話，就要使用 ```override``` 關鍵字來實作。

## Virtual Operation

Virtual 和 abstract 的差別可以由下面例子看到：

```
class Animal {
	virtual public void move(); // OK!
	virtual void eatFood(); // Compilation Error!
	virtual public void makeSound(); // Compilation Error!
}
```
可以看到的是， virtual operation 一定要為 public operatioon，且一定要實作，否則就會 CE。

而在子類別中，對於 virtual operation，可以選擇 ```override``` 來實作，也可以不。

## Interface

Interface 為一種 classifier，裡面可能會宣告一些 operations，但這些 operations 都沒有實作。

以下面的 Code 為例：

```
interface makeSound {
	void bark(); // OK!
	public void meow(); // Compilation Error!
	int decibel; // Compilation Error!
	void chuchu() { } // Compilation Error!
}
```
可以看到的是，如果 interface 中的 operation 被實作一定得是 public，所以本身不能宣告 public 且 operation 必不能在 interface 裡實作，且不能宣告 attribute。

## Reference

1. [interface , abstract , virtual 差異](https://dotblogs.com.tw/enet/2017/01/04/122935)
2. 台大李允中軟體工程課堂內容