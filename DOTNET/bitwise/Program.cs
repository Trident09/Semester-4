namespace sphere
{
    class Program
    {
        static void Main(string[] args)
        {
            bitwise();
        }


        static void bitwise()
        {
            //demonstrate bitwise operator
            Console.WriteLine("Enter the number 1");
            int num1 = Convert.ToInt32(Console.ReadLine());
            Console.WriteLine("Enter the number 2");
            int num2 = Convert.ToInt32(Console.ReadLine());
            //convert to binary
            string binary1 = Convert.ToString(num1, 2);
            string binary2 = Convert.ToString(num2, 2);
            Console.WriteLine("The binary of number 1 is " + binary1);
            Console.WriteLine("The binary of number 2 is " + binary2);
            Console.WriteLine("The bitwise AND is " + (num1 & num2));
            Console.WriteLine("The bitwise OR is " + (num1 | num2));
            Console.WriteLine("The bitwise XOR is " + (num1 ^ num2));
            Console.WriteLine("The bitwise NOT of number 1 is " + (~num1));
            Console.WriteLine("The bitwise NOT of number 2 is " + (~num2));
        }
    }
}