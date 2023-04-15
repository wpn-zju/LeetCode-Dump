public class Solution {
    public string[] UncommonFromSentences(string A, string B) {
        List<string> result = new List<string>();
        A = A + ' ' + B;
        string[] strsa = A.Split(' ');
        Dictionary<string, int> dic = new Dictionary<string, int>();
        foreach(string str in strsa)
            if(!dic.ContainsKey(str))
                dic.Add(str, 1);
            else
                dic[str]++;
        foreach(KeyValuePair<string, int> kvp in dic)
            if(kvp.Value == 1)
                result.Add(kvp.Key);
        return result.ToArray();
    }
}