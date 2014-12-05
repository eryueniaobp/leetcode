/*ref:  http://www.geeksforgeeks.org/forums/topic/facebook-interview-3/  
* For the sort question:
* Use the flip operation to define a swap function.  
* http://en.wikipedia.org/wiki/Pancake_sorting  
* best is O(n) . O(nlogn)will by good in interview. 
*/

void swap(int *arr, size_t size, size_t i, size_t j)
{
    if (i == j) return;
    else if (i > j)
    { int k = i; i = j; j = k;}
    
    if (i != 0) return swap(arr+i, 0, j-i);

//6 flip operations swap 2 elements 
// The blocks After i and j are represented by B and C respectively

// iBjC    
   flip(a,0);
// C'jB'i    
   flip(a,n-j-1);
// C'iBj  
   flip(a,n-j);
// C'ijB'   
   flip(a,n-j+1);
// C'ijB  
   flip(a,n-j);
// C'iB'j  
   flip(a,0);
// jBiC
}

Now use this swap with just any algorithm you like.

