class Solution {
    public int solution(String t, String p) {
        int len = p.length();
        int count = 0;
        for(int i = 0; i + len <= t.length(); i++){
            String sub = t.substring(i, i + len);
            long subNum = Long.parseLong(sub);
            long pNum = Long.parseLong(p);
            if(subNum <= pNum) count ++;
        }
        return count;
    }
}