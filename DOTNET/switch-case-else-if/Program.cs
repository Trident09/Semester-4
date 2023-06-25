using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace switchcaseelseifladder {

     class Program {

        static void Main(string[] args) {
            Console.WriteLine("Demonstrate");
            Console.WriteLine("1. Switch-case");
            Console.WriteLine("2. Else-if ladder");
            int choice = Convert.ToInt32(Console.ReadLine()); 
            switch (choice)
            {
                case 1:
                {
                    Console.WriteLine("Enter switch choice");
                    int switchOption = Convert.ToInt32(Console.ReadLine());
                    switch (switchOption)
                    {
                        case 1:
                        {
                            Console.WriteLine("This is option 1");
                            break;
                        }
                        case 2:
                        {
                            Console.WriteLine("This is option 2");
                            break;
                        }
                        case 3:
                        {
                            Console.WriteLine("This is option 3");
                            break;
                        }
                        default:
                        {
                            Console.WriteLine("Option greater than 3");
                            break;
                        }
                    }

                    break;
                }
                case 2:
                {
                    Console.WriteLine("Enter the else if ladder choice");
                    int elseIfOption = Convert.ToInt32(Console.ReadLine());
                    if (elseIfOption == 1) {
                        Console.WriteLine("This is option 1");
                    } else if (elseIfOption == 2) {
                        Console.WriteLine("This is option 2");
                    } else if (elseIfOption == 3) {
                        Console.WriteLine("This is option 3");
                    } else {
                        Console.WriteLine("Number Greater than 3");
                    }
                    break;
                }
                default:
                {
                    Console.WriteLine("Invalid Choice");
                    break;
                }
            }

            
        }
    }
}