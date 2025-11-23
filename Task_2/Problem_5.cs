public class Solution
{
    public int[] DailyTemperatures(int[] temperatures)
    {
        Stack<(int,int)> temps = new();
        int[] ans = new int[temperatures.Length];
        temps.Push((temperatures[0],0));
        for (int i = 0; i < temperatures.Length; i++)
        {
            while (temps.Count > 0 && temperatures[i] > temps.Peek().Item1)
            {
                var idx = temps.Peek().Item2;
                ans[temps.Peek().Item2] = i - idx;
                temps.Pop();
            }
            temps.Push((temperatures[i],i));
            // [73, 74, 75, 71, 69, 72, 76, 73]
        }
        return ans;
    }
}