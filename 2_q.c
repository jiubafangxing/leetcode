#include <stdio.h>
#include <stdlib.h>



 typedef struct ListNode {
      int val;
      struct ListNode *next;
 }ListNode;


struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    	struct ListNode *head = NULL, *tail = NULL;

// malloc(sizeof(struct ListNode));
	int carry = 0;
	while( l1 || l2){
		int l1val = l1 ? l1->val:0;
		int l2val = l2 ? l2->val:0;
		int sumval = l1val +l2val + carry;
		if(!head){
			head = malloc(sizeof(struct ListNode ));
			tail = head;
		}else{
			tail->next = malloc(sizeof(struct ListNode ));
			tail = tail -> next;
		}

		if(l2){
		   l2 = l2->next;
		}
		 if(l1){
		   l1 = l1->next;	
		}
		
		carry = sumval / 10;
		tail -> val  = sumval % 10;
		tail -> next = NULL;
	}
	if(carry > 0 ){
		tail -> next =  malloc(sizeof(struct ListNode ));
		tail = tail -> next;
		tail -> val = carry;
		tail -> next = NULL;
	}
	return head;
}
