package multithread;

import java.util.ArrayList;
import java.util.List;
import java.util.concurrent.*;

/**
 * Created by baipeng on 15-3-22.
 * Future 与  Callable 配合
 */
public class FutureDemo {
    public static void main(String []args) throws ExecutionException, InterruptedException {
        ExecutorService es = Executors.newFixedThreadPool(10);
        List<Future<String>> f = new ArrayList<Future<String>>();
        for(int i = 0 ; i < 10 ; i++ ) {
            Counter cnter = new Counter(i) ;
            f.add(es.submit(cnter));
        }
        for(int i = 0 ; i < 10 ; i++ ) {
            System.out.println(f.get(i).get());
        }
    }

    public static class Counter implements Callable<String>{
        int key = 0 ;
        public Counter(int i ) {
            key =  i ;
        }


        @Override
        public String call() throws Exception {
            try {
                Thread.sleep(1000);
                System.out.println("ok-> " + key) ;
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
            return "====" + key ;
        }
    }
}

