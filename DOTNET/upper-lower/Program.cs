using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ConsoleApp5
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Enter a string in lowercase: ");
            string s1 = Console.ReadLine();

            Console.WriteLine("Enter a string in uppercase: ");
            string s2 = Console.ReadLine();

            Console.WriteLine("Uppercase string of {0} : {1}", s1, s1.ToUpper());
            Console.WriteLine("Lowercase string of {0} : {1}", s2, s2.ToLower());

        }
    }
}