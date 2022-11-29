using System;
using System.Text;

public class bj2741
{
    public static void Main(string[] args)
    {
        int n = int.Parse(Console.ReadLine());
        StringBuilder allNum = new StringBuilder();
        
        for (int i=1; i <=n; i++)
        {
            allNum.AppendLine(i.ToString());
        }
        Console.WriteLine(allNum);
    }
}