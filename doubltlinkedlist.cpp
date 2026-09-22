#include<iostream>
using namespace std;
 struct node
{
    int info;
    struct node *next , *prev;
};

struct node *first = NULL , *last=NULL;
struct node *create_node(int x)
{
    struct node *temp;
    temp=(struct node*)malloc(sizeof(struct node));
        temp->info = x;
        temp->next=NULL;
        temp->prev=NULL;
        return(temp);
}
    void insert_first(int x)
    {
        struct node *temp;
        temp = create_node(x);
        if(first == NULL)
        {
            first = last= temp;
        }
        else {
            temp->next=first;
            first->prev=temp;
            first = temp;
            }
    }

    void insert_last(int x)
    {
        struct node *temp;
        temp = create_node(x);

        if(first==NULL)
        {
            first = last = temp;
        }
        else
        {
            last->next = temp;
            temp->prev=last;
            last = temp;
        }
    }

    void insert(int pos, int x)
{
    struct node *temp = create_node(x);
    struct node *y = first;

    int c = 1;

    while(c < pos && y != NULL)
    {
        y = y->next;
        c++;
    }

    if(y == NULL)
    {
        cout << "Invalid position\n";
        return;
    }

    temp->next = y->next;
    temp->prev = y;

    if(y->next != NULL)
        y->next->prev = temp;
    else
        last = temp;

    y->next = temp;
}


    void display(char ch)
    {
        struct node *temp;
        if(ch == 'l' || ch == 'L')
            temp = first;
        else 
            temp = last;
        while(temp!=NULL)
            {
                cout<<temp->info << " -> ";
                if(ch == 'l' || ch == 'L')
                    temp =temp->next;
                else
                    temp = temp->prev;
            }
    }


void delete_first()
{
    if(first == NULL)
    {
        cout << "List is empty\n";
        return;
    }

    struct node *temp;
    temp = first;

    if(first == last)   
    {
        first = last = NULL;
    }
    else
    {
        first = first->next;
        first->prev = NULL;
    }

    delete temp;
}


void delete_last()
{
    if(first == NULL)
    {
        cout << "List is empty\n";
        return;
    }

    struct node *temp;
    temp = last;

    if(first == last) 
    {
        first = last = NULL;
    }
    else
    {
        last = last->prev;
        last->next = NULL;
    }

    delete temp;
}


void delete_after(int pos)
{
    if(first == NULL)
    {
        cout << "List is empty\n";
        return;
    }

    struct node *y;
    y = first;

    int c = 1;
    while(c < pos && y != NULL)
    {
        y = y->next;
        c++;
    }

    if(y == NULL)
    {
        cout << "Invalid position\n";
        return;
    }

    
    if(y->next == NULL)
    {
        cout << "No node exists after position " << pos << "\n";
        return;
    }

    struct node *temp;
    temp = y->next;

    y->next = temp->next;

    if(temp->next != NULL)
    {
        temp->next->prev = y;
    }
    else
    {
        
        last = y;
    }

    delete temp;
}
int main() {
    
    while(1){
        int choice;

       cout << "\n\n1. Insert First\n2. Insert Last\n3. Insert at Position\n4. Display\n5. Delete First\n6. Delete Last\n7. Delete At Position\n8. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch(choice){
            case 1: {
                int x;
                cout << "Enter val: ";  
                cin >> x;
                insert_first(x);
                break;
            }

            case 2: {
                int x;
                cout << "Enter val: ";
                cin >> x;
                insert_last(x);
                break;
            }

             case 3:{
                int x, pos;
                cout << "Enter value: ";
                cin >> x;
                cout << "\nEnter position: ";
                cin >> pos;
                insert(pos ,x);
                break;
             }
            
            case 4:{
                char ch;
                cout << "\nEnter direction left or right: ";
                cin >> ch;

                display(ch);
                break;
            case 5 :
                delete_first();
                cout << "Deleted First!";
                break;

            case 6 :
                delete_last();
                cout << "Deleted last!";
                break;
            
            case 7 :
                int x;
                cout << "Enter pos: ";
                cin >> x;
                delete_after(x);
                break;
            }
            
            case 8:
                exit(0);
                break;
            
            default:
                exit(0);
                break;
        }
    }
    
    return 0;
}