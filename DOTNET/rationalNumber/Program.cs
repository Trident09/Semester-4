namespace RationalNumber
{
    class Program
    {
        static void Main(string[] args)
        {
            Rational();
        }


        static void Rational()
        {
            Console.WriteLine("Enter the number");
            double num = Convert.ToDouble(Console.ReadLine());
            if (num % 1 == 0)
            {
                Console.WriteLine("The number is rational");
            }
            else
            {
                Console.WriteLine("The number is irrational");
            }
        }
    }
}