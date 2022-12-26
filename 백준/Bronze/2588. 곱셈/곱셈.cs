using System;

namespace codingstudy
{
    class Program
    {
        static void Main(string[] args)
        {
            string a = Console.ReadLine(); // 1번째 줄
            string b = Console.ReadLine(); // 2번째 줄
            char[] c = b.ToCharArray(); // b의 n의 자리를 구하기 위해 배열로 저장
        
            int num1 = int.Parse(a);
            // 입력된 a를 int로 변환하여 num1로 저장
            int[] num2 = new int[c.Length];
            // c의 길이만큼의 int배열인 num2를 저장
    
            for (int i = 0; i < c.Length; i++)
            {
                num2[i] = int.Parse(c[i].ToString());
                // c배열에 있는 char를 string으로 쓰고 그걸 int로 바꿈 -> num2[i]에 저장
            }
    
            Console.WriteLine(num1 * num2[2]); //3번째 줄
            Console.WriteLine(num1 * num2[1]); //4번째 줄
            Console.WriteLine(num1 * num2[0]); //5번째 줄
            Console.WriteLine(num1 * num2[2]
                            + num1 * num2[1] * 10
                            + num1 * num2[0] * 100); //6번째 줄
        }
    }
}