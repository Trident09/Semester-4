using System;

interface IAnimal
{
    void Eat();
}

interface IFlyable
{
    void Fly();
}

class Bird : IAnimal, IFlyable
{
    public void Eat()
    {
        Console.WriteLine("Bird is eating.");
    }

    public void Fly()
    {
        Console.WriteLine("Bird is flying.");
    }
}

class Program
{
    static void Main(string[] args)
    {
        Bird bird = new Bird();
        bird.Eat();
        bird.Fly();
    }
}