import java.util.*;

class Solution {
    public String solution(String s) {
        char[] charArray = s.toCharArray(); // 문자열을 문자 배열로 변환
        Arrays.sort(charArray); // 문자 배열 정렬
        StringBuilder sb = new StringBuilder(new String(charArray)); // 문자 배열을 문자열로 변환 후 
        return sb.reverse().toString(); // 내림차순으로 정렬 반환
    }
}