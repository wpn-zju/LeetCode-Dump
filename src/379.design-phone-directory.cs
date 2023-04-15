public class PhoneDirectory {
        private Dictionary<int, bool> dir = new Dictionary<int, bool>();
        /** Initialize your data structure here
            @param maxNumbers - The maximum numbers that can be stored in the phone directory. */
        public PhoneDirectory(int maxNumbers)
        {
            for (int i = 0; i < maxNumbers; ++i)
                dir[i] = false;
        }

        /** Provide a number which is not assigned to anyone.
            @return - Return an available number. Return -1 if none is available. */
        public int Get()
        {
            foreach(KeyValuePair<int, bool> kvp in dir)
                if (!kvp.Value)
                {
                    dir[kvp.Key] = true;
                    return kvp.Key;
                }
            return -1;
        }

        /** Check if a number is available or not. */
        public bool Check(int number)
        {
            return dir.ContainsKey(number) && !dir[number];
        }

        /** Recycle or release a number. */
        public void Release(int number)
        {
            if (dir.ContainsKey(number))
                dir[number] = false;
        }
}

/**
 * Your PhoneDirectory object will be instantiated and called as such:
 * PhoneDirectory obj = new PhoneDirectory(maxNumbers);
 * int param_1 = obj.Get();
 * bool param_2 = obj.Check(number);
 * obj.Release(number);
 */