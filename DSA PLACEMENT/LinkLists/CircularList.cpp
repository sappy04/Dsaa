#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    // Constructor
    Node(int d)
    {
        this->data = d;
        this->next = NULL;
    }

    // Destructor
    ~Node()
    {
        if (this->next != NULL)
        {
            delete next;
        }
        cout << "Memory freed for node with data: " << this->data << endl;
    }
};

// Insert a node after a specific element (or into an empty list)
void insertNode(Node *&tail, int element, int d)
{
    
    if (tail == NULL)//empty list
    {
        Node *temp = new Node(d); //naya node banao aur usko hi tail mar ko in next step
        tail = temp;//tail mark kardo
        temp->next = temp; // Circular link banado
    }
    else
    {
        // Traverse the list to find the given element
        Node *curr = tail;//alloting tail as the current element
        do
        {
            if (curr->data == element)//current ka value kya wohi hai jisse mai khoj raha hoon?
            {//agar haa then
                Node *temp = new Node(d);//naya node create kiya
                temp->next = curr->next;//circular link
                curr->next = temp;//single element jo hai uska pointer naya elemt ko point kar raha hai

                // Update tail if needed
                if (curr == tail)//current jo initialise kiya tha wo tail se match ho gaya matlab searched item nahi mil paya
                {
                    tail = temp;//list k last node pe(tail pe) value insert karte hai aur usse tail mark kar dete hai kyu desired value milla nahi
                }
                return;//bahar nikla jao
            }
            curr = curr->next;//searching for the element by incrementing current jab tak mujhe mtch nahi milta
        } while (curr != tail);//jab current(tail),tail k equal nahi ho jata... inshort,pura loop traverse karenge jab tak tail se tail tak nahi pohuch jate 
    }
}

// Print the circular linked list
void print(Node *tail)
{
    if (tail == NULL)
    {
        cout << "List is empty." << endl;
        return;
    }

    Node *temp = tail->next;//last to first wala connection store kar liya hai
    do
    {
        cout << temp->data << " ";//last wale connection k base pe values print kar raha
        temp = temp->next;//temp ko increment kar rahe hai
    } while (temp != tail->next);//jab tak tail se ghum kar tail tak nahi aajata
    cout << endl;
}

// Delete a node with a specific value
void deleteNode(Node *&tail, int value)
{
    if (tail == NULL)
    {
        cout << "List is empty." << endl;
        return;
    }

    Node *prev = tail;//assume tail to be the first elememt and declare it prev
    Node *curr = prev->next;

    do
    {
        if (curr->data == value)//agar value match kar gaya
        {
            prev->next = curr->next;//connection establishment

            //jab list mai ek hi node hai aur hum usse hi delete karne chale hai
            if (prev == tail && curr->next == curr)
            {
                tail = NULL;//ek hi tha gayab kar diya usko bhi so tail ko null mark kar do
            }
            //jab list >=2 items hai prev and current different honge phir 
            else if (curr == tail)//current ko delete kar dya hai to abhi tail ko prev se update karo
            {
                tail = prev;//tail ko ek hi element hai jo hai prev to uspe update kar diya 
            }

            curr->next = NULL;//chosen node ka link totally todh diya gaya hai 
            delete curr;//abhi delete kar do 
            return;
        }
        prev = curr;//abhi to bas ek hi element hai same kar do donno ko
        curr = curr->next;//circular link banane k liye
    } while (curr != tail->next);

    cout << "Node with value " << value << " not found." << endl;
}

// Check if the list is circular
bool isCircularList(Node *tail)
{
    if (tail == NULL)//agar list empty hai to circular hi mante hai
        return true;

    Node *temp = tail->next;//agar mai sirf tail ka use karunga to track nahi rakh paunga is liye tail k next se kar raha hoon mai start
    while (temp != NULL && temp != tail)//temp!=null ye decide karta hai ki chain circular hai ki nahi(circular nahi hua to last mai null to rahega hi na) and temp!=tail kehta hai ki jab tak mai end tak na pohuch jau ghute raho(circular)
    {
        temp = temp->next;//nodes pe nodes ghum rahe hai by incremeneting
    }

    if (temp == tail)//jis element se start kiya(tail hi hai) aur usi element mai agaye to by temp=temp->next,ek peeche element se same ko main se access kar rahe  😂
    {
        return true;
    } 
    else
    {
        return false;
    }
}
int main()
{
    Node *tail = NULL;

    insertNode(tail, 5, 3); // Inserting into empty list
    print(tail);

    insertNode(tail, 3, 5); // Inserting after 3
    print(tail);

    insertNode(tail, 5, 7); // Inserting after 5
    print(tail);

    insertNode(tail, 7, 9); // Inserting after 7
    print(tail);

    deleteNode(tail, 5); // Deleting node with value 5
    print(tail);

    // Checking if the list is circular
    if (isCircularList(tail))
    {
        cout << "The list is circular." << endl;
    }
    else
    {
        cout << "The list is not circular." << endl;
    }
    return 0;
}
