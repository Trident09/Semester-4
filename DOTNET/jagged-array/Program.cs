namespace sphere
{
    class Program
    {
        static void Main(string[] args)
        {
            jagged();
        }


        static void jagged()
        {
            Console.WriteLine("Enter the number of rows");
            int rows = Convert.ToInt32(Console.ReadLine());
            int[][] arr = new int[rows][];
            for (int i = 0; i < rows; i++)
            {
                Console.WriteLine("Enter the numbers in row " + (i + 1));
                int size = Convert.ToInt32(Console.ReadLine());
                arr[i] = new int[size];
                for (int j = 0; j < size; j++)
                {
                    Console.WriteLine("Enter the element " + (j + 1));
                    arr[i][j] = Convert.ToInt32(Console.ReadLine());
                }
            }

            //print the jagged 2d array
            Console.WriteLine("The jagged 2D array is ");
            for (int i = 0; i < rows; i++)
            {
                for (int j = 0; j < arr[i].Length; j++)
                {
                    Console.Write(arr[i][j] + " ");
                }
                Console.WriteLine();
            }

        }
    }
}