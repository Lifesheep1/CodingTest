class Solution {
    public int solution(int left, int right) {
        int answer = 0;
        
        for(int i = left; i <=right; i++){
            if(Math.sqrt(i) == (int)Math.sqrt(i)){
                answer -= i; // 약수 개수가 홀수면 빼기
            } else {
                answer += i; // 약수 개수가 짝수면 더하기
            }
        }
        
        return answer;
    }
}