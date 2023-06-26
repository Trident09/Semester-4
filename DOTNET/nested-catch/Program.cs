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
        catch (Exception ex)
        {
            try
            {
                throw new InvalidOperationException("Nested exception occurred.", ex);
            }
            catch (InvalidOperationException nestedEx)
            {
                Console.WriteLine("Nested exception: " + nestedEx.Message);
                Console.WriteLine("Inner exception: " + nestedEx.InnerException.Message);
            }
        }

        Console.WriteLine("Program continues after exception handling.");
    }
}