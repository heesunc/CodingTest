using System;

public class bj2480
{
    public static void Main(string[] args)
    {
        String[] dice = Console.ReadLine().Split();
        
        int a = int.Parse(dice[0]);
        int b = int.Parse(dice[1]);
        int c = int.Parse(dice[2]);
        
        int money=0;
        
        if (a==b && a==c && b==c){
            money = 10000+a*1000;
        }
        
        else if (a==b){
            money = 1000+a*100;
        }
        
        else if (a==c){
            money = 1000+a*100;
        }
        
        else if (c==b){
            money = 1000+b*100;
        }
        
        else {
            if (a > b && a > c){
                money = 100 * a;
            }
            else if (b > c){
                money = 100 * b;
            }
            else {
                money = 100 * c;
            }
        }
        Console.WriteLine($"{money}");
    }
}