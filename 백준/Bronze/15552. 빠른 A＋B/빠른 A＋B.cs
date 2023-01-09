using System;
using System.Text;

namespace codingstudy
{
    class Program
    {
        static void Main()
        {
            StringBuilder sb = new StringBuilder();
            // Text안에 있는 StringBuilder 선언

            int t = int.Parse(Console.ReadLine());
            // for문 돌리기 위해서 몇 개의 테스트 케이스할건지 적는 곳

            for (int i = 0; i < t; i++)
            {
                string[] num = Console.ReadLine().Split();
                sb.Append(int.Parse(num[0]) + int.Parse(num[1]) + "\n");
                // 스트링빌더로 num[0]과 num[1]의 값의 합을 구함
            }
            Console.WriteLine(sb.ToString());
        }
    }
}