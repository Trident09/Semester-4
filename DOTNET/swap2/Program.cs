namespace swapwithout3rdvariable
{
    class Program
    {
        static void Main(string[] args)
        {
            swap();
        }


        static void swap()
        {
            Console.WriteLine("Enter the number 1");
            double x = Convert.ToDouble(Console.ReadLine());
            Console.WriteLine("Enter the number 2");
            double y = Convert.ToDouble(Console.ReadLine());
            Console.WriteLine(" x is " + x);
            Console.WriteLine(" y is " + y);
            x = x + y;
            y = x - y;
            x = x - y;
            Console.WriteLine("After Swap x is " + x);
            Console.WriteLine("After Swap y is " + y);
        }
    }
}