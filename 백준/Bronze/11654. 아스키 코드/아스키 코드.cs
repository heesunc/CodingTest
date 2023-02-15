using System;
using static System.Console;

namespace baekioon
{
    class MainApp
    {
        static void Main()
        {
            char asc;
            asc = Convert.ToChar(Console.ReadLine());

            int code1 = (int)asc;
            Console.WriteLine(code1);
        }
    }
}