using System;
using static System.Console;
using System.Text;

namespace for문11
{
    class X보다작은수
    {
        static void Main(string[] args)
        {
        	// s[0]은 수열의 A, s[1]은 정수 X
            string[] s = ReadLine().Split();
            // s[0]을 이루는 수열들
            string[] q = ReadLine().Split();

            StringBuilder answer = new StringBuilder();

            for (int i = 0; i < int.Parse(s[0]); i++)
            {
                // 정수 x보다 작은 숫자들을 검출
                if (int.Parse(s[1]) > int.Parse(q[i]))
                {
                	// 해당 숫자들을 answer에 공백과 함께 추가한다.
                    answer.Append(q[i] + " ");
                }
            }
            // 정답 출력
            WriteLine(answer.ToString());
        }
    }
}