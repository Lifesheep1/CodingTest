class Solution {
    public int solution(int[] numbers) {
        int answer = 45; // 0부터 9까지 합
        for(int num : numbers){ // numbers배열에 있는 값들을 answer에서 뺌
            answer -= num;
        }
        return answer; 
    }
}