# Solving Fizz Buzz in C# and C++

## Table of Contents

* Introduction
* The First Method
* The Optimized Method
* The Append Method
* The Switch-Case Method
* The Addition Method
* The Optimized Addition Method
* Output
* History

## Introduction

Fizz Buzz is a popular interview question to test the job candidates&rsquo; problem-solving ability. The task is to write a program to count incrementally, replacing any number divisible by three with the word `"Fizz"`, and any number divisible by five with the word `"Buzz"`, and any number divisible by both three and five with the word `"FizzBuzz"`.

The claim circulated on the web that most programmers cannot solve Fizz Buzz has been greatly exaggerated. We have no reason to believe that. But a junior programmer can be stumped by this question if he does not know that the division&rsquo;s remainder can be used to find out if a number is multiple of the divisor. The answer is when the remainder is zero. In C# and C++, we use the modulus operator (represented by the percentage sign, `%`) to calculate the remainder.

For example, we use division and remainder to find 146 minutes is how many hours and minutes. Below is the C# code. Please click on the C++ tab to see C++ code.

```CSharp
int totalMinutes = 146;
Console.WriteLine("{0} minutes is equal to {1} hours {2} minutes",
    totalMinutes, totalMinutes / 60, totalMinutes % 60);
```

```Cpp
int totalMinutes = 146;
printf("%d minutes is equal to %d hours %d minutes",
    totalMinutes, totalMinutes / 60, totalMinutes % 60);
```

The output is:

```
146 minutes is equal to 2 hours 26 minutes
```

As a small optimization tip, always do division and modulus operations in quick succession because the compiler can emit the same Intel x86&nbsp;div instruction to calculate both division and remainder together. If there are many lines of code in between your division and remainder operation, the compiler may emit another div instruction for your remainder which is counter-productive.

## The First Method

Please note the for-loop counter cannot start from zero because zero modulo by any number is zero. Both `0 % 3` and `0 % 5` give zero, and `"FizzBuzz"` will be printed, which is not what we want because zero is not multiples of `3` and `5`.

```CSharp
static void FizzBuzz(int count)
{
    for(int i = 1; i <= count; ++i) 
    {
        // can also use i % 15
        if (i % 3 == 0 && i % 5 == 0)
        {
            Console.WriteLine("FizzBuzz");
        }
        else if (i % 3 == 0)
        {
            Console.WriteLine("Fizz");
        }
        else if (i % 5 == 0)
        {
            Console.WriteLine("Buzz");
        }
        else
            Console.WriteLine(i);
    }
}
```

```Cpp
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
```

## The Optimized Method

As a minor optimization, since modulus is a time-consuming operation, we can cache the result in a variable to be reused.

```CSharp
static void FizzBuzzOptimized(int count)
{
    for (int i = 1; i <= count; ++i)
    {
        bool multiplesOf3 = ((i % 3) == 0);
        bool multiplesOf5 = ((i % 5) == 0);

        if (multiplesOf3 && multiplesOf5)
        {
            Console.WriteLine("FizzBuzz");
        }
        else if (multiplesOf3)
        {
            Console.WriteLine("Fizz");
        }
        else if (multiplesOf5)
        {
            Console.WriteLine("Buzz");
        }
        else
            Console.WriteLine(i);
    }
}
```

```Cpp
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
```

## The Append Method

There is another way to do the Fizz Buzz program by concatenation of `"Fizz"` and `"Buzz"` whenever the number is both multiple of `3` and `5` without using `WriteLine` or `std::endl` in C++ case. The reason for not using `WriteLine` is it sets the next output to the new line breaking up the words, `"Fizz"` and `"Buzz"`.

```CSharp
// FizzBuzz using the append method
static void FizzBuzzAppend(int count)
{
    for (int i = 1; i <= count; ++i)
    {
        bool output = false;
        if (i % 3 == 0)
        {
            Console.Write("Fizz");
            output = true;
        }
        if (i % 5 == 0)
        {
            Console.Write("Buzz");
            output = true;
        }
        if (output == false)
            Console.Write(i);

        Console.Write(&#39;\n&#39;);
    }
}
```

