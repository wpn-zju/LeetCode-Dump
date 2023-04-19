class Solution {
    public double[] sampleStats(int[] count) {
        double[] result = new double[5];
        int ptr = 0;
        // Min
        while (count[ptr] == 0)
            ptr++;
        result[0] = ptr;

        // Max
        ptr = 255;
        while (count[ptr] == 0)
            ptr--;
        result[1] = ptr;

        // Ave
        long sum = 0;
        int countNum = 0;
        for (int i = 0; i < 256; ++i)
        {
            countNum += count[i];
            sum += i * count[i];
        }
        result[2] = sum / (double)countNum;

        // Med
        ptr = 0;
        int midNum = countNum / 2;
        while (midNum > count[ptr])
        {
            midNum -= count[ptr];
            ptr++;
        }
        if (countNum % 2 == 1 || midNum < count[ptr])
            result[3] = ptr;
        else
        {
            int tmp = ptr;
            while (count[++ptr] == 0) ;
            result[3] = ((double)tmp + ptr) / 2;
        }

        // Mod
        int max = 0;
        int mode = 0;
        for(int i = 0; i < 256; ++i)
        {
            if (count[i] > max)
            {
                max = count[i];
                mode = i;
            }
        }
        result[4] = mode;

        return result;
    }
}