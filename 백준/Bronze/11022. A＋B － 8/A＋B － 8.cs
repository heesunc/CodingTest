using System;

namespace codingstudy
{
    class Program
    {
        static void Main()
        {
            int t = int.Parse(Console.ReadLine()); // 테스트 케이스 입력
            int sum = 0;

            for (int i = 0; i < t; i++)
            {
                string[] s = Console.ReadLine().Split(); // 더할 값 입력
                int num1 = int.Parse(s[0]);
                int num2 = int.Parse(s[1]);
                sum = num1 + num2;

                Console.WriteLine($"Case #{i+1}: {num1} + {num2} = {sum}");
            }         
            
        }
    }
}