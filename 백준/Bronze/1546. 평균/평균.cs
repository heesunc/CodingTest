using System;

namespace 백준1546번_평균
{
    class Program
    {
        static void Main(string[] args)
        {
            int n = int.Parse(Console.ReadLine());

            string[] s = Console.ReadLine().Split();
            float[] score = Array.ConvertAll(s, float.Parse);

            float max = float.MinValue;

            for (int i = 0; i<n; i++)
            {
                if(score[i] > max)
                {
                    max = score[i];
                }
            }

            float sum = 0.0f;
            for (int i=0; i<n; i++)
            {
                score[i] = score[i]/max*100;
                sum += score[i];
            }

            Console.WriteLine("{0:0.00####}", sum/n);
        }
    }
}
