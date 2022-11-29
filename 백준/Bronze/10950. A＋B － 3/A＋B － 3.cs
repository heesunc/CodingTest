using System;

public class bj10950
{
    class Program
    {
        static void Main(string[] args)
        {
            int t = int.Parse(Console.ReadLine());

            for (int i = 0; i < t; i++)
            {
                string[] s = Console.ReadLine().Split();
                int num1 = int.Parse(s[0]);
                int num2 = int.Parse(s[1]);

                Console.WriteLine(num1 + num2);
            }
        }
    }
}