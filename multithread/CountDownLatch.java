package multithread;

import java.util.ArrayList;
import java.util.List;
import java.util.concurrent.*;

/**
 * Created by baipeng on 15-3-22.
 */
public class CountDownLatchDemo {

    public static void main(String []args) throws ExecutionException, InterruptedException {
        ExecutorService es = Executors.newFixedThreadPool(10);

        int N = 10 ;
        CountDownLatch latch = new CountDownLatch(N);
        List<Future<String>> f = new ArrayList<Future<String>>();
        for(int i = 0 ; i < N ; i++ ) {
            Counter cnter = new Counter(i,latch ) ;
            f.add(es.submit(cnter));
        }

        latch.await();

        System.out.println("All is ok");

    }

    public static class Counter implements Callable<String> {
        int key = 0 ;
        CountDownLatch latch = null ;
        public Counter(int i ,CountDownLatch latch) {
            key =  i ;
            this.latch = latch ;
        }


        @Override
        public String call() throws Exception {
            try {
                Thread.sleep(1000);
                System.out.println("ok-> " + key) ;
                latch.countDown();
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
            return "====" + key ;
        }
    }
}

