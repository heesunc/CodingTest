using System;

class Program
{
    static void Main(string[] args)
    {
        bool[] isSelfNum = new bool[10001];

        for (int i = 1; i < 10001; i++)
        {
            int d = i + getDigitSum(i);
            if (d <= 10000) isSelfNum[d] = true;
        }

        for (int i = 1; i < 10001; i++)
        {
            if (!isSelfNum[i]) Console.WriteLine(i);
        }
    }

    static int getDigitSum(int n)
    {
        int sum = 0;
        while (n > 0)
        {
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }
}
