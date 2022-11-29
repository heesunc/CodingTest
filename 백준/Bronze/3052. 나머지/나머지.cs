using System;

namespace 백준3052번_나머지
{
    class Program
    {
        static void Main(string[] args)
        {
            List<int> numbers = new List<int>();

            List<int> answer = new List<int>();

            for(int i=0; i<10; i++)
            {
                numbers.Add(int.Parse(Console.ReadLine()) % 42);
            }
            for (int i=0; i < numbers.Count-1; i++)
            {
                for (int j=i+1; j<numbers.Count; j++)
                {
                    if (numbers[i] == numbers[j])
                    {
                        continue;
                    }
                    else // 동일한 값이 아니라면
                    {
                        if (!answer.Contains(numbers[i]))
                        {
                            answer.Add(numbers[i]);
                        }
                    }
                }
            }
            if (!answer.Contains(numbers[^1]))
            {
                answer.Add(numbers[^1]);
            }
            Console.WriteLine(answer.Count);
        }
    }
}