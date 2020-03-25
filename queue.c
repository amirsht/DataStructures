
#include <stdlib.h>
#include <stdio.h>

struct Node
{
	void *value;
	struct Node *next;
}typedef Node;


struct Queue
{
	int size;
	struct Node *head;
	struct Node *tail;
}typedef Queue;


struct Queue* newQueue()
{
  struct Queue *q;
  q = (Queue*)malloc(sizeof(Queue));

  if(q == NULL)
    return q;

  q->size = 0;
  q->head = NULL;
  q->tail = NULL;

  return q;
}

int enqueue(struct Queue *q, void *value)
{
	Node *node = (Node*)malloc(sizeof(Node));

	if (node == NULL)
	{
		return q->size;
	}

	node->value = value;
	node->next = NULL;

	//First item added to queue
	if(q->head == NULL)
	{
		q->head = node;
		q->tail = node;
		q->size = 1;

	}
	else
	{
		q->tail->next = node;
		q->tail = node;
		q->size++;
	}


	return q->size;
}

void* dequeue(struct Queue *q)
{
	if (q->size == 0)
	{
		return NULL;
	}

	Node *node = q->head;
	void *value = q->head->value;
	q->head = q->head->next;
	q->size  --;
	node->next = NULL;
	free(node);

	return value;

}

void freeQueue(struct Queue *q)
{
	while(q->head != NULL)
	{
		Node *temp = q->head;
		q->head = q->head->next;
		if (temp->value != NULL)
			free(temp->value);
		free(temp);
	}

	if (q->tail != NULL)
		free(q->tail);

	free (q);
}

void printQueue(struct Queue *q)
{
	Node *temp = q->head;
	while(temp != NULL)
	{
		printf("%c ",(char)temp->value);
		temp = temp->next;
	}

}
