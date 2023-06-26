using System.Collections;
using System.Collections.Generic;
using System.Collections.ObjectModel;

using System;
using System.Collections;

class Program
{
    static void Main(string[] args)
    {
        // ArrayList
        ArrayList arrayList = new ArrayList();
        arrayList.Add("Apple");
        arrayList.Add("Banana");
        arrayList.Add("Cherry");
        Console.WriteLine("ArrayList:");
        foreach (var item in arrayList)
        {
            Console.WriteLine(item);
        }
        Console.WriteLine();

        // List<T>
        List<string> list = new List<string>();
        list.Add("Car");
        list.Add("Bus");
        list.Add("Train");
        Console.WriteLine("List<T>:");
        foreach (var item in list)
        {
            Console.WriteLine(item);
        }
        Console.WriteLine();

        // Stack
        Stack stack = new Stack();
        stack.Push("Red");
        stack.Push("Green");
        stack.Push("Blue");
        Console.WriteLine("Stack:");
        while (stack.Count > 0)
        {
            Console.WriteLine(stack.Pop());
        }
        Console.WriteLine();

        // Queue
        Queue queue = new Queue();
        queue.Enqueue("One");
        queue.Enqueue("Two");
        queue.Enqueue("Three");
        Console.WriteLine("Queue:");
        while (queue.Count > 0)
        {
            Console.WriteLine(queue.Dequeue());
        }
        Console.WriteLine();

        // HashSet<T>
        HashSet<string> hashSet = new HashSet<string>();
        hashSet.Add("Dog");
        hashSet.Add("Cat");
        hashSet.Add("Bird");
        Console.WriteLine("HashSet<T>:");
        foreach (var item in hashSet)
        {
            Console.WriteLine(item);
        }
        Console.WriteLine();

        // Dictionary<TKey, TValue>
        Dictionary<int, string> dictionary = new Dictionary<int, string>();
        dictionary.Add(1, "Monday");
        dictionary.Add(2, "Tuesday");
        dictionary.Add(3, "Wednesday");
        Console.WriteLine("Dictionary<TKey, TValue>:");
        foreach (var item in dictionary)
        {
            Console.WriteLine(item.Key + ": " + item.Value);
        }
        Console.WriteLine();

        // SortedList<TKey, TValue>
        SortedList<int, string> sortedList = new SortedList<int, string>();
        sortedList.Add(3, "Third");
        sortedList.Add(1, "First");
        sortedList.Add(2, "Second");
        Console.WriteLine("SortedList<TKey, TValue>:");
        foreach (var item in sortedList)
        {
            Console.WriteLine(item.Key + ": " + item.Value);
        }
        Console.WriteLine();

        // LinkedList<T>
        LinkedList<string> linkedList = new LinkedList<string>();
        linkedList.AddLast("Apple");
        linkedList.AddLast("Banana");
        linkedList.AddLast("Cherry");
        Console.WriteLine("LinkedList<T>:");
        foreach (var item in linkedList)
        {
            Console.WriteLine(item);
        }
        Console.WriteLine();

        // ObservableCollection<T>
        ObservableCollection<string> observableCollection = new ObservableCollection<string>();
        observableCollection.CollectionChanged += (sender, e) =>
        {
            Console.WriteLine("ObservableCollection<T> changed.");
        };
        observableCollection.Add("First");
        observableCollection.Add("Second");
        observableCollection.Add("Third");
        Console.WriteLine();

        Console.WriteLine("Press any key to exit.");
        Console.ReadKey();
    }
}