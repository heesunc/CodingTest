using System;

namespace codingstudy
{
    class Program
    {
        static void Main(string[] args)
        {
            int[] cs = {1,1,2,2,2,8}; // 킹,퀸,룩,비숍,나이트,폰
            string[] input = Console.ReadLine().Split();

            for (int i=0; i<cs.Length; i++)
            {
                cs[i]-=int.Parse(input[i]);
            }
            foreach (int j in cs)
            {
                Console.Write(j.ToString()+" ");
            }  
        }
    }
}