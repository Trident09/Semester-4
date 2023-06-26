using System;

class Program
{
    static void Main(string[] args)
    {
        try
        {
            int numerator = 10;
            int denominator = 0;
            int result = numerator / denominator;
            Console.WriteLine("Result: " + result); // This line won't execute
        }
        catch (DivideByZeroException ex)
        {
            Console.WriteLine("Error: " + ex.Message);
        }
        finally
        {
            Console.WriteLine("Finally block executed.");
        }

        Console.WriteLine("Program continues after exception handling.");
    }
}