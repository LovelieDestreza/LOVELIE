#include <iostream>

using namespace std;

    typedef struct Node{
        string songName;
        Node *link;
    }Node;
    
        //node *sample = new Node;
       //sample->songName = "Heaven Knows by Orange and Lemon";
        //cout << sample->songName <<endl;
    
    
//create new mode
    Node *createNode(string data){
        Node *newNode = new Node;
        newNode->songName = data;
        newNode->link = NULL;
        
        return newNode;
    }


    void traverse(Node *head){
        Node *temp = new Node;
        temp = head;

        cout << "my playlist" <<endl;
        while(temp  != NULL){
            cout << temp->songName << "->"<<endl;
            if(temp->link ==NULL){
                cout << "NULL"<<endl;
            }

            temp = temp->link;
        }
    }
       int main(){
        Node *head = createNode("Sanctuary by Joji"); 

        head = inserteAtEnd("sunday Morning by Moroon 5", head);
          traverse(head);

        
          Node *insertAtEnd(string data, Node *head){
            if(head == NULL){
                Node *newNode = createNode(data);
                head = newNode;
                cout << "A new node has been inserted at the end \n" <<endl;
                return head;
            }
            Node *temp = new Node;
            temp head;

            while(temp->link !=NULL){
                temp = temp->link;
            }
            Node *newNode = createNode(data);
            temp->link = newNode;

            cout << " Ä new node has been inserted at the end \n" <<endl;
            return head;

        }

        return 0;
       }