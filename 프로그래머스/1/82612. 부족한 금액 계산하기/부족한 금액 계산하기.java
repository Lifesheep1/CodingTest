class Solution {
    public long solution(int price, int money, int count) {
        long answer = 0;
        long indeed = 0;
        for (int i = 1; i<=count; i++){
            indeed += price * i;
        }
        answer = indeed - money;
        if (answer<=0){
            return 0;
        }

        return answer;
    }
}