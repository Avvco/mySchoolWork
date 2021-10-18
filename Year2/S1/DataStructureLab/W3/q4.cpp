#include <iostream>
#include <string>

#define SIZE 100

using namespace std;

class Node
{
  public:
	   int data;
	   Node *next;
};

class Queue
{
public:
	Queue()
	{
    front = NULL;
    rear = NULL;
	}
	int enqueue(int data)
	{
    Node* node = new Node();
    node -> data = data;
    node -> next = NULL;
    if (front == NULL) {
      front = node;
      rear = node;
      return 1;
    }else {
      rear -> next = node;
      rear = node;
      return 1;
    }
	}
	int *dequeue()
	{
    if (front == NULL) {
      return NULL;
    }else {
      Node* delNode = front;
      int* value = &(delNode -> data);
      front = front -> next;
      if (front == NULL) {
        rear = NULL;
      }
      return value;
    }
	}
private:
	Node *front;
  Node *rear;
};

int main()
{
	int data, *temp;
	string command;
	Queue *queue = new Queue();
	while(1)
	{
		cin>>command;
		if(command.compare("exit") == 0)
		{
			break;
		}
		else if(command.compare("enqueue") == 0)
		{
			cout<<"Please input a integer data:";
			cin>>data;
			if(queue->enqueue(data) == 1)
			{
				cout<<"Successfully enqueue data "<<data<<" into queue."<<endl;
			}
			else
			{
				cout<<"Failed to enqueue data into queue."<<endl;
			}
		}
		else if(command.compare("dequeue") == 0)
		{
			temp = queue->dequeue();
			if(temp == NULL)
			{
				cout<<"Failed to dequeue a data from queue.\n";
			}
			else
			{
				cout<<"Dequeue data "<<*temp<<" from queue."<<endl;
			}
		}
	}
}
