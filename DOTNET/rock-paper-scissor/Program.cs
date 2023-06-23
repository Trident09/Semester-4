namespace rockPaperScissor
{
    class Program
    {
        static void Main(string[] args)
        {
            game();
        }


        static void game()
        {
            while (true)
            {
                Console.WriteLine("Enter your choice");
                Console.WriteLine("1. Rock");
                Console.WriteLine("2. Paper");
                Console.WriteLine("3. Scissors");
                int choice = Convert.ToInt32(Console.ReadLine());
                Random rnd = new Random();
                int computer = rnd.Next(1, 4);
                // make a string arr
                string[] arr = new string[3];
                arr[0] = "Rock";
                arr[1] = "Paper";
                arr[2] = "Scissors";
                //computer thinking time
                Console.WriteLine("Computer is thinking...");
                System.Threading.Thread.Sleep(2000);
                Console.WriteLine("Computer choice is " + arr[computer - 1]);
                if (choice == 1)
                {
                    if (computer == 1)
                    {
                        Console.WriteLine("Draw");
                    }
                    else if (computer == 2)
                    {
                        Console.WriteLine("You lose");
                    }
                    else
                    {
                        Console.WriteLine("You win");
                    }
                }
                else if (choice == 2)
                {
                    if (computer == 1)
                    {
                        Console.WriteLine("You win");
                    }
                    else if (computer == 2)
                    {
                        Console.WriteLine("Draw");
                    }
                    else
                    {
                        Console.WriteLine("You lose");
                    }
                }
                else if (choice == 3)
                {
                    if (computer == 1)
                    {
                        Console.WriteLine("You lose");
                    }
                    else if (computer == 2)
                    {
                        Console.WriteLine("You win");
                    }
                    else
                    {
                        Console.WriteLine("Draw");
                    }
                }
                else
                {
                    Console.WriteLine("Invalid input");
                }
                Console.WriteLine("Do you want to play again? (y/n)");
                string answer = Console.ReadLine();
                if (answer == "n")
                {
                    break;
                }
                else if (answer == "y")
                {
                    continue;
                }
                else
                {
                    Console.WriteLine("Invalid input");
                }


            }
        }
    }
}