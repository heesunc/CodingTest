using System;

public class bj2525
{
    public static void Main(string[] args)
    {
        string[] htime = Console.ReadLine().Split();
        
        int h = int.Parse(htime[0]);
        int m = int.Parse(htime[1]);
        int c = int.Parse(Console.ReadLine());
        
        m+=c;
        
        if (m>=60){
            while(m>=60){
                m-=60;
                h++;
                if (h>=24){
                    h=0;
                }
            }
        }
        Console.WriteLine($"{h} {m}");
    }
}