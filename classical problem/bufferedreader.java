package graph;


import java.io.*;
import java.util.Arrays;

/**
 * bufferedreader实现.
 */
public class TBufferedReader {
    private char []cb ;
    private Reader in ;
    private int nChars , nextChar ;
    public TBufferedReader(Reader in, int sz){
        if(sz <=0)
            throw new IllegalArgumentException(("buffer size <=0 "));
        this.in = in ;
        cb = new char[sz];
        nChars = nextChar = 0 ;
    }

    public int read(char cbuf[], int off, int len) throws IOException {
        if(nChars - nextChar >= len){
            System.arraycopy(cb, nextChar, cbuf, off, len);
            nextChar += len ;
            return len;
        }else{
            // < len 需要读取更多.
            int clen = nChars - nextChar;
            if(clen > 0) {
                System.arraycopy(cb, nextChar, cbuf, off, nChars - nextChar);
                off += clen;
                len -= clen;
            }

            while( clen < len ) {
                System.out.println("read it");
                int size = in.read(cb); //  读入更多的数据.
                if(size == -1){
                    return -1;
                }
                if(size < cb.length){
                    // touch the end!
                    int curlen = Math.min(size, len);
                    System.arraycopy(cb, 0, cbuf, off, curlen);

                    clen += curlen ;
                    if(size > curlen ){
                        nextChar = curlen ;
                        nChars = size ;
                    }else{
                        nextChar = 0 ;
                        nChars = 0 ;
                    }

                    break;
                }else{
                    // has more content.
                    int curlen = Math.min(size, len);
                    clen += curlen ;
                    System.arraycopy(cb, 0, cbuf, off, curlen);

                    if(size > len){
                        nextChar = len;
                        nChars = size;
                        break;
                    }else{
                        // need more read!!

                        off += curlen;
                        len -= curlen ;
                    }

                }
            }
            return clen ;

        }
    }
    public static void main(String []argv) throws IOException {

        TBufferedReader reader = new TBufferedReader(new FileReader("./data/test.txt"), 2) ;
        char []buf = new char[100];
        int size = reader.read(buf, 0 , 100);
        System.out.println("size = " + size );
        System.out.println(buf);


//        char []cbuf = new char[100];
//        BufferedReader reader = new BufferedReader(new FileReader("./data/test.txt"));
//        int size = reader.read(cbuf);
//        System.out.println("size = " + size );
//        System.out.println(String.valueOf(cbuf));


    }
}
