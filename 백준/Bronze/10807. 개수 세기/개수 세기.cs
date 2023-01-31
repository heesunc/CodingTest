using System;
using System.Linq;

namespace codingstudy
{
    class Program
    {
        static void Main()
        {
            // 정수의 개수
            int n = int.Parse(Console.ReadLine());

            // 정수 배열
            string [] num = Console.ReadLine().Split();

            // 찾으려는 정수
            string v = Console.ReadLine();

            // 찾기, 해당조건을 만족하는 모든 값 리스트로 반환한거의 길이
            int result = Array.FindAll(num, x => x==v).Length;
            
            Console.WriteLine(result);
        }
    }
}