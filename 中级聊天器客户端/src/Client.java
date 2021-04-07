import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.Socket;

public class Client {
    public static void main(String[] args) throws IOException {
        Socket socket=new Socket("127.0.0.1",1300);
        System.out.println("请输入你要使用的名字");
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        String username=br.readLine();
        System.out.println("聊天开始");
        PrintWriter out=new PrintWriter(socket.getOutputStream());
        out.println(username);
        out.flush();
     ClientThread clientThread=new ClientThread(socket);
     clientThread.start();
     while(true)
     {
         String msg=username+":"+ br.readLine();
         out.println(msg);
         out.flush();
     }
    }
}
