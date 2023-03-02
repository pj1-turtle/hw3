#include "llrec.h"

//*********************************************
// Provide your implementation of llpivot below
//*********************************************


void llpivot (Node*& head, Node*& smaller, Node*& larger, int pivot){
	smaller = NULL;
	larger = NULL;

	Node* new_smaller = smaller;
	Node* new_larger = larger;

	if(head == NULL){
		return;
	}
			
	if(head->val > pivot){
		larger = head;
		larger->next = NULL;
		new_larger = larger->next;
		
	}
	else{
		smaller = head;
		smaller->next = NULL;
		new_smaller = smaller->next;
	}

	if(head->next != NULL){
		llpivot(head->next, new_smaller, new_larger, pivot);
	}

	head = NULL;

}