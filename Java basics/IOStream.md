# 입출력 스트림 (I/O Stream) 

- 자바는 다양한 입출력 장치에 독립적으로 일관성있는 입출려을 입출력 스트림을 통해 제공함

## 스트림의 종류 

- 입력 스트림 : FileInputStream, FileReader, BufferedInputStream, BufferedReader, ...
- 출력 스트림 : FileOutputStream, FileWriter, BufferedOutputStream, BufferedWriter, ...


- 바이트 단위 스트림 : 데이터를 바이트 단위로 읽고 쓸 때 사용. (ex. 동영상, 음악 파일, 실행 파일 등의 자료) - Stream 으로 끝나는 스트림들 (ex. FileInputStream, BufferedInputStream, ..)
- 문자 단위 스트림 : 인코딩에 맞게 2바이트 이상으로 처리하도록 구현된 스트림. - Reader, Writer 로 끝나는 스트림들 (ex. FileReader, FileWriter, ..)

![스크린샷 2021-07-19 오후 10 19 22](https://user-images.githubusercontent.com/43959582/126166029-d13c2f18-85b1-4ad6-8eac-2cae27a7db8a.png) 


## 기반 스트림과 보조 스트림 

- 기반 스트림 : 대상에 직접 자료를 읽고 쓰는 기능의 스트림 (ex. FileInputStream, FileOutputStream, FileReader, FileWriter, ...)
- 보조 스트림 : 직접 읽고 쓰는 기능은 없이 추가적인 기능을 더해주는 스트림 (ex. InputStreamReader, OutputStreamWriter, BufferedInputStream, BufferedOutputStream, ...)
- 보조스트림은 항상 기반 스트림이나 다른 보조 스트림을 생성자의 매개 변수로 포함해야 함

![스크린샷 2021-07-19 오후 10 50 29](https://user-images.githubusercontent.com/43959582/126170529-3196423a-3ba6-4174-8330-77f444f46fb5.png) 



## 표준 입출력 멤버

```java
public class System {
    public static PrintStream out;    // System.out.println("message");
    public static PrintStream in;     // int d = System.in.read();
    public static PrintStream err;    // System.err.println("error");
}
```
```java
try { // 한 줄 입력받고 출력하기
    while ((i = System.in.read ()) != '\n'){
        System.out.print((char)i);
    }
} catch (IOException e){
    e.printStackTrace();
}
```

## 바이트 단위 입출력 스트림 

- InputStream : 바이트 단위 입력 스트림 최상위 추상 클래스
- 주요 하위 클래스 : `FileInputStream`, `ByteArrayInputStream`, `FilterInputStream`, ...
- 주요 메서드 : `int read()`, `int read(byte b[])`, `int read(byte b[], int off, int len)`, `void close()`, ...

```java
try(FileInputStream fis = new FileInputStream("input.txt")){ 
    int i;
    while ( (i = fis.read()) != -1){
        System.out.println((char)i);
    }
} catch (FileNotFoundException e) {
    e.printStackTrace();
} catch (IOException e) {
    e.printStackTrace();
}
```

- OutputStream : 바이트 단위 출력 스트림 최상위 추상 클래스
- 주요 하위 클래스 : `FileOutputStream`, `ByteArrayOutputStream`, `FilterOutputStream`, ...
- 주요 메서드 : `int write()`, `int write(byte b[])`, `int write(byte b[], int off, int len)`, `void flush()`, `void close()`, ...

```java
try(FileOutputStream fos = new FileOutputStream("output.txt",true)){
    byte[] bs = new byte[26];
    byte data = 65;        //'A' 의 아스키 값
    for(int i = 0; i < bs.length; i++){  // A-Z 까지 배열에 넣기
        bs[i] = data;
        data++;
    }
    fos.write(bs);  //배열 한꺼번에 출력하기
}catch(IOException e) {
    e.printStackTrace();
}

```

## 문자 단위 입출력 스트림 

- Reader : 문자 단위 입력 스트림 최상위 추상 클래스
- 주요 하위 클래스 : `FileReader`, `InputStreamReader`, `BufferedReader`, ...
- 주요 메서드 : `int read()`, `int read(char buf[])`, `int read(char buf[], int off, int len)`, `void close()`, ...

```java
try(FileReader fr = new FileReader("reader.txt")){
    int i;
    while( (i = fr.read()) != -1){
        System.out.print((char)i);
    }
} catch (IOException e) {
    e.printStackTrace();
}
```

- Writer : 문자 단위  스트림 최상위 추상 클래스
- 주요 하위 클래스 : `FileWriter`, `OutputStreamWriter`, `BufferedWriter`, ...
- 주요 메서드 : `int writer()`, `int writer(char buf[])`, `int writer(char buf[], int off, int len)`, `int write(String str)`, `int write(String str, int off, int len)`, `int flush()`, `void close()`, ...

```java
try(FileWriter fw = new FileWriter("writer.txt")){
    fw.write('A');    // 문자 하나 출력
    char buf[] = {'B','C','D','E','F','G'};

    fw.write(buf); //문자 배열 출력
    fw.write("안녕하세요"); //String 출력
    fw.write(buf, 1, 2); //문자 배열의 일부 출력
    fw.write("65");  //숫자를 그대로 출력
}catch(IOException e) {
    e.printStackTrace();
}
```

## 보조 스트림 사용 

- BufferedInputStream, BufferedOutputStream

```java
  // a.zip 을 copy.zip 으로 복사
  long millisecond = 0;
  try(FileInputStream fis = new FileInputStream("a.zip");
          FileOutputStream fos = new FileOutputStream("copy.zip");
          BufferedInputStream bis = new BufferedInputStream(fis);   // 매개변수로 기반스트림을 받아서 기능을 더함
          BufferedOutputStream bos = new BufferedOutputStream(fos)){       
      int i;
      while( ( i = bis.read()) != -1){
          bos.write(i);
      }
  }catch(IOException e) {
      e.printStackTrace();
  }
```

- DataInputStream, DataOutputStream

```java
try(FileOutputStream fos = new FileOutputStream("data.txt");
        DataOutputStream dos = new DataOutputStream(fos)){
    dos.writeByte(100);
    dos.writeChar('A');
    dos.writeInt(10);
    dos.writeFloat(3.14f);
    dos.writeUTF("Test");
} catch (IOException e) {
    e.printStackTrace();
}

try(FileInputStream fis = new FileInputStream("data.txt");
        DataInputStream dis = new DataInputStream(fis)){
    System.out.println(dis.readByte());
    System.out.println(dis.readChar());
    System.out.println(dis.readInt());
    System.out.println(dis.readFloat());
    System.out.println(dis.readUTF());
} catch (IOException e) {
    e.printStackTrace();
}
```

## 직렬화 (Serialization)

- 인스턴스의 상태를 그대로 파일로 저장하거나 네트워크로 전송(serialization)하고, 이를 다시 복원(deserialization) 하는 방식
- 보조 스트림을 활용
- `OujectInputStream(InputStream in)`, `ObjectOutputStream(OutputStream out)`
- 인스턴스의 내용이 외부로 유출되는 작업이므로 직렬화 하려는 클래스는 Serializable 인터페이스를 구현하도록 하여 구분
- 직렬화 하려는 클래스에 직렬화 하지 않으려는 멤버 변수는 transient 로 선언한다. (Socket 등 직렬화 할 수 없는 객체) 

```java
class Person implements Serializable { ... }
```
```java
// main
Person personAhn = new Person("이순신", "대표이사");
Person personKim = new Person("김유신", "상무이사");

try(FileOutputStream fos = new FileOutputStream("serial.out");
        ObjectOutputStream oos = new ObjectOutputStream(fos)){
    oos.writeObject(personAhn);
    oos.writeObject(personKim);
}catch(IOException e) {
    e.printStackTrace();
}

try(FileInputStream fis = new FileInputStream("serial.out");
        ObjectInputStream ois = new ObjectInputStream(fis)){
    Person p1 = (Person)ois.readObject();
    Person p2 = (Person)ois.readObject();

    System.out.println(p1);
    System.out.println(p2);
}catch (IOException e) {
    e.printStackTrace();
}
```
- Externalizable 인터페이스 : writeExternal(), readExternal() 메서드를 구현하여 객체를 읽고 쓰는 코드를 직접 구현할 수 있음

## RandomAccessFile 클래스 

- 입출력 클래스 중 유일하게 파일에 대한 입력과 출력을 동시에 할 수 있는 클래스
- 파일 포인터가 있어서 읽고 쓰는 위치의 이동이 가능함. 
