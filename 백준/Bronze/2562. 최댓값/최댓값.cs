using System;

namespace 백준2562번
{
    class Program
    {
        static void Main(string[] args)
        {
            // 9개의 숫자가 주어지므로 길이 9의 배열 생성
            int[] arr = new int[9];
            // 최대값을 저장할 변수
            int max = 0;
            // 배열번호를 저장할 변수
            int num = 0;

            // 숫자를 배열에 입력
            for (int i=0; i<9; i++)
            {
                arr[i] = int.Parse(Console.ReadLine());
            }

            // 최대값 찾기
            for (int i=0; i<arr.Length; i++)
            {
                if (arr[i] > max)
                {
                    // 현재값이 max보다 크면, max에 저장하고 인덱스번호도 저장
                    max = arr[i];
                    // 배열번호에 +1을 해줘야 입력된 순서의 번호가 된다.
                    num = i+1;
                }
            }          
            // 최댓값 출력
            Console.WriteLine(max);
            // 최댓값이 몇 번째 수인지 출력
            Console.WriteLine(num);
        }
    }
}
