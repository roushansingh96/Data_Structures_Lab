#include<stdio.h>
#include<stdlib.h>

/* Custom structure to store color of upper and lower clothing. */
struct node
{
	int color_upper;
	int color_lower;
	struct node *next;
};
typedef struct node Dress_Code;

/* Function to dynamically create a new node. */
Dress_Code *create_node()
{
	Dress_Code *temp;

	temp = (Dress_Code *)malloc(sizeof(Dress_Code));
	if(!temp)
	{
		printf("\nError in accessing memory.\n");
		exit(0);
	}
	temp->next = NULL;

	return temp;
}

/* Driver function to run the program*/
int main(int argc, char const *argv[])
{
	int number_people, input1, input2;
	FILE *input_file, *output_file;

	input_file = fopen(argv[1], "r");
	if(!input_file)
	{ 
		printf("\nError in opening file in read mode.\n");
		exit(0);
	}

	fscanf(input_file, "%d", &number_people);   // Number of people

	int total_colors = number_people >> 1;

	Dress_Code *head=NULL, *p=NULL, *q=NULL;

	/* Below code takes input from FILE and stores in customized linked list. */
	for(int i=0; i < number_people; i++)
	{
		fscanf(input_file, "%d", &input1);
		fscanf(input_file, "%d", &input2);
		if(!head)
		{
			head = create_node();
			head->color_upper = input1;
			head->color_lower = input2;
			p = head;
		//	printf("%d %d ", p->color_upper, p->color_lower);
		}
		else
		{
			q = create_node();
			q->color_upper = input1;
			q->color_lower = input2;
			p->next = q;
			p = p->next;
		//	printf("%d %d ", p->color_upper, p->color_lower);
		}
	}
	p->next = head;
	p = head;

	int count=0;

	/* Below code checks if every person is wearing the proper color sequence. */
	do
	{
		if(p->color_lower == p->next->color_upper)
		{
			p = p->next;
			count++;
		}
	}while(p != head);

	output_file = fopen(argv[2], "w+");

	/* Condition to check if all the person in the party are wearing proper color sequence. */ 
	if(count == number_people)
		fprintf(output_file, "\nColor Sequence in Dress Code is followed by circular linked list.\n");
	else
		fprintf(output_file, "\nColor Sequence in Dress code is not followed by circular linked list.\n");

	return 0;
}

