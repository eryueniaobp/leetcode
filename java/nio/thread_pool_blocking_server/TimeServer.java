package nio.thread_pool_blocking_server;

import nio.TimeServerHandler;

import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;

// Reference: http://ifeve.com/netty-definitive-guide-2-2/
public class TimeServer {

    /**
     * @param args
     * @throws IOException
     */
    public static void main(String[] args) throws IOException {
        int port = 8080;
        if (args != null && args.length > 0) {
            try {
                port = Integer.valueOf(args[0]);
            } catch (NumberFormatException e) {
                // 采用默认值
            }
        }
        ServerSocket server = null;
        try {
            server = new ServerSocket(port);
            System.out.println("The time server is start in port : " + port);
            Socket socket = null;
            TimeServerHandlerExecutePool singleExecutor = new TimeServerHandlerExecutePool(
                    10, 5000);// 创建IO任务线程池
            while (true) {
                //如果是长连接的话，这里的accept也是很成问题的
                socket = server.accept();
                //弱点：大量的请求进来，这里处理不及时 或者 直接队列撑满，那么后续的请求就无法 accept 了，就等住了
                singleExecutor.execute(new TimeServerHandler(socket));
            }
        } finally {
            if (server != null) {
                System.out.println("The time server close");
                server.close();
                server = null;
            }
        }
    }
}