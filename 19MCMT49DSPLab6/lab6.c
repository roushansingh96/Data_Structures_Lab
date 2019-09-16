#include<stdio.h>
#include<stdlib.h>

//Structure for Single Linked List
struct sll
{
	int data;
	struct sll *next;
};

//Structure for Double Linked List
struct dll
{
	struct dll *prev;
	int data;
	struct dll *next;
};

//Function to create Single Linked List node
struct sll *createSLLnode()
{
	struct sll *temp;
	temp = (struct sll *)malloc(sizeof(struct sll));
	temp->next = NULL;
	return temp;
}

//Function to create Double Linked List node
struct dll *createDLLnode()
{
	struct dll *temp;
	temp = (struct dll *)malloc(sizeof(struct dll));
	temp->prev = NULL;
	temp->next = NULL;
	return temp;
}


int main(int argc, char const *argv[])
{
	int test, option, n, i, value, num;

	struct sll *headSLL=NULL, *p=NULL, *q=NULL;
	struct dll *headDLL=NULL, *r=NULL, *s=NULL;
	
	//Input from FILE
	
	FILE *inputFile;

	inputFile = fopen(argv[1], "r");

	fscanf(inputFile, "%d", &test);
	fscanf(inputFile, "%d", &option);
	fscanf(inputFile, "%d", &n);

	//Creating Linked List from file input.

        for(i=0; i<n; i++)
	{
		fscanf(inputFile, "%d", &value);
		
		if(option == 1)
		{
			if(!headSLL)
			{
				headSLL = createSLLnode();
				headSLL->data = value;
				p = headSLL;
			}
			else
			{
				q = createSLLnode();
				q->data = value;
				p->next = q;
				p = p->next;
			}

		}
		else if(option == 2)
		{
			if(!headDLL)
			{
				headDLL = createDLLnode();
				headDLL->data = value;
				r = headDLL;
			}
			else
			{
				s = createDLLnode();
				s->data = value;
				r->next = s;
				s->prev = r;
				r = r->next;
			}
		}
				
	}
	fscanf(inputFile, "%d", &num);

	num = num << 2;
	char operations[num];
	int val=0;

	for(i=0; i<num; i++)
		fscanf(inputFile, "%c", &operations[i]);
	fclose(inputFile);
	
	//Code for Searching, Delete, Insert in Linked List
	for(i=0; i<num; i++)
	{
		p = headSLL;
		r = headDLL;

		if(operations[i] == ' ')
			i++;

		//Single Linked List

		if(option == 1) 
		{
			if(operations[i] == 'S' || operations[i] == 's')
		        {
				i++;
			        val = (int)operations[i] - 48; 
			        while(p->data != val && p != NULL)
					p = p->next;

			        if(!p)
				{
	      				printf("Element %d not found in Single Linked List after searching.\n", val);
	               			exit(0);
		        	}
 
            			printf("\nList after searching %d in Single Linked List\n", val);
	        		p = headSLL;
			        while(p)
			        {  
					printf("%d ", p->data);
			         	p = p->next;
			        }
			
		       }
		       else if(operations[i] == 'D' || operations[i] == 'd')
		       {
		       	        i++;
		        	val = (int)operations[i] - 48;
			        while(p->next->data != val && p != NULL)
					p = p->next;
			
			        if(!p)
			        {
					printf("Element %d not found in Single Linked List to delete.\n", val);
				        exit(0);
			        }

			        struct sll *delete;
			        delete = p->next;
		                p->next = delete->next;
		                free(delete);

			        printf("\n%d is deleted successfully from Single Linked List.", val);
			        printf("\nList after deleting %d from Single Linked List.\n", val);

			        p = headSLL;
			        while(p)
			        {
					printf("%d ", p->data);
			         	p = p->next;
			        }
		       }
		       else if(operations[i] == 'I' || operations[i] == 'i')
		       {
		       	        i++;
		        	val = (int)operations[i] - 48;
			        while(p->next)
					p = p->next;
			
				struct sll *newNode;
			        newNode = createSLLnode();
			        newNode->data = val;
			        p->next = newNode;

				printf("\nList after inserting %d at the end in Single Linked List.\n", val);
			        p = headSLL;
			        while(p)
			        {
					printf("%d ", p->data);
				        p = p->next;
			        }
		      }
		}

		// Double Linked List
		else if(option == 2)
		{
			if(operations[i] == 'S' || operations[i] == 's')
		        {
				i++;
			        val = (int)operations[i] - 48;
			        while(r->data != val && r != NULL)
					r = r->next;

			        if(!r)
				{
	      				printf("Element %d not found in Double Linked List after searching.\n", val);
	               			exit(0);
		        	}

            			printf("\nList after searching %d in Double Linked List\n", val);
	        		r = headDLL;
			        while(r)
			        {
					printf("%d ", r->data);
			         	r = r->next;
			        }

		       }
		       else if(operations[i] == 'D' || operations[i] == 'd')
		       {
		       	        i++;
		        	val = (int)operations[i] - 48;
			        while(r->next->data != val && r != NULL)
					r = r->next;

			        if(!r)
			        {
					printf("Element %d not found in Doube Linked List to delete.\n", val);
				        exit(0);
			        }

			        struct dll *delete, *back;
			        delete = r->next;
				back = r->next->next;
		                r->next = delete->next;
				back->prev = r;
		                free(delete);

			        printf("\n%d is deleted successfully from Double Linked List.", val);
			        printf("\nList after deleting %d from Double Linked List.\n", val);

			        r = headDLL;
			        while(r)
			        {
					printf("%d ", r->data);
			         	r = r->next;
			        }
		       }
		       else if(operations[i] == 'I' || operations[i] == 'i')
		       {
		       	        i++;
		        	val = (int)operations[i] - 48;
			        while(r->next)
					r = r->next;

				struct dll *newNode;
			        newNode = createDLLnode();
			        newNode->data = val;
			        r->next = newNode;
				newNode->prev = r;

				printf("\nList after inserting %d at the end in Double Linked List.\n", val);
			        r = headDLL;
			        while(r)
			        {
					printf("%d ", r->data);
				        r = r->next;
			        }
		      }
		}
	}
	
	return 0;
}
	
