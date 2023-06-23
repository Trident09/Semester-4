namespace floyd
{
    class Program
    {
        static void Main(string[] args)
        {
            floyd();
        }


        static void floyd()
        {
            Console.WriteLine("Enter the number of rows");
            int rows = Convert.ToInt32(Console.ReadLine());
            int num = 1;
            for (int i = 1; i <= rows; i++)
            {
                for (int j = i; j > 0; j--)
                {
                    Console.Write(num + " ");
                    num++;
                }
                Console.WriteLine();
            }
        }
    }
}