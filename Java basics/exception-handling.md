# 예외 처리 (Exception Handling) 

## 예외 처리의 중요성 

- 프로그램의 비정상 종료를 피하여 시스템이 원활히 실행되도록 함
- 오류가 발생한 경우 log 를 남겨서 원인을 파악할 수 있도록 함
- 자바는 안정성이 중요한 언어로 대부분 프로그램에서 발생하는 오류에 대해 문법적으로 예외 처리를 해야함


## 구조 

- 시스템 오류(error) : 가상 머신에서 발생, 프로그래머가 처리 할 수 없는 오류 (ex. 동적 메모리가 없는 경우, 스택 메모리 오버플로우 등) 
- 예외(exception) : 프로그램에서 제어할 수 있는 오류 (ex. 읽어들이려는 파일이 존재하지 않는 경우, 네트워크나 DB 연결이 안 되는 경우 등)

![image](https://user-images.githubusercontent.com/43959582/126062415-c8406b2b-7018-48af-92a6-a9209d7f36a8.png)

```java
java.lang.Object
    java.lang.Throwable
        java.lang.Exception
```
- 모둔 예외 클래스의 최상위 클래스는 Exception 클래스


## try-catch 문 

- try 블록에는 예외가 발생할 가능성이 있는 코드를 작성하고 try 블록 안에서 예외가 발생할 경우 catch 블록이 수행됨
- try 블록에서 예외가 발생해도 프로그램이 종료되거나 멈추지 않고 catch 블록을 수행한 후 계속 진행됨

```java
public class ArrayExceptionHandling {
    public static void main (String[] args){
        int[] arr = {1, 2, 3, 4, 5};
        
        try{
            for (int i = 0; i <= 5; i++) System.out.println(arr[i];
        } catch (ArrayIndexOutOfBoundsException e){
            System.out.println (e);
        }
        System.out.println("프로그램이 죽지 않고 여기까지 실행된다.");
    }
}
```

## 예외 처리 미루기 

- throws 를 사용하면 예외가 발생하는 곳이 아닌 사용하는 문장에서 예외 처리를 할 수 있음

```java
public class ThrowsException {
    // 예외가 발생하는 곳에서는 throws 로 그냥 넘김
    public Class loadClass (String fileName, String className) throws FileNotFoundException, ClassNotFoundException{
        FileInputStream fis = new FileInputStream (fileName); // FileNotFoundException 발생
        Class c = Class.forName (className);    // ClassNotFoundException 발생
    }
    
    // 이를 사용하는 곳에서 try-catch 로 처리
    public static void main (String[] args){    
        ThrowsException test = new ThrowsException ();
        
        try {
            test.loadClass ("a.txt", "java.lang.String");
        } catch (FileNotFoundException e){
            e.printStackTrace ();
        } catch (ClassNotFoundException e){
            e.printStackTract ();
        } catch (Exception e){    // 모든 예외는 Exception 클래스를 상속받으므로 이외의 모든 예외에 대해 default 처리를 해줄 수 있다.
            e.printStackTrace ();
        }
    }
}
```

## 사용자 정의 예외 클래스 

- Exception 클래스를 상속하여 필요한 예외 클래스를 직접 만들어 사용 가능
- 패스워드에 대한 예외 처리

```java
public class PasswordException extends Exception{
    public PasswordException(String message) {
        super(message);
    }
}
```
```java
public class PasswordTest {
    private String password;

    public String getPassword(){
        return password;
    }

    public void setPassword(String password) throws PasswordException{
        if(password == null){
            throw new PasswordException("비밀번호는 null 일 수 없습니다");
        }
        else if(password.length() < 5){
            throw new PasswordException("비밀번호는 5자 이상이어야 합니다.");
        }
        else if (password.matches("[a-zA-Z]+")){
            throw new PasswordException("비밀번호는 숫자나 특수문자를 포함해야 합니다.");
        }
        this.password = password;
    }

    public static void main(String[] args) {
        PasswordTest test = new PasswordTest();
        String password = null;
        
        try {
            test.setPassword(password);
        } catch (PasswordException e){
            System.out.println(e.getMessage());
        }
    }
}

```
