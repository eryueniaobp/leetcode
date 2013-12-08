// n&(n-1) 会将 n 最低位的 1 置为 0 
int lowestOneBit(int n){
    return n - n&(n-1);
}

int k = lowestOneBit(n) ; 

int pos = -1 ; 
while( k  ) {
    k = k>>1; 
    pos++;
}; 

int pos = -1; 
while( k ){
    if( k &0x1 ){
        pos++ ;
        break; 
    }
    k = k>>1; 
    pos ++ ;
}

