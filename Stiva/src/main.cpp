#include <iostream>

#include <stack>
#include "Stiva.h"

int main(int argc, char const *argv[])
{
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
}
