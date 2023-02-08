using System;
using System.IO;
using System.Text;
 
 
class Program {
 
    //함수 d(n)을 정의해보고 공식을 만들어보자.
    //역으로 생성자를 확인하는 함수를 만들수 있는지 확인해보자.
 
    //만약 생성자를 역추적하여 확인할수 있다면
    //생성자 확인이 불가능할때까지 역으로 돌린 뒤 숫자를 출력한다.
    //while문으로 돌려보자.
 
    //문제 설명에 나온 함수 d(n)
    static int Creater(string num)
    {
        int result = int.Parse(num);
        for (int i = 0; i < num.Length; i++)
        {
            result += int.Parse(num[i].ToString());
        }
 
        return result;
    }
 
    static void Main()
    {
        //생각해보니 역으로 생성자가 누구인지 확인하기 어렵다.
        //그냥 10000줄의 수를 stringBuilder에 집어넣고
        //함수 d(n)에서 나온 수를 다 제거하여 남은 수만 출력하면
        //10000보다 작거나 같은 셀프넘버만 남게된다.
 
        //생성자로 인해 생성된 값을 받습니다.
        int[] created_Values = new int[10000];
        for (int i = 0; i < 10000; i++)
        {
            created_Values[i] = Creater(i.ToString());
        }
 
        //셀프넘버값을 받을 스트링빌더를 생성합니다.
        StringBuilder selfNumber = new StringBuilder();
 
        //반복문을 돌면서 각 값을 created_Values[](생성된값)와 비교하며 문자열을 채웁니다.
        bool isSelfNumber = true;
        for (int i = 0; i < 10001; i++)
        {
            for (int j = 0; j < created_Values.Length; j++)
            {
                if(i == created_Values[j])
                {
                    isSelfNumber = false;
                    break;
                }
                else
                {
                    isSelfNumber = true;
                }
            }
 
            if (isSelfNumber) selfNumber.AppendLine(i.ToString());
        }
 
        //마지막까지 채워진 SelfNumber문자열을 출력합니다
        Console.WriteLine(selfNumber);
    }
}