#include <stdio.h>
#include <stdlib.h>

struct node {
	 int data;
	 struct node *next;
};

typedef struct node * NODE;

NODE getnode() {
	 NODE p;
	 p = (NODE) malloc(sizeof(struct node));
	 if (p != NULL) return p;
	 else {
		  printf("No Memory \n");
		  return NULL;
	 }
}

NODE insert_front(int item, NODE head) {
	 NODE p;
	 p = getnode();
	 p -> data = item;
	 p -> next = head;
	 head = p;
	 printf("Inserted \n");
	 return head;
}

void insert_back(int item, NODE head) {
	 NODE p, q;
	 q = getnode();
	 q -> data = item;
	 q -> next = NULL;
	 p = head;
	 while (p -> next != NULL) p = p -> next;
	 p -> next = q;
	 printf("Inserted \n");
}


void display (NODE head) {
	 NODE p;
	 if (head == NULL) {
		  printf("Empty List \n");
		  return;
	 }
	 p = head;
	 while (p != NULL) {
		  printf("\n%d \n", p -> data);
		  p = p -> next;
	 }
}

int main() {
	 int choice, pos, ele;
	 char ch;
	 NODE head = NULL;
	 clrscr();

	 do {
		  printf("1.Enter from Front \n2.Enter from the End\n3.Display\n4.Exit");


	;
		  printf("\nEnter Choice \n");
		  scanf("\n%d", &choice);

		  switch (choice) {
				case 1: printf("\nEnter Element \n");
						  scanf("%d", &ele);
						  head = insert_front(ele, head);
						  break;

				case 2: printf("\nEnter Element \n");
						  scanf("%d", &ele);
						  insert_back(ele, head);
						  break;

				case 3: display(head);
						  break;

		 case 4: exit(0);
						  break;

				default: printf("Invalid Choice \n");
		  }


	 } while (choice != 5);

	 return 0;
}