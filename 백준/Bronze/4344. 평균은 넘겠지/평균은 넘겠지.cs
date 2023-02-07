using System;

namespace codingstudy
{
    class Program
    {
        static void Main()
        {
            int c = int.Parse(Console.ReadLine());

            int[] scores;
            double avg;
            int cnt;

            for (int i = 0; i < c; i++)
            {
                scores = Array.ConvertAll(Console.ReadLine().Split(), int.Parse);
                avg = 0;
                cnt = 0;
                for (int j = 1; j < scores.Length; j++)
                {
                    avg += scores[j];
                }
                avg /= scores.Length - 1;
                for (int j = 1; j < scores.Length; j++)
                {
                    if (scores[j] > avg)
                    {
                        cnt++;
                    }
                }
                Console.WriteLine("{0:F3}%", (double)cnt / (scores.Length - 1) * 100);
            }
        }
    }
}
