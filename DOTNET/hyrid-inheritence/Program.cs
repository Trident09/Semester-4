using System;

interface IAnimal
{
    void Eat();
}

class Animal
{
    public void Sleep()
    {
        Console.WriteLine("Animal is sleeping.");
    }
}

class Cat : Animal, IAnimal
{
    public void Eat()
    {
        Console.WriteLine("Cat is eating.");
    }
}

class Program
{
    static void Main(string[] args)
    {
        Cat cat = new Cat();
        cat.Eat();    // Inherited from IAnimal
        cat.Sleep();  // Inherited from Animal
    }
}