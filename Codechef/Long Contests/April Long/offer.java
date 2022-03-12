
import java.util.*;
import java.lang.*;
import java.io.*;

class Solve
{
	public static long solve(long[][] dp, long k, long index, long curr) {
        long len = dp[0].length;
        if (k == 1) return (curr & dp[(int)(len - index - 1)][(int)index]);
        long answer = 0;
        for (int i= 1; i <= len - index - k + 1; ++i) {
            long now = curr & dp[(int)(i - 1)][(int)index];
            if (now == 0)
                continue;
            answer = Math.max(answer, solve(dp, k - 1, index + i, now));
        }
        return answer;
	}

	public static void main (String[] args)
	{
        Scanner sc = new Scanner(System.in);

        int n=sc.nextInt();

        long[] arr=new long[n];

        for (int i=0;i<n;++i){
            arr[i]=sc.nextLong();
        }
        int tc=sc.nextInt();
        while (tc>0){
            long k;
            k=sc.nextLong();
            long[] t=new long[n];
            ArrayList<Long> v = new ArrayList<Long>();
            for (int i=0; i<n; i++){
                t[i]=sc.nextLong();
                t[i]=t[i]*arr[i];
                if (t[i]!=0) v.add(t[i]);
            }

            int len = v.size();
            if (k > len) {
                System.out.println(0);
                continue;
            }

            long[] array=new long[len];
            for (int i=0;i<len;i++)
                array[i]=v.get(i);


            long[][] dp = new long[(int)(len - k + 1)][];
            dp[0] = array;
            for (int i = 1; i < dp.length; i++) {
                dp[i] = new long[(int)(len - i)];
                for (int j = 0; j < dp[i].length; j++) {
                    dp[i][j] = dp[i - 1][j + 1] + dp[0][j];
                }
            }
            System.out.println(solve(dp, k, 0, Integer.MAX_VALUE));
            tc--;
        }
	}
}
