#include <iostream>

void FizzBuzz(int count);
void FizzBuzzOptimized(int count);
void FizzBuzzAppend(int count);
void FizzBuzzSwitch(unsigned int count);
void FizzBuzzAddition(int count);
void FizzBuzzAddition2(int count);

int main()
{
    //FizzBuzz(20);
    //FizzBuzzOptimized(20);
    //FizzBuzzAppend(20);
    //FizzBuzzSwitch(20);
    //FizzBuzzAddition(20);
	FizzBuzzAddition2(20);

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
// FizzBuzz using switch-case written by Lewis1986
// Comment in https://www.codeproject.com/Articles/1244852/The-Real-Answer-to-the-FizzBuzz-Interview-Question
void FizzBuzzSwitch(unsigned int count) 
{
    for (unsigned int i = 1; i <= count; ++i)
    {
        unsigned int test = 0;
        test |= (i % 3 == 0) ? 2 : 0; // set 3 if is fizz
        test |= (i % 5 == 0) ? 4 : 0; // set 5 if is buzz
        switch (test & 6) {
        case 6:
            std::cout << "FizzBuzz" << std::endl;
            break;
        case 2:
            std::cout << "Fizz" << std::endl;
            break;
        case 4:
            std::cout << "Buzz" << std::endl;
            break;
        default:
            std::cout << i << std::endl;
        }
    }
}
// Submitted by Jacques Fournier
void FizzBuzzAddition(int count)
{
	int c3 = 0;
	int c5 = 0;
	for (int i = 1; i <= count; ++i)
	{
		++c3;
		++c5;
		if (c3 == 3)
			c3 = 0;
		if (c5 == 5)
			c5 = 0;

		if (c3 == 0 && c5 == 0)
		{
            std::cout << "FizzBuzz" << std::endl;
		}
		else if (c3 == 0)
		{
            std::cout << "Fizz" << std::endl;
		}
		else if (c5 == 0)
		{
            std::cout << "Buzz" << std::endl;
		}
        else
        {
            std::cout << i << std::endl;
        }
	}
}
// Submitted by Bela Gyuricza
void FizzBuzzAddition2(int count)
{
	int c3 = 3;
	int c5 = 5;
	for (int i = 1; i <= count; ++i)
	{
		if (c3 == i && c5 == i)
		{
            std::cout << "FizzBuzz" << std::endl;
			c3 += 3;
			c5 += 5;
		}
		else if (c3 == i)
		{
            std::cout << "Fizz" << std::endl;
			c3 += 3;
		}
		else if (c5 == i)
		{
            std::cout << "Buzz" << std::endl;
			c5 += 5;
		}
        else
        {
            std::cout << i << std::endl;
        }
	}
}
