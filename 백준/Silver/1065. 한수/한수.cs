using System;
using static System.Console;

namespace baekioon
{
    class MainApp
    {
        static void Main()
        {
            // true값일때 올라갈 count 변수
            int count = 0;

            // n개 입력
            int n = int.Parse(ReadLine());

            for (int i = 1; i <= n; i++)
            {
                if (hansu(i.ToString())) count++;
            }

            WriteLine(count);
        }

        // 등차수열, 한수를 판단할 메소드
        // - 그 값이 등차면 true
        // - 아디면 false 
        // - bool 값으로 선언
        static bool hansu(string num)
        {
            // 2자리수 일때는 무조건 등차수열
            if (int.Parse(num) < 100) return true;

            // 3자리수 판단
            // - diigits변수는 num의 길이만큼 크기를 가짐
            int[] digits = new int[num.Length];

            // 각 자리수를 digits값에 넣어줌
            for (int i = 0; i < num.Length; i++)
            {
                digits[i] = num[i];
            }

            // 등차수열 판단
            // - 등차수열이라면 첫째수 둘째수의 차이와 둘째수 셋째수의 차이가 같아야함
            if ((digits[0] - digits[1]) == digits[1] - digits[2])
            {
                return true;
            }
            else
                return false;
        }
    }
}