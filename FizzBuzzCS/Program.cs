using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace FizzBuzzCS
{
    internal class Program
    {
        static void Main(string[] args)
        {
            //FizzBuzz(20);
            //FizzBuzzOptimized(20);
            //FizzBuzzAppend(20);
            //FizzBuzzAddition(20);
            FizzBuzzSwitch(20);
        }
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

                Console.Write('\n');
            }
        }
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
        static void FizzBuzzAddition(int runningCount)
        {
            int fizzBuzzCount = 0;
            int fizzCount = 0;
            int buzzCount = 0;
            int numCount = 0;
            int c3 = 0;
            int c5 = 0;

            for (int i = 1; i <= runningCount; ++i)
            {
                if (++c3 == 3)
                {
                    c3 = 0;
                    if (++c5 == 5)
                    {
                        c5 = 0;
                    }
                }
                if (c3 == 0)
                {
                    if (c5 == 0)
                    {
                        fizzBuzzCount++;
                        Console.WriteLine("FizzBuzz");
                    }
                    else
                    {
                        buzzCount += 1;
                        Console.WriteLine("Fizz");
                    }
                }
                else if (c5 == 0)
                {
                    fizzCount++;
                    Console.WriteLine("Buzz");
                }
                else
                {
                    numCount++;
                    Console.WriteLine(i);
                }
            }
        }
    }
}
