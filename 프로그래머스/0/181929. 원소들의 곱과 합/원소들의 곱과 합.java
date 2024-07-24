class Solution {
    public int solution(int[] num_list) {
        int answer = 0;
        int result1 = 1;
        int result2 = 0;
        for(int i=0; i<num_list.length; i++){
            result1 *= num_list[i];
            result2 += num_list[i];
        }
        if (result1 < result2*result2){
            answer = 1;
        }
        return answer;
    }
}