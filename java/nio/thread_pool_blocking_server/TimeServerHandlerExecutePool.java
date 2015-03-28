package nio.thread_pool_blocking_server;

import java.util.concurrent.ArrayBlockingQueue;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.ThreadPoolExecutor;
import java.util.concurrent.TimeUnit;

public class TimeServerHandlerExecutePool {

    private ExecutorService executor;

    public TimeServerHandlerExecutePool(int maxPoolSize, int queueSize) {
        int pnum = Runtime.getRuntime().availableProcessors() ;
        int corePoolSize = maxPoolSize >  pnum ? pnum : 0 ;
        executor = new ThreadPoolExecutor(corePoolSize,
                maxPoolSize, 120L, TimeUnit.SECONDS,
                new ArrayBlockingQueue(queueSize));
    }
    public void execute(java.lang.Runnable task) {
        executor.execute(task);
    }
}
