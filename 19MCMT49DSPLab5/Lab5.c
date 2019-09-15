#include<stdio.h>
#include<stdlib.h>

#define limit 20

struct custom
{
	char array[20];
	int front;
	int rear;
	int size;
};

int main()
{
	int testcase, countQueues, i, j, inputLength, min, max;
	char input[50];
	char data;

	// FILE operations to retrieve input.

	FILE *file;
	file = fopen("input.txt", "r");
	if(file == NULL)
	{
		printf("\nError in opening file in read mode.\n");
		exit(0);
	}
	fscanf(file, "%d", &testcase);
	fscanf(file, "%d", &countQueues);
	fscanf(file, "%s", input);
        fclose(file);

	struct custom Queue[countQueues];

	for(i=0; i<countQueues; i++)
	{
		Queue[i].front = 0;
		Queue[i].rear  = -1;
		Queue[i].size  = 0;
	}

	inputLength = sizeof(input) / sizeof(input[0]);

	//Insertion of elements in queues.

	for(i=0; i<inputLength; i++)
	{
		if(input[i] == '\0')
			break;
		if(input[i] == 'i')
			i++;
		if(input[i] != 'd')
		{
			min = 0;
			for(j=0; j<countQueues; j++)
			{
				if(Queue[j].size < Queue[min].size)
					min = j;
			}

			//ENQUEUE operation

			if(Queue[min].size >= limit)
			       printf("\nQueue %d is full.\n", min);
			else
			{
				Queue[min].rear = (Queue[min].rear + 1) % limit;
				Queue[min].array[Queue[min].rear] = input[i];
				Queue[min].size++;
				printf("\nElement %c is enqueued in queue %d.\n", input[i], min);
			}
		}
		else
		{
			max = 0;
			for(j=0; j<countQueues; j++)
			{
				if(Queue[j].size > Queue[max].size)
					max = j;
			}

			// DEQUEUE operation

			if(Queue[max].size <= 0)
				printf("\nQueue %d is empty.\n", max);
			else
			{

		        	data = Queue[max].array[Queue[max].front];
				printf("\nElement deleted from queue %d is %c\n", max, data);
				Queue[max].front++;
		         	Queue[max].size--;
			}
		}
	}

	// Printing elements present in all the queues.

	for(i=0; i<countQueues; i++)
	{
		printf("\nQueue %d has elements : ", i);
		for(j=Queue[i].front; j<=Queue[i].rear; j++)
			printf(" %c ", Queue[i].array[j]);
		printf("\n");
	}

	return 0;
}


