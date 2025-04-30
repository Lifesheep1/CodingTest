class Solution {
    public boolean solution(String s) {
        if(s.length() != 4 && s.length() != 6) return false;
        char [] chars = s.toCharArray(); // char배열로 변환
        for(char c : chars){
        // 아스키코드로 판단
            if(c < '0' || c> '9') return false;
        }
        return true;
    }
}