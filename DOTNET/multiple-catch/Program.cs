using System;

class Program
{
    static void Main(string[] args)
    {
        try
        {
            int[] numbers = { 1, 2, 3 };
            int index = 4;
            int result = numbers[index]; // This line will throw an IndexOutOfRangeException
            Console.WriteLine("Result: " + result); // This line won't execute
        }
        catch (IndexOutOfRangeException ex)
        {
            Console.WriteLine("Index out of range error: " + ex.Message);
        }
        catch (DivideByZeroException ex)
        {
            Console.WriteLine("Divide by zero error: " + ex.Message);
        }
        catch (Exception ex)
        {
            Console.WriteLine("Generic error: " + ex.Message);
        }

        Console.WriteLine("Program continues after exception handling.");
    }
}