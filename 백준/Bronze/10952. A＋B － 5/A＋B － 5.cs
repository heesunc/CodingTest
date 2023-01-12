using System;

namespace codingstudy
{
    class Program
    {
        static void Main()
        {
            int sum = 0;
            int num1=1, num2=1;

            while (num1!=0 && num2!=0)
            {
                string[] s = Console.ReadLine().Split(); // 더할 값 입력
                num1 = int.Parse(s[0]);
                num2 = int.Parse(s[1]);

                sum = num1 + num2;
                if (num1!=0 && num2!=0)
                {
                    Console.WriteLine($"{sum}");
                }                
            }
        }
    }
}