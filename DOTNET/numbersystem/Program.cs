namespace numbersystemconversion
{
    class Program
    {
        static void Main(string[] args)
        {
            convert();
        }


        static void convert()
        {
            Console.WriteLine("Conversion :");
            Console.WriteLine("1. Binary to Decimal");
            Console.WriteLine("2. Decimal to Binary");
            Console.WriteLine("3. Hex to Octal");
            Console.WriteLine("4. Octal to Decimal");
            int choice = Convert.ToInt32(Console.ReadLine());
            Console.WriteLine(choice);
            switch (choice)
            {
                case 1:
                {
                    Console.WriteLine("Enter the Binary value");
                    string input = Console.ReadLine();
                    int result = 0;
                    for (int i = input.Length; i > 0 ; i--)
                        if (input.Substring(i-1,1) == "1")
                            result += (int)Math.Pow(2,(input.Length-i));
                    Console.WriteLine("Decimal of " + input + " is " + result);
                    break;
                }
                case 2:
                {
                    Console.WriteLine("Enter Decimal the value");
                    int intNum = Convert.ToInt32(Console.ReadLine());
                    string binaryNum = Convert.ToString(intNum, 2);
                    Console.WriteLine("The binary of number " + intNum + " is " + binaryNum);
                    break;
                }
                case 3:
                {
                    Console.WriteLine("Enter Hexadecimal the value");
                    string value = Console.ReadLine();
                    string octalValue = Convert.ToString(Convert.ToInt32(value, 16), 8);
                    Console.WriteLine("The decimal of octal " + value + " is " + octalValue);
                    break;
                }
                case 4:
                {
                    Console.WriteLine("Enter Octal the value");
                    string octalNum = Console.ReadLine();
                    int DecimalNum = Convert.ToInt32(octalNum, 8);
                    Console.WriteLine("The decimal of number " + octalNum + " is " + DecimalNum);
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