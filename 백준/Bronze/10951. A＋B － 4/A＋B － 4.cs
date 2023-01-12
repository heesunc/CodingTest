using System;

namespace codingstudy
{
    class Program
    {
        static void Main()
        {
            while (true)
            {
                string input = Console.ReadLine();

                if (input == null) break;
                
                string[] s = input.Split();

                int num1 = int.Parse(s[0]);
                int num2 = int.Parse(s[1]);
                int sum = num1 + num2;

                Console.WriteLine(sum);
            }
        }
    }
}