#include <iostream>

void FizzBuzz(int count);
void FizzBuzzOptimized(int count);
void FizzBuzzAppend(int count);

int main()
{
    //FizzBuzz(20);
    //FizzBuzzOptimized(20);
    FizzBuzzAppend(20);

    return 0;
}
void FizzBuzz(int count)
{
    for (int i = 1; i <= count; ++i)
    {
        // can also use i % 15
        if (i % 3 == 0 && i % 5 == 0)
        {
            std::cout << "FizzBuzz" << std::endl;
        }
        else if (i % 3 == 0)
        {
            std::cout << "Fizz" << std::endl;
        }
        else if (i % 5 == 0)
        {
            std::cout << "Buzz" << std::endl;
        }
        else
            std::cout << i << std::endl;
    }
}
void FizzBuzzOptimized(int count)
{
    for (int i = 1; i <= count; ++i)
    {
        bool multiplesOf3 = ((i % 3) == 0);
        bool multiplesOf5 = ((i % 5) == 0);
        if (multiplesOf3 && multiplesOf5)
        {
            std::cout << "FizzBuzz" << std::endl;
        }
        else if (multiplesOf3)
        {
            std::cout << "Fizz" << std::endl;
        }
        else if (multiplesOf5)
        {
            std::cout << "Buzz" << std::endl;
        }
        else
            std::cout << i << std::endl;
    }
}
// FizzBuzz using the append method
void FizzBuzzAppend(int count)
{
    for (int i = 1; i <= count; ++i)
    {
        bool output = false;
        if (i % 3 == 0)
        {
            std::cout << "Fizz";
            output = true;
        }
        if (i % 5 == 0)
        {
            std::cout << "Buzz";
            output = true;
        }
        if (output == false)
            std::cout << i;

        std::cout << '\n';
    }
}
