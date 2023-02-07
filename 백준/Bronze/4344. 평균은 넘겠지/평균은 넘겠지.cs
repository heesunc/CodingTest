using System;

namespace codingstudy
{
    class Program
    {
        static void Main()
        {
            int c = int.Parse(Console.ReadLine()); // 테스트 케이스

            int[] scores;
            double avg;
            int cnt;

            while (c --> 0)
            {
                // 첫번째 요소를 제외한 나머지 문자열들을 배열로 추출
                scores = Array.ConvertAll(Console.ReadLine().Split()[1..],int.Parse);
                // Average() 메서드로 배열의 평균 구하기
                avg = scores.Average();
                // Count() 메서드로 배열의 건수 구하기
                // 람다식으로 scores배열에서 개별 점수가 평균보다 높은 것의 개수를 구해 Count를 호출
                // cnt에는 scores 배열에서 평균보다 높은 점수의 개수가 저장됨 
                cnt = scores.Count(score => score > avg);

                Console.WriteLine("{0:F3}%",(double)cnt / scores.Length*100);
            }
        }
    }
}