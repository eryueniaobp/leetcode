package multithread;

import java.util.Queue;
import java.util.UUID;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.LinkedBlockingQueue;
import java.util.concurrent.locks.Condition;
import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;

/**
 * Created by baipeng on 15-3-31.
 * Solution 1: use LinkedBlockingQueue directly!
 * Solution 2: use Object#wait and #notify,notifyAll
 * Solution 3: use the Lock and Condition .
 */
public class ProducerAndConsumer {
    public static void main(String []args){
        IBoundedBuffer<Item> bb = new LockBoundedBuffer<Item>(10);
//        IBoundedBuffer<Item> bb = new BoundedBuffer<Item>(10);
//        IBoundedBuffer<Item> bb = new ProxyBoundedBuffer<Item>(10);
        int P = 10 , C = 10 ;
        ExecutorService pes = Executors.newFixedThreadPool(P+C) ;
        for(int i = 0 ;i < P ; i++){
            pes.execute(new Producer(bb)) ;
        }
        for(int i = 0 ; i < C ; i++){
            pes.execute(new Consumer(bb));
        }
        pes.shutdown();
    }

    public static interface IBoundedBuffer<V> {
        public void offer(V v) throws InterruptedException;
        public V poll () throws  InterruptedException ;
    }
    public static abstract class BaseBoundedBuffer<V> {
        private final V [] buffer ;
        private int tail = 0 ;
        private int head = 0 ;
        private int count = 0 ;
        public BaseBoundedBuffer(int capacity){
            buffer = (V[])new Object[capacity] ;
        }
        protected synchronized final void doPut(V v) {
            buffer[tail] = v;
            if(++tail == buffer.length ) {
                tail = 0 ;
            }
            count++ ;
        }
        protected synchronized final V doTake() {
            V v = buffer[head] ;
            buffer[head] = null;
            if(++head == buffer.length )
                head = 0 ;
            count -- ;
            return v;
        }
        public synchronized final boolean isFull() {
            return count == buffer.length ;
        }
        public synchronized final boolean isEmpty(){
            return count == 0 ;
        }

    }

    // 采用Condition，signal时，锁竞争的情况变少，吞吐量变高
    public static class LockBoundedBuffer<V> extends BaseBoundedBuffer<V> implements IBoundedBuffer<V> {
        Lock lock = new ReentrantLock();
        Condition notFull = lock.newCondition();
        Condition notEmpty = lock.newCondition() ;

        public LockBoundedBuffer(int capacity) {
            super(capacity);
        }
        @Override
        public synchronized void offer(V v) throws InterruptedException {
            lock.lock();
            try {
                while (isFull()) {
                    notFull.wait();
                }
                doPut(v);
                notEmpty.signal();
            }finally {
                // unlock 必须放在finally模块中,否则遇到异常
                // 中途退出，就麻烦了
                lock.unlock();
            }
        }

        @Override
        public synchronized V poll() throws InterruptedException {
            lock.lock();
            try {
                while (isEmpty()) {
                    notEmpty.wait();
                }
                V v = doTake();
                notFull.signal();
                return v;
            }finally {
                lock.unlock();
            }
        }
    }
    public static class ProxyBoundedBuffer<V> implements IBoundedBuffer<V> {
        final Queue<V> queue ;
        public ProxyBoundedBuffer(int capacity) {
            queue = new LinkedBlockingQueue<V>(capacity);
        }
        @Override
        public void offer(V v) throws InterruptedException {
            queue.offer(v) ;
        }

        @Override
        public V poll() throws InterruptedException {
            return queue.poll();
        }
    }
    // KEY DATA-STRUCTURE
    public static class BoundedBuffer<V>  extends BaseBoundedBuffer<V> implements IBoundedBuffer<V> {

        public BoundedBuffer(int capacity){
            super(capacity) ;
        }


        public synchronized void offer( V v )  throws InterruptedException {
            while(isFull()){
                wait();
            }
            System.out.println("putting " + v );
            doPut(v);
            notifyAll();
        }
        public synchronized V poll() throws  InterruptedException{
            while(isEmpty()) {
                wait();
            }
            V v = doTake();
            System.out.println("taking " + v);
            notifyAll();
            return v ;
        }
    }

    // Clean Producer and Consumer !
    public static class Producer implements Runnable{
        IBoundedBuffer<Item> queue = null;
        public Producer(IBoundedBuffer<Item> queue){
            this.queue = queue ;
        }
        @Override
        public void run() {
            while (true){
                try {
                    Item item = new Item(UUID.randomUUID().toString()) ;
                    queue.offer(item);
                }catch (InterruptedException e){
                    e.printStackTrace();
                }
            }
        }
    }
    public static class Consumer implements Runnable{
        IBoundedBuffer<Item> queue = null;
        public Consumer(IBoundedBuffer<Item> queue){
            this.queue = queue;
        }

        @Override
        public void run() {
            while(true){
                try {
                    Item item = queue.poll();
                    // use this item
                }catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }

        }
    }
    public static class Item {
        public int id ;
        public String tag;
        public String uuid ;
        public Item(String uuid){
            this.uuid = uuid ;
        }
        public String toString(){
            return uuid+"";
        }
    }
}
