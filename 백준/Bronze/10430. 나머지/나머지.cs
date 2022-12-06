using System;

namespace codingstudy
{
    class Program
    {
        static void Main(string[] args)
        {
            string[] num = Console.ReadLine().Split();
            
            int a = int.Parse(num[0]);
            int b = int.Parse(num[1]);
            int c = int.Parse(num[2]);

            Console.WriteLine((a+b)%c);
            Console.WriteLine(((a%c)+(b%c))%c);
            Console.WriteLine((a*b)%c);
            Console.WriteLine(((a%c)*(b%c))%c);
        }
    }
}