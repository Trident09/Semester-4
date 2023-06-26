using System;

class Adder
{
    public int Add(int num1, int num2)
    {
        return num1 + num2;
    }

    public double Add(double num1, double num2)
    {
        return num1 + num2;
    }

    public string Add(string str1, string str2)
    {
        return str1 + str2;
    }
}

class Program
{
    static void Main(string[] args)
    {
        Adder adder = new Adder();

        int sum1 = adder.Add(3, 4);
        double sum2 = adder.Add(2.5, 1.5);
        string sum3 = adder.Add("Hello", " World");

        Console.WriteLine("Sum 1: " + sum1);
        Console.WriteLine("Sum 2: " + sum2);
        Console.WriteLine("Sum 3: " + sum3);
    }
}