```Cpp
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

        std::cout << &#39;\n&#39;;
    }
}
```

## The Switch-Case Method

It is possible to do the Fizz Buzz program using switch-case. It is a variant of the optimized method. Submitted By Lewis1986

```CSharp
// FizzBuzz using the switch-case method
static void FizzBuzzSwitch(uint count)
{
    for (uint i = 1; i <= count; ++i)
    {
        uint test = 0;
        test |= (uint)((i % 3 == 0) ? 2 : 0); // set 3 if is fizz
        test |= (uint)((i % 5 == 0) ? 4 : 0); // set 5 if is buzz
        switch (test & 6)
        {
            case 6:
                Console.WriteLine("FizzBuzz");
                break;
            case 2:
                Console.WriteLine("Fizz");
                break;
            case 4:
                Console.WriteLine("Buzz");
                break;
            default:
                Console.WriteLine(i);
                break; // to silent the warning in C# compiler
        }
    }
}
```

```Cpp
// FizzBuzz using the switch-case method
void FizzBuzzSwitch(unsigned int count) 
{
    for (unsigned int i = 1; i <= count; ++i)
    {
        unsigned int test = 0;
        test |= (i % 3 == 0) ? 2 : 0; // set 3 if is fizz
        test |= (i % 5 == 0) ? 4 : 0; // set 5 if is buzz
        switch (test & 6) {
        case 6:
            std::cout << "FizzBuzz\n";
            break;
        case 2:
            std::cout << "Fizz\n";
            break;
        case 4:
            std::cout << "Buzz\n";
            break;
        default:
            std::cout << i << "\n";
        }
    }
}
```

## The Addition Method

The method contributed By Jacques Fournier makes use of two more counters to keep track of whether they add up to `3` or `5` and reset them to zero. The subsequent checks detect the counter is zero to determine a multiple of `3` or `5`. It is an ingenious way to avoid using the time-consuming modulo operator.

```CSharp
// FizzBuzz using the addition method
static void FizzBuzzAddition(int count)
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
            Console.WriteLine("FizzBuzz");
        }
        else if (c3 == 0)
        {
            Console.WriteLine("Fizz");
        }
        else if (c5 == 0)
        {
            Console.WriteLine("Buzz");
        }
        else
            Console.WriteLine(i);
    }
}
```

```Cpp
// FizzBuzz using the addition method
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
            std::cout << i << std::endl;
    }
}
```

## The Optimized Addition Method

Bela Gyuricza slightly alters the above method by removing the checks to reset `c3` and `c5` to zero. The logic is hard to understand at first glance. I tested the code and it works correctly.

```CSharp
static void FizzBuzzAddition2(int count)
{
    int c3 = 3;
    int c5 = 5;
    for (int i = 1; i <= count; ++i)
    {
        if (c3 == i && c5 == i)
        {
            Console.WriteLine("FizzBuzz");
            c3 += 3;
            c5 += 5;
        }
        else if (c3 == i)
        {
            Console.WriteLine("Fizz");
            c3 += 3;
        }
        else if (c5 == i)
        {
            Console.WriteLine("Buzz");
            c5 += 5;
        }
        else
            Console.WriteLine(i);
    }
}
```

```Cpp
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
```

The difference in solving style is a matter of preference.

## Output

All six methods produce identical&nbsp;output.

```
1
2
Fizz
4
Buzz
Fizz
7
8
Fizz
Buzz
11
Fizz
13
14
FizzBuzz
16
17
Fizz
19
Buzz
```

## History

* 7<sup>th</sup> February, 2024: Added the optimized addition method</a> contributed by Bela Gyuricza
* 30<sup>th</sup> January, 2024: Added the addition method</a> contributed by Jacques Fournier
* 28<sup>th</sup> January, 2024: Added the switch-case method</a> contributed by Lewis1986
* 20<sup>th</sup> January, 2024: First release
