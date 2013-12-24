
#include <iostream>
#include <stack> 
#include <cstdlib>
#include <string> 
#include <vector>
#include <queue> 
#include <sstream> 
using namespace std;

#define MAX_LEN 100
class Heap {
public:
    int data[MAX_LEN];
    int length_; 
    Heap(int data[],int len ){
        if(len > MAX_LEN ) return ;
        for(int i = 0 ; i< len ;i ++ ){
            this->data[i] = data[i] ; 
        }
        length_ = len ; 
    }
    //最小堆
    void make_heap() {
        int i = length_/2;  
        while( i >= 0 ){
            sift_down( i-- );
        }
    }

    void push_heap(int value){
        if(length_ >= MAX_LEN ) return ;  // push fail 
        data[length_++] = value; 
        int i = length_ - 1 ; 
        while ( i > 0 ) {
            int p = (i-1)/2 ; 
            if( data[p] > data[i] ) {
                int t = i ; 
                if( i & 0x1 ) {
                    if(data[i+1] < data[i] ) {
                        t = i+1 ;
                    }
                }else{
                    if(data[i-1] < data[i] ) {
                        t = i-1; 
                    }
                }
                swap(data[p],data[t] ) ; 
                i = p ;
            }else{
                break;
            }
        }
    }
    int top(){
        return data[0] ; 
    }
    int pop_heap(){
        swap(data[0],data[length_ - 1 ] ) ; 
        length_ -- ; 
        sift_down(0); 
        return data[length_] ;
    }
private: 
    int parent(int  pos ) {
        return (pos-1)/2 ;
    }
    int sift_down(int pos ) {
        int t = pos ; 
        while ( t < length_) {
            int left = 2*t +1 ; 
            int right = 2*t +2  ;
            if( right >= length_ ) {
                right = left ; 
            }
            if( left >= length_ ) {
                break;
            }
            if(data[t] <= data[left] && data[t] <= data[right]) {
                break;
            }
            if(data[left]<= data[right] ) {
                //choose left
                swap(data[t] ,data[left] ) ;
                t = left ; 
            }else{
                swap(data[t],data[right]); 
                t = right ;                
            }
        }
    }
};
int main() 
{
    int data[MAX_LEN] ; 
    for(int i = 0 ; i < MAX_LEN; i++ ){
        data[i] = i ; 
    }
    // shuffle 
    for(int i = MAX_LEN-1;i > 0 ;i-- ){
        int k = rand() % (i+1)  ; 
        swap(data[i],data[k]) ;
         
    }
    for(int i = 0 ; i < MAX_LEN; i++ ){
        cout<<data[i]<<" "; 
    }
    cout<<endl;
    Heap heap(data,MAX_LEN) ;
    heap.make_heap();
    cout<<"top = " << heap.top() << endl ; 
    heap.pop_heap()  ; 
    cout<<"After pop , top = " << heap.top() <<endl; 


    heap.push_heap(2) ; 
    cout<<"After push ,top  =" << heap.top() <<endl; 
    system("Pause");
    return 0 ;
}

