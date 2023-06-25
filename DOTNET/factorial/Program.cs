namespace factorial
{
    class Program
    {
        static void Main(string[] args)
        {
            factorial();
        }


        static void factorial()
        {
            int num, n, fac;
            Console.WriteLine("Please enter a number to get its factorial: ");
            n = Convert.ToInt32(Console.ReadLine());
            num = 1;
            fac = 1;
            while (num < n)
            {
                fac = fac * (num+1);
                num++;
            }
            Console.WriteLine("Factorial of {0}! = {1}\n", num, fac);
        }
    }
}