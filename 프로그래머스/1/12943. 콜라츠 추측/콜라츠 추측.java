class Solution {
    public int solution(int num) {
        int answer = 0;
        if(num == 1) return 0; // num이 1일때
        while(num != 1){
            if(answer >= 500) return -1; //500번 넘을때
            
            if(num % 2 == 0){ // 짝수일때
                num = num / 2;
            }
            else if(num % 2 == 1){ // 홀수일때
                num = num*3 +1;
            }
            answer ++;
        }
        return answer;
    }
}