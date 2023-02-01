using System;
using System.Linq;

namespace codingstudy
{
    class Program
    {
        static void Main()
        {
            int[] num = new int[31];

            for (int i = 0; i < 28; i++)
            {
                int n = int.Parse(Console.ReadLine());
                num[n] = 1;
            }

            for (int i = 1; i <= 30; i++)
            {
                if (num[i] != 1)
                {
                    Console.WriteLine(i);
                }
            }
        }
    }
}