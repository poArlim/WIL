# 자바 Thread

## Thread 클래스 상속하여 만들기 

- Thread 클래스를 상속하여 만들 수 있고, run() 메서드에 스레드가 할 작업을 구현
- 인스턴스 생성 후 start() 메서드로 스레드를 실행시킴

```java
class MyThread extends Thread {
    public void run (){
        ...
    }
}

public class ThreadTest {
    public static void main (String[] args){
        MyThread th1 = new Mythread ();
        MyThread th2 = new Mythread ();
        th1.start ();
        th2.start ();
    }
}
```

## Runnable 인터페이스 구현하여 만들기 

- 이미 다른 클래스를 상속하여 Thread 클래스를 상속받지 못할 겅우 Runnable 인터페이스를 구현
- Runnable 인터페이스를 구현한 인스턴스를 매개변수로 스레드 인스턴스 생성 후 start () 로 실행

```java
class MyThread implements Runnable {
    public void run (){
        ...
    }
}

public class ThreadTest {
    public static void main (String[] args){
        MyThread mth = new MyThread ();
        Thread th1 = new Thread (mth);
        th1.start ();
        
        Thread th2 = new Thread (new MyThread ());
        th2.start ();
        
    }
}
```

## 우선순위 

- Thread.MIN_PRIORITY = 1
- Thread.MAX_PRIORITY = 10
- Thread.NORMAL_PRIORITY = 5
- `setPriority()`/`getPriority()`


## join()

- 동시에 두 개 이상의 Thread 가 실행 될 때 다른 Thread 의 결과를 참조하여야 하는 경우 사용
- join() 함수를 **호출한** 스레드가 not-runnable 상태가 됨 (lock_acquire 와 유사함)
- 참조한 스레드의 수행이 끝나면 runnable 상태로 돌아옴

```java
public static void main (String[] args){
    ...
    th1.start ();
    th2.start ();
    
    try {
        th1.join ();    // main 스레드에서 th1 스레드에 join
        th2.join ();    // main 스레드에서 th2 스레드에 join
    } catch (InterruptedException e){
        System.out.println (e);
    }
    
    int lastTotal = th1.total + th2.total;  // th1, th2 실행이 모두 완료된 후에 실행
}
```

## 동기화 (Synchronization) 

- synchronized 메서드나 synchronized 블럭을 사용
- synchronized 로 선언된 메서드가 실행될 때 메서드가 속해있는 객체에 lock 을 건다.
- deadlock 을 방지하기 위해 synchronized 메서드에서 다른 synchronized 메서드는 호출하지 않는다.


## wait()/notify()

- wait() 는 스레드를 not-runnable 상태로 만듬
- notify() 는 wait() 상태의 스레드들 중 임의로 하나의 스레드를 runnable 상태로 깨움 (starvation 발생 가능성이 있어서 notifyAll() 사용을 권장)
- notifyAll() 은 모든 wait() 상태의 스레드를 께움, 유효한 리소스만큼의 스레드가 수행되고 자원을 갖지 못한 스레드는 다시 wait() 상태로 만든다.


![image](https://user-images.githubusercontent.com/43959582/126277092-38dfd3b2-631f-4447-abfc-8ed5e57b7b92.png) 

