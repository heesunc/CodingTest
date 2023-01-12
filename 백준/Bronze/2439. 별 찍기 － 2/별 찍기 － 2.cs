using System;

namespace codingstudy
{
    class Program
    {
        static void Main()
        {
            int n = int.Parse(Console.ReadLine());
        
            for (int i=1; i<=n; i++)
            {
                for(int j=n; j>=i+1; j--)
                {
                    Console.Write(" ");
                }
                for(int k=1; k<i+1; k++)
                {
                    Console.Write("*");
                }
                Console.Write("\n");
            }
        }
    }
}