class Solution {
    public boolean solution(int x) {
        int sum = 0;
        String str = Integer.toString(x); // x를 문자열로 변환
        for (int i = 0; i < str.length(); i++) {
            sum += str.charAt(i) - '0'; // 아스키 코드값이므로 '0'을 빼서 정수로 변환
        }
        return x % sum == 0;
    }
}