using System;

namespace Example
{
    class Program
    {
        static void Main(string[] args)
        {
            string[] n = Console.ReadLine().Split();
            int A=int.Parse(n[0]);
            int B=int.Parse(n[1]);
            
            if (A > B){
                Console.WriteLine(">");
            }
            else if (A < B){
                Console.WriteLine("<");
            }
            else if (A == B){
                Console.WriteLine("==");
            }
        }
    }
}