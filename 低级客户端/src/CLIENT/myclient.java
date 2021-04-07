package CLIENT;

import java.io.*;
import java.net.DatagramSocket;
import java.net.Socket;
import java.nio.charset.StandardCharsets;

public class myclient {
    public static void main(String[] args) throws IOException {
        Socket socket=new Socket("127.0.0.1",1200);
      new Receive(socket).start();
      new Send(socket).start();
    }
}
class Receive extends Thread{
    private final Socket socket;
    public Receive(Socket socket)
    {
        this.socket=socket;
    }
    public void run()
    {
        super.run();
        try {
            DataInputStream dataInputStream = new DataInputStream(socket.getInputStream());
            while(true){
                String msg = dataInputStream.readUTF();
                System.out.println("收到消息："+msg);
            }
        } catch (IOException e) {
            e.printStackTrace();
        }


    }
}
class Send extends Thread{
    private final Socket msocket;
    public Send(Socket msocket)
    {
        this.msocket=msocket;
    }
    public void run()
    {
        super.run();
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        try {
            DataOutputStream dataOutputStream = new DataOutputStream(msocket.getOutputStream());
            while(true){
                String line = br.readLine();
                dataOutputStream.flush();
                dataOutputStream.writeUTF(line);
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
