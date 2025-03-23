//홀수라면 가운데 한글자 반환
//짝수라면 가운데 두글자 반환
// int mid = s.length() / 2; <- 가운데 인덱스
//홀수라면 s[mid], 짝수라면 s[mid-1] + [mid]
class Solution {
    public String solution(String s) {
        int len = s.length();
        int mid = len / 2;
        
        if(len % 2 == 0) { // 길이가 짝수일때
            return s.substring(mid - 1, mid + 1);
        }else { // 길이가 홀수일 때
            return s.substring(mid, mid + 1);
        }
    }
}