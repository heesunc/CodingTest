using System;

public class bj2739
{
    public static void Main(string[] args)
    {
        int n = int.Parse(Console.ReadLine());
        
        for (int i=1; i <= 9; i++){
            Console.WriteLine($"{n} * {i} = {n * i}");
        }
    }
}