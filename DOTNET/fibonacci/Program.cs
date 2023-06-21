namespace fibonacci
{
    class Program
    {
        static void Main(string[] args)
        {
            int t1 = 0, t2 = 1, next_term = t1 + t2;
            Console.WriteLine(t1);
            Console.WriteLine(t2);
            for (int i = 1; i < 10; i++)
            {
                t1 = t2;
                t2 = next_term;
                next_term = t1 + t2;
                Console.WriteLine(t1);
            }
        }
    }
}
