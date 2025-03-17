import java.util.Arrays;

public class Solution {
    public long solution(long n) {
        char[] digits = Long.toString(n).toCharArray(); // 숫자를 문자 배열로 변환
        Arrays.sort(digits); // 오름차순 정렬
        StringBuilder sortedNumber = new StringBuilder(new String(digits)).reverse(); // 내림차순 변환
        return Long.parseLong(sortedNumber.toString()); // long타입으로 변환
    }
}