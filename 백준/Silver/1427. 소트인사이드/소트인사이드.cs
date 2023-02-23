using System;
using System.Linq;

public class Sample
{
    public static void Main()
    {
        // Array.Sort() : 오름차순으로 배열을 정렬
        // 내림차순으로 정렬하는 메서드는 없으므로 Sort() 호출 후 Reverse() 메서드를 사용

        // string str = Console.ReadLine();
        // int[] arr = new int[str.Length]; // str길이만큼의 int배열 만들어줌
        // string result="";

        // for (int i = 0; i < str.Length; i++)
        // {
        //     // 문자열 하나씩 잘라서 arr 배열에 저장
        //     arr[i] = int.Parse(str.Substring(i,1));
        // }
        // Array.Sort(arr); // 오름차순 정렬
        // Array.Reverse(arr); // 내림차순 정렬

        // for (int i = 0; i < str.Length; i++)
        // {
        //     result += arr[i].ToString();
        // }
        // Console.WriteLine(result);

        string input = Console.ReadLine();

        // if (!int.TryParse(input, out int _))
        // {
        //     Console.WriteLine("Invalid input.");
        //     return;
        // }

        int[] arr = input.Select(c => int.Parse(c.ToString())).ToArray();
        Array.Sort(arr);
        Array.Reverse(arr);

        Console.WriteLine(string.Join("", arr));
    }
}