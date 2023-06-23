namespace smallestNumber
{
    class Program
    {
        static void Main(string[] args)
        {
            smallest();
        }


        static void smallest()
        {
            Console.WriteLine("Enter the size of array");
            int size = Convert.ToInt32(Console.ReadLine());
            int[] arr = new int[size];
            for (int i = 0; i < size; i++)
            {
                Console.WriteLine("Enter the element");
                arr[i] = Convert.ToInt32(Console.ReadLine());
            }
            int smallest = arr[0];
            for (int i = 0; i < size; i++)
            {
                if (arr[i] < smallest)
                {
                    smallest = arr[i];
                }
            }
            Console.WriteLine("The smallest number is " + smallest);
        }
    }
}