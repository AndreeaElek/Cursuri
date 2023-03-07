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
