using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace temperature {

     class Program {

        static void Main(string[] args) {
            Console.WriteLine("Convert");
            Console.WriteLine("1. Celcius to Fahrenheit");
            Console.WriteLine("2. Fahrenheit to Celcius");
            int choice = Convert.ToInt32(Console.ReadLine()); 
            switch (choice)
            {
                case 1:
                {
                    double celsius;
                    Console.WriteLine("Enter the fahrenheit value");
                    double fahrenheit = Convert.ToDouble(Console.ReadLine());
                    Console.WriteLine("Fahrenheit: " + fahrenheit);
                    celsius = (fahrenheit - 32) * 5 / 9;
                    Console.WriteLine("Celsius: " + celsius);
                    break;
                }
                case 2:
                {
                    double fahrenheit;
                    Console.WriteLine("Enter the celcius value");
                    double celsius = Convert.ToDouble(Console.ReadLine());
                    Console.WriteLine("Celsius: " + celsius);
                    fahrenheit = (celsius * 9) / 5 + 32;
                    Console.WriteLine("Fahrenheit: " + fahrenheit);
                    break;
                }
                default:
                break;
            }

            
        }
    }
}