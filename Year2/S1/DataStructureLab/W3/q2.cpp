#include <iostream>
#include <cstring>

#define SIZE 100

using namespace std;

class Queue
{
public:
    Queue()
    {
      front = -1;
      rear = -1;
      tag = false;
    }
    bool isFull() {
      return rear % SIZE == front && tag;
    }
    bool isEmpty() {
      return front == rear && !tag;
    }
    int enqueue(int data)
    {
      if (isFull() || (rear == SIZE - 1 && front == -1)) {
        return -1;
      } else {
        rear = (rear + 1) % SIZE;
        this -> data[rear] = data;
        if (rear == front) tag = true;
        return 1;
      }
    }
    int *dequeue()
    {
      if (isEmpty()) {
        return NULL;
      }else {
        front = (front + 1) % SIZE;
        int* data = &(this -> data[front]);
        if (front == rear) tag = false;
        return data;
      }
    }
private:
    int data[SIZE];
    int front;
    int rear;
    int tag;
};

int main()
{
    int data, *temp;
    char command[50];
    Queue *queue = new Queue();
    while(1)
    {
        cin>>command;
        if(strcmp(command, "exit") == 0)
        {
            break;
        }
        else if(strcmp(command, "enqueue") == 0)
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
        else if(strcmp(command, "dequeue") == 0)
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
