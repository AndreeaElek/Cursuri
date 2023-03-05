#ifndef STIVA_H
#define STIVA_H

#pragma once

#include <iostream>

#define MAX_STACK_SIZE 10

class Stiva
{
public:
    int a[MAX_STACK_SIZE];
    Stiva();
    ~Stiva();

    bool push(int x);
    int pop(); 
    int peek(); 
    bool isEmpty();
    bool contains(int x);

private:
    int top;

};

#endif