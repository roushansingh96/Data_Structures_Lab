#include<stdio.h>
#include<stdlib.h>

//Creating node for single linked list.
struct node {
	int data;
	struct node *next;
};
typedef struct node Node;

//Function to create a single linked list dynamically.
Node *createNode() {
	Node *temp;
	temp = (Node *)malloc(sizeof(Node));

	if(!temp) {
		printf("\nError in memory allocation.\n");
		exit(0);
	}
	temp->next = NULL;
	return temp;
}

int main(int argc, char const *argv[]) {
	int T, N, i, pos_link, value;

	//Input and Output is taken and stored from FILE.
	FILE *inputFile, *outputFile;

	inputFile = fopen(argv[1], "r");
	if(!inputFile) {
		printf("\nError in opening file in read mode.\n");
		exit(0);
	}
	outputFile = fopen(argv[2], "w+");

	fscanf(inputFile, "%d", &T);

	while(T--) {
		fscanf(inputFile, "%d", &N);
		fscanf(inputFile, "%d", &pos_link);

		Node *head=NULL, *p=NULL, *q=NULL;

		//Storing values in linked list.
		for(i=0; i<N; i++) {
			fscanf(inputFile, "%d", &value);

			if(!head) {
				head = createNode();
				head->data = value;
				p = head;
			}
			else {
				q = createNode();
				q->data = value;
				p->next = q;
				p = p->next;
			}
		}

		Node *temp = head;

		//Pointing last node to the given position in the input FILE.
		if(pos_link >= 0) {
			while(pos_link--)
				temp = temp->next;
			p->next = temp;
		}
		else {
			p->next = NULL;
		}

		temp = head;

		int flag=0, count=0;

		//Loop to check if linked list is circular or not.
		while(temp) {
			if(p->next == temp) {
				fprintf(outputFile, "\nLinked list is circular starting at node %d.\n", count);
				flag = 1;
				break;
			}
			else {
				temp = temp->next;
				count++;
			}
		}

		if(flag == 0)
			fprintf(outputFile, "\nLinked List is not circular.\n");
	}
	fclose(inputFile);
	fclose(outputFile);

	return 0;
}
