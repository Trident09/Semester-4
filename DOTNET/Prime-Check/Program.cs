namespace CheckPrime
{
    class Program
    {
        static void Main(string[] args)
        {
            game();
        }


        static void game()
        {
            Console.WriteLine("Enter the number");
            int num = Convert.ToInt32(Console.ReadLine());
            for (int i = 2; i <= num; i++)
            {
                if (num % i == 0)
                {
                    Console.WriteLine("Not a prime number");
                    break;
                }
                else if (i == num - 1)
                {
                    Console.WriteLine("Prime number");
                    break;
                }
            }
        }
    }
}
