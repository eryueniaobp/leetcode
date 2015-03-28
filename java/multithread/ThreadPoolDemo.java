package multithread;

import java.util.concurrent.*;
import java.util.concurrent.atomic.AtomicInteger;

/**
 * Created by baipeng on 15-3-28.
 */
public class ThreadPoolDemo {
    public static void main(String []args){
        // default capacity  of LinkedBlockingQueue is very big!
        ExecutorService es = Executors.newFixedThreadPool(2);
//        for(int i = 0 ; i <100  ;i++ ){
//            es.execute(new Worker());
//        }
        System.out.println("end in demo! ");

        int maxPoolSize = 2 ;
        int queueSize = 10 ;
        es =   new ThreadPoolExecutor(0, maxPoolSize, 120L, TimeUnit.SECONDS,
                new ArrayBlockingQueue(queueSize), new ReportRejected());

        AtomicInteger ai = new AtomicInteger(0);
        try {
            for (int i = 0; i < 100; i++) {
                es.execute(new Worker(ai));
            }
        }
        catch(RejectedExecutionException e){
            // If the task cannot be submitted for execution, either because this executor has been shutdown or because its capacity has been reached, the task is handled by the current RejectedExecutionHandler.
            // If you set the RejectedExceptionHandler ,it will not raise the Exception !
            e.printStackTrace();
        }finally {
            es.shutdown();  // it will always run if not shutdown !
        }
        System.out.println("end in demo! 2 ");
    }
    public static class Worker implements  Runnable {
        AtomicInteger ai = null;
        public Worker(AtomicInteger ai){
            this.ai = ai ;
        }
        @Override
        public void run() {
            try {
                Thread.sleep(5000);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
            int cur = ai.addAndGet(1);
            System.out.println(cur + " waked up!");

        }
    }

    public static class ReportRejected implements RejectedExecutionHandler {

        @Override
        public void rejectedExecution(Runnable runnable, ThreadPoolExecutor threadPoolExecutor) {
            System.out.println("rejected !!!" );
            try {
                Thread.sleep(1000);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }


}
