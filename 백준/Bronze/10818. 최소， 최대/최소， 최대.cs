namespace 백준10818번
{
    class Program
    {
        static void Main(string[] args)
        {
            // 입력 받음
            int n = int.Parse(Console.ReadLine());
            // 입력받은 숫자 길이만큼의 배열을 생성
            int[] arr = new int [n];
            // 두번째로 입력받는 숫자들을 공백기준으로 잘라서 배열로 저장
            string[] s = Console.ReadLine().Split();
            // int로 바꿔서 저장
            for (int i=0; i<n; i++)
            {
                arr[i] = int.Parse(s[i]);
            }
            // 배열을 정렬
            Array.Sort(arr);
            // 배열의 맨앞과 맨 뒤 출력
            Console.WriteLine($"{arr[0]} {arr[n-1]}");
        }
    }
}