#include <iostream> 

using namespace std;

typedef struct Node{
    string songName;
    Node *link;
}Node;
Node *createNode(string data){
    Node *newNode = new Node;
    newNode->songName = data; 
    newNode->link = NULL;
    return newNode;
}
void traverse(Node *head){
    Node *temp = new Node;
    temp = head;

    cout << "My Playlist" <<endl;
    while(temp != NULL){
        cout << temp->songName<< "->"<<endl;
        if(temp->link == NULL){
            cout << "NULL"<<endl;
        }

        temp = temp->link;
    }
}

// Insert at the end
Node *insertAtEnd(string data, Node *head) {
    if (head == NULL) { // if the linked list is empty
        Node *newNode = createNode(data); // create node
        head = newNode; // assign new node as head
        cout << "A new node has been inserted at the end\n" << endl; // print out message
        return head;
    }
    Node *temp = new Node; // create a temporary node
    temp = head; // assign temporary node as head

    while (temp->link != NULL) { // traverse until the end is found, i.e., link == NULL
        temp = temp->link;
    }

    Node *newNode = createNode(data); // create new node
    temp->link = newNode; // link the new node to the last element

    cout << "A new node has been inserted at the end\n" << endl;
    return head;
}
Node *insertAtTheBeginning(string data, Node *head){
    Node *newNode = createNode(data);
    newNode->link = head;

    head = newNode;

    cout << "A new node has been inserted at the beginning \n" <<endl;

    return head;
}
//Insert at the after a given node
string insertAfter(string after, string data, Node *head){
    Node *temp = new Node; // create temporary node
    temp = head; // assign temporary node as head

    while(temp->songName.compare(after) != 0){ // search for the node
        if(temp == NULL){ // if no such node exist, break and return error message
            return "No such song exist, please try again later.";
        }
        temp = temp->link;
    }

    Node *newNode = createNode(data); // create new node
    newNode->link = temp->link; // assign the link of the new node to the node after the given node
    temp->link = newNode; // link new node to the given node

    return "An new node has been added after " + after + "\n"; // return confirmation message
}

string deleteAtEnd(Node *head){
    if(head == NULL){
        return "The linked list is empty \n";
    }
    
    if (head->link == NULL){
        delete head;
        return "The head has been deleted \n";
    }
    
    Node *temp = new Node;
    temp = head;
    
    while(temp->link != NULL){
        temp = temp->link;
    }
    
    temp->link = NULL;
    
    return "A node has been deleted at the end \n";
}

Node *deleteFromBeginning(Node *head){
    if(head == NULL){
        cout << "The linked list is empty \n" << endl;
        return NULL;
    }
    
    if(head->link == NULL){
        delete head;
    }
    
    head = head->link;
    
    cout << "A node has been delete from the beginning \n" << endl;
    
    return head;
}

Node *deleteFromGivenNode(string givenNode, Node *head){
    if(head == NULL){
        cout << "The linked list is empty. \n" <<endl;
    }
    
    if(head->songName.compare(givenNode) == 0){
        head = deleteFromBeginning(head);
        cout << "The Node" + givenNode + "has been deleted. \n" << endl;
        return head;
    }
    
    Node *temp = new Node;
    Node *next = new Node;
    temp = head;
    next = temp->link;


    
    while(next->songName.compare(givenNode) != 0){
        if(temp == NULL){
            cout << "No such node exist. \n" <<endl;
            return head;
        }
        next = next->link;
        temp = temp->link;
    }
    
    temp->link = next->link;
    cout << "The Node " + givenNode + " has been deleted. \n" << endl;
    return head;
}

 int main(){

    Node *head = createNode ("Sanctuary by Joji");
    head = insertAtEnd("Sunday Morning by Maroon 5", head);
    head = insertAtEnd("Very Nice by Seventeen", head);
    head = insertAtEnd("Water by Tyla", head);
    head = insertAtEnd("Birds of a Feather by Billie Eilish", head);
    head = insertAtTheBeginning("Nonsense by Sabrina Carpenter", head);
    head = insertAtTheBeginning("Snooze by SZA", head);
    head = insertAtTheBeginning("Vampire by Olivia Rodrigo", head);
    head = insertAtTheBeginning("Light a Flame by Seventeen", head);

    traverse(head);

    string result = insertAfter("Nonsense by Sabrina Carpenter", "Tadhana", head);
    cout << result; 
    string result1 = insertAfter("Snooze by SZA", "Palagi", head);
    cout << result1; 
    string result2 = insertAfter("Vampire by Olivia Rodrigo", "Paraluman", head);
    cout << result2;
    
    traverse(head);

    string END = deleteAtEnd(head);
    cout << END << endl;
    head  = deleteFromBeginning(head);
    head = deleteFromGivenNode("Birds of a Feather by Billie Eilish", head);
    traverse(head);

    
    
      return 0;
}
