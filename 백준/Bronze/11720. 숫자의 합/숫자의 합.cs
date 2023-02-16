using System;

namespace baekioon
{
    class MainApp
    {
        static void Main()
        {
            // N개의 숫자
            int n = int.Parse(Console.ReadLine());
            // 입력 받은 숫자를 char배열에 저장
            char[] s = Console.ReadLine().ToCharArray();
            int sum = 0;

            for (int i=0; i <s.Length; i++)
            {
                // int로 전환해서 더해줌
                sum += (int)Char.GetNumericValue(s[i]);
            }     
            Console.WriteLine(sum);
        }
    }
}

