#include <iostream>
using namespace std;

struct LinkedListNode{
    int data;
    LinkedListNode* next;
    LinkedListNode(int idata)
    {
        data = idata;
        next = NULL;
    }
};

void createLinkedList(LinkedListNode** head, int data){
    LinkedListNode* tmp = NULL;
    LinkedListNode* newNode = new LinkedListNode(data);
    if(newNode==NULL){
        return;
    }
    //First element
    if (*head == NULL){
        *head = newNode; 
    }
    else{
        tmp = *head;
        while(tmp->next != NULL){
            tmp = tmp->next;
        }
        tmp->next = newNode;
    }
    
    
}
//Recursive reverse - v1
LinkedListNode* reverse_rec_v1(LinkedListNode* head){
    LinkedListNode* secondElem = NULL;
    
    if (head == NULL)
        return head;
    if (head->next == NULL)
        return head;
    
    secondElem = head->next;
    head->next = NULL;
    LinkedListNode* rest = reverse_rec_v1(secondElem);
    std::cout <<"head = "<<head->data <<std::endl;
    std::cout <<"rest = "<<rest->data <<std::endl;
    secondElem->next = head;
    return rest;

}

//Recursive reverse - v2
void reverse_rec_v2(LinkedListNode* head){
    
    LinkedListNode* secondElem = NULL;
    
    if (head == NULL)
        return;
    if (head->next == NULL)
        return;
    
    secondElem = head->next;
    head->next = NULL;
    reverse_rec_v2(secondElem);
//    std::cout <<"head = "<<head->data <<std::endl;
//    std::cout <<"rest = "<<rest->data <<std::endl;
    secondElem->next = head;
    head = secondElem; 

    return;

}


void display(LinkedListNode* head){
    LinkedListNode* tmp = head;
    while(tmp != NULL){
        std::cout <<tmp->data<< " " <<std::endl; 
        tmp = tmp->next;
    }
    
}

int main() {
	LinkedListNode* head = NULL;
	createLinkedList(&head, 10);
	createLinkedList(&head, 20);
	createLinkedList(&head, 30);
	createLinkedList(&head, 40);
	createLinkedList(&head, 50);
	display(head);

    std::cout <<"After reversing "<<std::endl;	
	//head = reverse_rec_v1(head);
	//display(head);
	
	reverse_rec_v2(head);
	display(head);
	
	return 0;
}
