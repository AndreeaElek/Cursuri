#include <iostream>

#include <stack>
#include "Stiva.h"
#include <stack>

class Node 
{
    public:
        int data;
        Node* next;


};

void printLinkedList(Node* ref)
{
    while(ref != NULL)
    {
        std::cout << "Data is: " << ref->data << std::endl;
        ref = ref->next;
    }
}

bool searchLinkedList(Node* ref, int x)
{
    while(ref != NULL)
    {
        if(ref->data == x)
        {
            std::cout  << x << " found in list " << std::endl;
            return true;
        }
        ref = ref->next;
    }
        std::cout << x << " not found in list \n";
    return false;
}


//inserare la capul listei
void push(Node*& referinta, int data)
{
    std::cout << "Inseram un nod cu valoarea " << data << " la inceputul listei" << std::endl;
    Node * new_node = new Node();
    new_node->data = data; //(*new_node).data

    new_node->next = referinta; 
    
    referinta = new_node;
}


    //inserare la mijlocul listei
//inserare dupa o anumita pozitie
void insertAfterPos(Node* ref, int element, int pos)
{
    std::cout << "Inseram un nod cu valoarea " << element << " dupa elementul de pe pozitia " <<  pos << std::endl;
    Node * new_node = new Node();
    new_node->data = element;
    Node * temp = new Node();

    int i = 1;
    while(ref != NULL)
    {
        if(i == pos)
        {
            temp = ref->next;
            ref->next = new_node;
            new_node->next = temp;
        }
        i++;
        ref = ref->next;
    }
}

//inserare dupa un anumit element
void insertAfterElem(Node* ref, int new_node_data, int key)
{
    std::cout << "Inseram un nod cu valoarea " << new_node_data << " dupa elementul " <<  key << std::endl;
    Node * new_node = new Node();
    Node * temp = new Node();
    new_node->data = new_node_data;

    while( ref != NULL)
    {
        if(ref->data == key)
        {
            temp = ref->next;
            ref->next = new_node;
            new_node->next = temp;
        }
        ref = ref->next;
    }
}


void append_V2(Node* ref, int new_node_data)
{
    std::cout << "Inseram un nod cu valoarea " << new_node_data << " la sfarsitul listei" << std::endl;
    Node * new_node = new Node();
    Node * temp = new Node();
    new_node->data = new_node_data;

    while( (ref->next) != NULL)
    {
        ref = ref->next;        
    }
    ref->next = new_node;
    new_node->next = NULL;
}


//inserare la coada listei
void append(Node*& head, int data)
{
    std::cout << "Inseram un nod cu valoarea " << data << " la sfarsitul listei" << std::endl;
    Node * new_node = new Node();
    new_node->data = data;

    Node* lastNode = head;

    new_node->next = NULL;


    if(head == NULL)
    {
        head = new_node;
        return;
    }

//traversam pana la sfarsitul listei
    while(lastNode->next != NULL)
    {
        lastNode = lastNode->next;
    }
    //schimbam nextul ulimului nod sa arate spre noul nod
    lastNode->next = new_node;
}

void deleteNode(Node*& head_ref, int key)
{
    std::cout<< "Cautam sa stergem nudul cu key-ul " << key << std::endl;
    Node* temp = head_ref;
    Node* prev = NULL;

//Daca nodul are cheia ce trebuie stearsa
    if(temp != NULL && temp->data == key)
    {
        head_ref= temp->next; //schimbam head-ul
        delete temp; // stergem head-ul vechi
        return;
    }

    else
    {
        while(temp != NULL && temp->data != key)
        {
            prev = temp; 
            temp = temp->next;
        }

        //daca cheia nu este gasita
        if(temp == NULL)
        {
            return;
        }

        //rupem/scoatem nodul din lista
        prev -> next = temp->next;
        delete temp; 
    }
}



int main(int argc, char const *argv[])
{
    Node* cap = NULL;
    Node* doi = NULL;
    Node* trei = NULL;

    //alocam trei noduri in memoria heap
    cap = new Node();
    doi = new Node();
    trei = new Node();

    cap->data = 1;
    cap->next = doi;

    doi->data = 2;
    doi->next = trei;

    trei->data = 3;
    trei->next = NULL;

    printLinkedList(cap);

    Node* patru = NULL;
    patru = new Node();

    patru->data = 4;
    patru->next = NULL;

    trei->next = patru;

    printLinkedList(cap);

    searchLinkedList(cap, 2);
    searchLinkedList(cap, 5);

    push(cap,5);
    printLinkedList(cap); 

    append(cap, 10);
    printLinkedList(cap);

    deleteNode(cap, 10);
    printLinkedList(cap);

    append_V2(cap, 6);
    printLinkedList(cap);

    insertAfterElem(cap, 7, 3);
    printLinkedList(cap);
    
    insertAfterPos(cap, 8, 2);
    printLinkedList(cap);


    //Tema: Inserare la mijlocul listei (cautati o anumita cheie si inserati dupa aceasta)



   //Tema: O functie ce sa caute intro-o lista inlantuita un element


    /*
    Stiva s;
    //s.push(10);
    //s.push(11);
    for(int i=0; i<=11; i++)
    {
        s.push(i);
    }
    s.peek();
    s.isEmpty();
    s.contains(6);
    s.contains(12);
    for(int i=11; i>=-1; i--)
    {
        s.pop();
    } 
    s.isEmpty();

    std::stack<int> p;
    */
}
