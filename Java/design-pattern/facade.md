# 파사드 패턴 (Facade Pattern) 

파사드는 건물의 앞쪽 정면이라는 뜻을 가진다. 객체와 실제 사용하는 서브 객체들의 사이에 복잡한 의존관계가 있을 때, 중간에 facede 라는 객체를 두고 여기서 제공하는 interface 만을 활용하여 기능을 사용하는 방식이다.

![스크린샷 2021-07-21 오후 8 47 49](https://user-images.githubusercontent.com/43959582/126483857-97845d94-441b-4152-b6cc-556ee01516e8.png) 

Client 객체는 FTP, WRITER, READER 객체들의 상세한 구현을 몰라도 facade 객체가 제공하는 인터페이스(connect(), read(), write() 등의 메서드)만으로 기능을 사용할 수 있다. 


- FTP 프로토콜 
```java
public class FtpProtocol {
    
    public FtpProtocol(String host, int port, String path){
        System.out.println("ftp server create");
    }
    
    public void connect(){
        System.out.println("ftp server connected");
    }
    
    public void moveDirectory(){
        System.out.println("move path");
    }
    
    public void disConnect(){
        System.out.println("ftp server disConnected");
    }
}
```

- File Reader
```java
public class FileReader {
    private String fileName;
    
    public FileReader(Stirng fileName){
        this.fileName = fileName;
    }
    
    public void fileConnect(){
        System.out.println("FileReader Connected");
    }
    
    public void fileRead(){
        System.out.println("Read file");
    }
    
    public void fileDisconnect(){
        System.out.println("FileReader disConnected");
    }
}
```

- File Writer
```java
public class FileWriter {
    private String fileName;
    
    public FileWriter(Stirng fileName){
        this.fileName = fileName;
    }
    
    public void fileConnect(){
        System.out.println("FileWriter Connected");
    }
    
    public void fileWrite(){
        System.out.println("Write file");
    }
    
    public void fileDisconnect(){
        System.out.println("FileWriter disConnected");
    }
}
```

- sftp 클라이언트 : facade 로써 클라이언트에게 이 건물의 정면만을 보고 기능을 사용할 수 있게 해준다.
```java
public class SftpClient {

    private FtpProtocol ftpProtocol;
    private FileReader fileReader;
    private FileWriter fileWriter;

    public SftpClient(String host, int port, String path, String fileName){
        this.ftpProtocol = new FtpProtocol(host, port, path);
        this.fileReader = new FileReader(fileName);
        this.fileWriter = new FileWriter(fileName);
    }

    public void connect(){
        this.ftpProtocol.connect();
        this.ftpProtocol.moveDirectory();
        this.fileReader.fileConnect();
        this.fileWriter.fileConnect();

    }

    public void write(String content){
        this.fileWriter.fileWrite(content);
    }

    public String read(){
        return this.fileReader.fileRead();
    }

    public void disConnect(){
        this.fileReader.fileDisconnect();
        this.fileWriter.fileDisconnect();
        this.ftpProtocol.disConnect();
    }
}
```




