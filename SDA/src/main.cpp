#include <iostream>

bool findElement(int myArray[], int arrSize, int number)
{
    for(int i=0; i<arrSize; i++)
    {
        if(myArray[i]==number)
        {
            return true;
        }
    }
    return false;
}

int greatestElement(int myArray[], int arrSize)
{
    int greatestElem = myArray[0];
    for(int i=1; i<arrSize; i++)
    {
        if(myArray[i]>greatestElem)
        {
            greatestElem = myArray[i];
        }
    }
    return greatestElem;
}

int main(int argc, char const *argv[])
{
    int test[] = {1,2,3,8,10,99,55,7};

    if(findElement(test,8,7))
    {
        std::cout << "Am gasit pe 7 \n";
    }
    else
    {
        std::cout << "Nu am gasit \n";
    }

    std::cout<< "Cel mai mare element din array este: " << greatestElement(test,8) << std::endl;

    return 0;

    //functie care ne da cel mai mare lement din array

}
