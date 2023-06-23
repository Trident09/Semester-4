namespace fibonacci
{
    class Program
    {
        static void Main(string[] args)
        {
            Fibonnaci();
        }
        static void Fibonnaci(){
        Console.WriteLine("Enter the number of sequence");
        int num = Convert.ToInt32(Console.ReadLine());
        int a = 0;
        int b = 1;
        int c = 0;      
        for ( int i = 0 ; i < num ; i++){
            c = a + b;
            a = b;
            b = c;
            if (i == num - 1){
                Console.Write(c+"\n");
            }
            else{
                Console.Write(c + " , ");
            }
        }
        
    }
    }
}