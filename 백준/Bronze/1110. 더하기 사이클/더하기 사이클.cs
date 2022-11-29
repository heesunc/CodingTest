using System;

namespace bj1110
{
    class Program
    {
        static void Main(string[] args)
        {
            string inputNum = Console.ReadLine();

            int count = 0;
            int addNum;

            if (10> int.Parse(inputNum))
            {
                inputNum = inputNum + 0;
            }

            string originalNum = inputNum;

            while(true)
            {
                count++;
                int a = int.Parse(inputNum) / 10;
                int b = int.Parse(inputNum) % 10;
                addNum = a+b;

                inputNum = b.ToString() + (addNum % 10).ToString();

                if(int.Parse(inputNum) == int.Parse(originalNum))
                break;
            }
            Console.WriteLine(count);
        }
    }
}