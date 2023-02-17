using System;
using System.Linq;

public class Sample
{
    public static void Main()
    {
        // 알파벳 소문자로 이루어진 단어 S
        string s = Console.ReadLine();
        for (char c = 'a'; c <= 'z'; c++) // 알파벳 a부터 z까지 반복합니다.
        {
            int index = s.IndexOf(c); // 문자열에서 해당 알파벳이 처음으로 나타나는 인덱스를 찾습니다.

            if (index != -1) // 알파벳이 문자열에 포함되어 있으면
            {
                Console.Write(index + " "); // 인덱스를 출력합니다.
            }
            else // 알파벳이 문자열에 포함되어 있지 않으면
            {
                Console.Write("-1 "); // -1을 출력합니다.
            }
        }
    }
}