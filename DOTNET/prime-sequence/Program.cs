namespace PrimeSequence
{
    class Program
    {
        static void Main(string[] args)
        {
            Prime();
        }


        static void Prime()
        {
            //input the range and find all the prime numbers in the range
            Console.WriteLine("Enter the range");
            int range = Convert.ToInt32(Console.ReadLine());
            int counter = 0;
            for (int i = 2; i <= range; i++)
            {
                for (int j = 2; j <= i; j++)
                {
                    if (i % j == 0)
                    {
                        break;
                    }
                    else if (j == i - 1)
                    {
                        Console.Write(i + " ");
                        counter++;
                    }
                }
            }
            Console.WriteLine("\nThere are " + counter + " prime numbers in the range");
        }
    }
}