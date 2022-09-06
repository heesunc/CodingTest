using System;
using static System.Console;

namespace _1차원배열6
{
    class OX퀴즈
    {
        static void Main(string[] args)
        {
            // t 입력 받음
            int t = int.Parse(ReadLine());

            // 연속으로 몇번 맞추고 있는지를 저장하기 위한 combo 선언
            int combo = 0;
            // 점수 저장
            int score = 0;
            
            // t만큼 for문을 돌림
            for (int i = 0; i < t; i++)
            {
            // 값을 입력받음
                string s = ReadLine();

                for (int j = 0; j < s.Length; j++)
                {
                // 만약 해당 글자가 O라면,
                    if (s[j] == 'O')
                    {
                        // 콤보를 증가시킴
                        ++combo;
                        // 스코어에 콤보를 더해줌.
                        score += combo;
                    }
                    else
                    {
                    // 콤보를 0으로 만든다.
                        combo = 0;
                    }
                }
                // 계산값 출력
                WriteLine(score);
                // 다음번 반복을 위해서 콤보와 스코어를 0으로 바꿔줌
                combo = 0;
                score = 0;
            }
        }
    }
}