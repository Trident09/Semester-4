namespace sphere
{
    class Program
    {
        static void Main(string[] args)
        {
            sphere();
        }


        static void sphere()
        {
            Console.WriteLine("Enter the radius of the sphere");
            double radius = Convert.ToDouble(Console.ReadLine());
            double volume = 4.00 / 3.00 * Math.PI * radius * radius * radius;
            Console.WriteLine("The volume of the sphere is " + volume);
            double surfaceArea = 4 * Math.PI * radius * radius;
            Console.WriteLine("The surface area of the sphere is " + surfaceArea);
        }
    }
}