#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};
typedef struct node Node;

//Function to create nodes dynamically.
Node *createNode()
{
    Node *temp;
    temp = (Node *)malloc(sizeof(Node));
    temp->next = NULL;
    return temp;
}

int main(int argc, char const *argv[])
{
    int n, t, i, value;

    //Input and Output is taken and stored in FILE.
    FILE *inputFile, *outputFile;
    inputFile = fopen(argv[1], "r");
    outputFile = fopen(argv[2], "w+");
    if(inputFile == NULL)
    {
        printf("\nError in opening file in read mode.\n");
        exit(0);
    }
    fscanf(inputFile, "%d", &t);
    fprintf(outputFile, "Even numbers are shifted to left and Odd numbers to the right.\n\n");

    while(t)
    {
        t--;
        fscanf(inputFile, "%d", &n);

        Node *headEven=NULL, *p=NULL, *q=NULL, *headOdd=NULL, *r=NULL, *s=NULL;

        for(i=0; i<n; i++)
        {
            fscanf(inputFile, "%d", &value);

	    //Condition checking for even numbers.
            if(value % 2 == 0)
            {
                if(!headEven)
                {
                    headEven = createNode();
                    headEven->data = value;
                    p = headEven;
                }
                else
                {
                    q = createNode();
                    q->data = value;
                    p->next = q;
                    p = p->next;
                }
            }
	    //Condition checking for odd numbers.
            else
            {
                if(!headOdd)
                {
                    headOdd = createNode();
                    headOdd->data = value;
                    r = headOdd;
                }
                else
                {
                    s = createNode();
                    s->data = value;
                    r->next = s;
                    r = r->next;
                }
            }
        }

        p->next = headOdd;
        p = headEven;

	//Printing output in FILE.
        while(p->next)
        {
            fprintf(outputFile, "%d ", p->data);
            p = p->next;
        }
        fprintf(outputFile, "\n\n");
    }
    fclose(inputFile);
    fclose(outputFile);

    return 0;
}

