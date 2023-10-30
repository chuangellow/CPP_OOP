# 14. Relationship Among Classes

當我們 classify 一個需求或我們的系統中有哪些 classes 之後，下一個問題就在於如何將這些 classes 兜起來成為我們的系統，如何去描述 classifier 和 classifier 之間的關係。

而 classifier 和 classifier 間的關係由弱到強又可以分為下面幾種：

1. Dependency: Uses-a
2. Association: Has-a
3. Aggregation: Owns-a
4. Composition: Is-part-of-a
5. Generalization: Is-a

下面先簡述一下這五個關係，和在 Java Code 中的實作方式：

Dependency: 描述說 Source Class 和 Target Class 會有短暫的關係，而 Source Class 不會 hold target as reference，只是用到 target 中的某些 method 等等。

常見的 Java implementation 如下：

```
public class SourceClass {
    public void someMethod(TargetClass target) {
    }
}
```

而當 someMethod 執行完後， target 的 lifecycle 就自動結束了。

Association: 差別在於 Source Class 和 Target Class 的關係是長期的，Source Class 會 hold target as reference，但 Source 和 Target 間實質上沒有 ownership 的關聯性。

舉例來說，假設有一個 class 為 ```Teacher```，另一個 class 是 ```Subject```，可能就有 teacher teaches subject 的關係存在，但 subject 的 lifecycle 應該要和 teacher 無關：

```
public class Teacher {
    private Subject subject;
}
```

Aggregation：和 association 的差別性主要在於是否有 "whole-part" 的關聯性，但卻不用 maintain target class 的 lifecycle，

舉例來說，假設有一個 class 為 ```Department ```，另一個 class 是 ```Employee ```，那麼可以說 ```Employee``` 應為 ```Department``` 的一部分，但 ```Department``` 消失時，```Employee``` 不會消失，

實作上就為：

```
public class Department {
    private List<Employee> employees;
}
```

Composition: 和 Aggregation 的主要差別在於當 Source class 消失後，Target class 應一起消失，Source class 應負責 maintain target class 的 lifecycle，

舉例來說，```Car``` 和 ```Engine```，大部分時，當 ```Car``` 消失後，```Engine``` 應一同報廢，實作上會變成：

```
public class Car {
    private Engine engine = new Engine();
    public Car() {
    }
}
```

因此，在考慮 class 和 class 間的關係時，就需要精準地判斷說要使用何種關係來描述，通常會希望使用弱關係，來讓系統的耦合度不要過高。
