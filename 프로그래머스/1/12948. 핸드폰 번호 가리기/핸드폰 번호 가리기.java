class Solution {
    public String solution(String number) {
        int len = number.length(); // 전체 길이
        int star = len -4; // *로 바꿀 개수
        String stars = "*".repeat(star); // "*"을 star만큼 반복
        String l = number.substring(star); // 마지막 4자리
        return stars + l;
    }
}