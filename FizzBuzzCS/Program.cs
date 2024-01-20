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
            FizzBuzzAppend(20);
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
    }
}
