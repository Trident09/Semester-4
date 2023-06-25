namespace vowels
{
    class Program
    {
        static void Main(string[] args)
        {
            count();
        }


        static void count()
        {
            int total = 0;
            // Build a list of vowels up front:
            var vowels = new HashSet<char> { 'a', 'e', 'i', 'o', 'u' };
            Console.WriteLine("Enter a Sentence");
            string sentence = Console.ReadLine().ToLower();

            for (int i = 0; i < sentence.Length; i++)
            {
                if (vowels.Contains(sentence[i]))
                {
                    total++;
                }
            }
            Console.WriteLine("Your total number of vowels is: {0}", total);
        }
    }
}