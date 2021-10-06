
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

class Stack
{
public:
    Stack()
    {
      data = NULL;
    }
    int push(int d)
    {
      Node* node = new Node();
      node -> data = d;
      node -> next = data;
      data = node;
      return 1;
    }

    int *pop()
    {
      if (data == NULL) {
        return NULL;
      }else {
        Node* delNode = data;
        int* value = &delNode -> data;
        data = delNode -> next;
        return value;
      }
    }
private:
    Node *data;
};

int main()
{
    int data, *temp;
    string command;
    Stack *stack = new Stack();
    while(1)
    {
        cin>>command;
        if(command.compare("exit") == 0)
        {
            break;
        }
        else if(command.compare("push") == 0)
        {
            cout<<"Please input a integer data:";
            cin>>data;
            if(stack->push(data) == 1)
            {
                cout<<"Successfully push data %d into stack.\n";
            }
            else
            {
                cout<<"Failed to push data into stack.\n";
            }
        }
        else if(command.compare("pop") == 0)
        {
            temp = stack->pop();
            if(temp == NULL)
            {
                cout<<"Failed to pop a data from stack.\n";
            }
            else
            {
                cout<<"Pop data %d from stack.\n"<<*temp;
            }
        }
    }
}
