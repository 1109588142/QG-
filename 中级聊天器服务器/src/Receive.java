import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.ArrayList;
import java.util.List;

public class Receive {
    public static void main(String[] args) throws IOException {
        List<User> list=new ArrayList<User>();
        ServerSocket serverSocket=new ServerSocket(1300);
        System.out.println("服务器启动成功");
        while(true)
        {
            Socket socket=serverSocket.accept();
            InputStream inputStream=socket.getInputStream();
            InputStreamReader inputStreamReader=new InputStreamReader(inputStream);
            BufferedReader br=new BufferedReader(inputStreamReader);
            String name1= br.readLine();
            User user=new User(name1,socket);
            System.out.println(user.getName()+"正在登陆");
            list.add(user);
            new ServerThread(user,list).start();
        }
    }
}



