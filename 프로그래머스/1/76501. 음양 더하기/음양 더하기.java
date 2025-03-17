class Solution {
    public int solution(int[] absolutes, boolean[] signs) {
        int answer = 0;
        //absolutes의 길이만큼 반복을 먼저하고 그안에서 signs이 붙은 자리는 -를 붙여주고 absolutes를 다 더함
        for(int i = 0; i < absolutes.length; i++){
            if(signs[i] == false){
                absolutes[i] = (absolutes[i] * -1);  
            }
            answer += absolutes[i];
        }
        return answer;
    }
}