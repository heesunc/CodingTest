using System;

namespace codingstudy
{
    class Program
    {
        static void Main()
        {
            // 영수증에 적힌 총 금액 입력
            int total = int.Parse(Console.ReadLine());
            // 영수증에 적힌 구매한 물건의 종류의 수 N
            int n = int.Parse(Console.ReadLine());
            // 금액 맞는 지 비교할 int 
            int comp = 0;

            // n만큼 개수와 가격을 입력할 수 있도록 작성
            for (int i=0; i< n; i++)
            {
                // 개수와 가격 입력
                int[] pro = Array.ConvertAll(Console.ReadLine().Split(),int.Parse);
                // 계산
                comp += pro[0] * pro[1];
            }

            // 개수와 가격이 일치하면 Yes, 않으면 No
            if (total == comp)
                {
                    Console.WriteLine("Yes");
                }
                else
                {
                    Console.WriteLine("No");
                }   
        }
    }
}