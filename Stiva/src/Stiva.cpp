#include "Stiva.h"

Stiva::Stiva()
{
    top = 1;
}

Stiva::~Stiva()
{

}
bool Stiva::push(int x)
{
    if(top>=(MAX_STACK_SIZE-1))
    {
        std::cout << "Stack overflow! \n";
        return false;
    }
    else
    {
        a[++top] = x;
        std::cout << "Pushed into the stack \n";
        return true;
    }
}

int Stiva::pop()
{
    if(top<0)
    {
        std::cout << "Stack underflow! \n";
        return 0;
    }
    else
    {
        int x = a[top--];
        std::cout << "Poped from the stack \n";
        return x;
    }
}

int Stiva::peek()
{
    if(top<0)
    {
        std::cout << "Stack is empty! \n";
        return 0;
    }
    else
    {
        int topPosition = top - 1;
        int x = a[topPosition];
        std::cout << "Peeked and found top: " << x << std::endl;
        return x;
    }
}

bool Stiva::isEmpty()
{
    if(top <0 )
    {
        std::cout << "Stack is empty \n";
        return true;
    }
    else 
    {
        std::cout << "Stack is not empty \n";
        return false;
    }
}

bool Stiva::contains(int x)
{
    if(!(top < 0))
    {
        for(int i=0; i < top; i++)
        {
            if(a[i] == x)
            {
                std::cout << "Element " << x << " found in stack \n";
                return true;
            }
        }
    }
    std::cout << "Element " << x << " not found in stack \n";
    return false;
}
