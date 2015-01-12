#include <iostream>
#include <stack> 
#include <cstdlib>
#include <string> 
#include <vector>
#include<algorithm>
#include <ctime>
using namespace std;
struct ListNode {
    int val ; 
    ListNode *next; 
    ListNode(int x) : val(x),next(NULL){

    }
}; 
// 返回 最终排序好的某个位置 ,这个很关键. 
ListNode *partition(ListNode *head, ListNode *tail ) 
{
	
	if ( head == tail || head->next == tail) return head ; 

    int pivot = head->val ; 
    ListNode *node = head , *ltail = NULL , *rtail = NULL ; 


    while( node !=tail && node->val <= pivot ) {
            ltail = node ; 
            node = node->next ;
    }

    while(node!= tail ) {
        while( node!=tail && node->val > pivot ) {
            rtail = node; 
            node = node->next ;
        }
        if(node !=tail ) {
			ltail = ltail->next ; 
		
            swap(ltail->val  , node->val) ; // it's tricky .. not good .
            rtail= node ; 
            node= node->next ; 
        }
    }
	swap(ltail->val, head->val) ;
    return ltail  ; 
}
// [head ,tail) 
ListNode* qsort(ListNode *head , ListNode *tail) 
{
   
	if( head == NULL || head == tail  ) return  NULL;
    ListNode *pos = partition(head,tail) ;  
    
    
    qsort(head, pos) ;
    qsort(pos->next, tail); 
    
    return head ; 
}

//41 467 334 500 169  
//recursively
#define MAX_LEN 1000
int main()
{
//	srand(time(NULL));
	
	int mirror[MAX_LEN]  ; 
	
    ListNode *head = new ListNode(INT_MAX); 
    ListNode *node = head; 
	for(int i = 0 ; i< MAX_LEN ; i++ )
	{
        node->next = new ListNode(INT_MAX); 
        node->next->val = rand() %1000 ; 
        
        node = node->next; 
        //cout<<node->val<<" " ; 
        mirror[i] = node->val  ; 
	}
    head = head->next; 
	cout<<endl;
	
	/*
	cout<<"Mirror Sorted :\n\t" ; 
	sort(mirror, mirror+MAX_LEN) ; 
	for(int i = 0 ; i< MAX_LEN ; i++ )
	{
		cout<<mirror[i]<<" " ; 
	}
	cout<<endl; 
	*/
	
	
	
    head = qsort(head, NULL ) ;
    int pre = INT_MIN , cur = INT_MAX ;
    int count = 0 ;
	while(head!=NULL){
		//cout<<head->val<<" ";
        if(  pre > head->val ) {
            cout<<"Error"<<endl ;
            break; 
        }
        pre = head->val ; 
        head = head->next; 
        count++ ; 
    }
	cout<<endl<<count<<endl;
	system("pause");
}
// An expected solution .
class Solution {
public:
    ListNode *sortList(ListNode *head) {
        if(!head||!head->next)
            return head;
        return mergeSort(head);
    }
    ListNode * mergeSort(ListNode *head){
        if(!head||!head->next)   //just one element
            return head;
        ListNode *p=head, *q=head, *pre=NULL;
        while(q&&q->next!=NULL){
            q=q->next->next;
            pre=p;
            p=p->next;  //divide into two parts
        }
        pre->next=NULL;
        ListNode *lhalf=mergeSort(head);
        ListNode *rhalf=mergeSort(p);  //recursive
        return merge(lhalf, rhalf);   //merge
    }
    ListNode * merge(ListNode *lh, ListNode *rh){
        ListNode *temp=new ListNode(0);
        ListNode *p=temp;
        while(lh&&rh){
            if(lh->val<=rh->val){
                p->next=lh;
                lh=lh->next;
            }
            else{
                p->next=rh;
                rh=rh->next;
            }
            p=p->next;
        }
        if(!lh)
            p->next=rh;
        else
            p->next=lh;
        p=temp->next;
        temp->next=NULL;
        delete temp;
        return p;
    }
};

