import java.io.IOException;
import java.io.PrintWriter;
import java.util.List;

public class ServerThread extends  Thread{
    private User usermax;
    private User user;
    private List<User> list;

    public ServerThread(User user,List<User> list)
    {
        this.user=user;
        this.list=list;
    }
private  void sendToClient(String username,String msg)
{
    for(User user1:list)
    {
        usermax=user1;
        if(!(usermax.getName().equals(username)))
        {
            PrintWriter pw=usermax.getPw();
            pw.println(msg);
            pw.flush();
        }
    }
}
    public void run()
    {
        super.run();
        while (true)
        {
            try {
                String msg=user.getBr().readLine();
                System.out.println(msg);
                String[] str=msg.split(":");
                sendToClient(str[0],msg);
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
    }
}
