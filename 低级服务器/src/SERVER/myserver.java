package SERVER;

import javax.lang.model.type.NullType;
import java.io.*;
import java.net.ServerSocket;
import java.net.Socket;
import java.nio.charset.StandardCharsets;

public class myserver {
public static  final int PORT=1200;

    public static void main(String[] args) throws IOException {
        Socket socket;
       ServerSocket serverSocket = new ServerSocket(PORT);
            socket = serverSocket.accept();
        new Send(socket).start();
        new Receive(socket).start();
    }
}
class Send extends Thread{
    private final Socket msocket;
    public  Send(Socket socket)
    {
        this.msocket=socket;
    }
    public void run()
    {
        super.run();
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        try {
            DataOutputStream dataOutputStream = new DataOutputStream(msocket.getOutputStream());
            while(true){
                String msg = br.readLine();
                dataOutputStream.flush();
                dataOutputStream.writeUTF(msg);
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
class Receive extends Thread{
    private final Socket socket ;
    public  Receive(Socket socket)
    {
        this.socket=socket;
    }
   public void run()
   {
       super.run();

       try {
           DataInputStream dataInputStream = new DataInputStream(socket.getInputStream());
           while(true){
               String line = dataInputStream.readUTF();
               System.out.println("收到消息："+line);
           }
       } catch (IOException e) {
           e.printStackTrace();
       }

   }

}