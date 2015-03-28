package nio.io_multiplex_server;

import java.util.concurrent.Executor;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

public class TimeClient {

    /**
     * @param args
     */
    public static void main(String[] args) {

        int port = 8080;
        if (args != null && args.length > 0) {
            try {
                port = Integer.valueOf(args[0]);
            } catch (NumberFormatException e) {
                // 采用默认值
            }
        }
        ExecutorService es = Executors.newFixedThreadPool(10000) ;
        for(int i = 0 ;i < 1000; i++ ) {
            es.execute(new TimeClientHandle("127.0.0.1", port)) ;
        }
        System.out.println("submitted , will shutdown");
        es.shutdown();
    }
}