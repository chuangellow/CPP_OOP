# Object-oriented Programming vs. Functional Programming

## 1. What are OOP and FP?

不論 OOP 或是 FP 都是一種 computation paradigm，用作幫助我們寫出可讀性高又容易理解的程式。

而所有程式中，又主要分為兩個主要部分：

- data：程式中的變數，操作的狀態
- behavior：定義資料的變化，和狀態的轉移

而 OOP 使用的方法是將 data 和 behavior 統一定義在一個地方，這個地方就是 object，透過 object 我們可以更好理解資料的運作和行為。

而 FP 則相反，明確地切割出 data 和 behavior。

FP 和 OOP 的目標都是適度替程式設計附加抽象化，減少無謂的細節，更好閱讀及維護，溝通也會更加容易，只是 OOP 偏向更大觀點的抽象， FP 則偏向實作細節的抽象。

系統越來越龐大時，用 OOP 的觀點會很容易看出單元跟單元間的互動，但若只使用 FP 來看則會被密密麻麻的 function 互動給淹沒。

而進入實作層面時，用 FP 的觀念可以很快地把功能本身以抽象化的方式實作出來，OOP 雖然也做得到但確實就比繁瑣。

Ref: [黃升煌 Mike](https://ithelp.ithome.com.tw/articles/10233399)

## 2. OOP Computation Paradigm

下面為一具體的情境來描述兩者的差別：

> Let’s say you run a company and you’ve just decided to give all your employees a $10,000.00 raise. (If this sort of thing happens often at your company, let me know when you’re hiring) How could we write a command-line script to make this change?
> 
> You most likely have all your employee records in a database with two attributes: the employee’s name and a current salary. In our examples, we’ll ignore the part where you transfer the data to and from the database. Let’s just focus on the “giving a raise” feature.

使用 OOP 來完成該 task 的方法為：

```
class Employee {
	private:
		string name;
		int salary;
	public:
		Employee();
		Employee(string name, int salary);
		void setName(string name);
		string getName();
		void addSalary(int salary);
		void description();
};
```
將每個職員抽象化為一個 ```Employee``` 的 class，透過該 class 的 member function，提供使用者一個介面來更改該職員的薪水。

我們就能輕鬆的宣告一個 employee 的 object array，透過 for loop 來將所有 object 調薪。

```
int main(void) {
	Employee e[3] = {
		Employee("John", 10000),
		Employee("Mary", 20000),
		Employee("Bob", 30000)
	};

	cout << "Before adding salary: \n" << endl;
	for (Employee& emp : e) {
		emp.description();
	}
	for (Employee& emp : e) {
		emp.addSalary(10000);
	}
	cout << "After adding salary: \n" << endl;
	for (Employee& emp : e) {
		emp.description();
	}
}
```

可以發現 OOP 中裡的幾個特點：

- Data is supplied to an object at the time the object is created
- We use methods on that object  to interact with data that we’ve already stored
- All the behaviors that are associated with that object type, making them easy to find if we’re unfamiliar with the codebase or refreshing our memory after some time away.
- The object is an obvious location to add behaviors as our project becomes more complex.

## 3. FP Computation Paradigm

下面則是 functional programming 處理該情境時，會使用的方式：

```
string employeeName[3] = {"John", "Mary", "Jason"};
int employeeSalary[3] = {3000, 4000, 5000};
```
將資料直接以 array 或是其他資料結構儲存，與其將資料和行為都包裝在一個物件上，不如將資料分割出去，並將行為額外定成 function，

```
int *happierEmployeeSalary = addSalary(employeeSalary, 3, 1000);
```
因為現在資料不是被包裝在物件中，我們的方法就必須提供 data 給 function 進行操作，function 就會回傳已經操作過後的資料，並存在另一個陣列中。

```
int main(void) {
	string employeeName[3] = {"John", "Mary", "Jason"};
	int employeeSalary[3] = {3000, 4000, 5000};
	cout << "Before addSalary" << endl;
	for (int i = 0; i < 3; i++) {
		cout << employeeName[i] << " " << employeeSalary[i] << endl;
	}
	int *happierEmployeeSalary = addSalary(employeeSalary, 3, 1000);
	cout << "After addSalary" << endl;
	for (int i = 0; i < 3; i++) {
		cout << employeeName[i] << " " << happierEmployeeSalary[i] << endl;
	}
	return 0;
}
```
可以發現 FP 和 OOP 不同的行為有：

- FP likes to view everything as a data transformation
- The original array is untouched
- This idea of not changing the contents (or “state”) of a variable once it’s been created is called immutability

> In the OOP version, the contents of the employees array changes over time: before change_salary is applied the salaries are 100K and 125K, but afterwards they are 110K and 135K! 
> 
> This means we don’t always know which value we’ll have at any given point in the program: we have to walk through the program flow and find out if change_salary has been called or not. 
> 
> This can be difficult as the program increases in complexity. The FP version avoids this because employees represents the “before” state and happier_employees represents the “after” state. Their values are always the same over their entire existence.

## Reference

[Object Oriented Programming vs. Functional Programming](https://www.codenewbie.org/blogs/object-oriented-programming-vs-functional-programming)