import java.util.Arrays;

class Solution {
    public int[] solution(int[] num_list) {
        int[] answer;
        if (num_list[num_list.length-1] > num_list[num_list.length-2]){
            answer = Arrays.copyOf(num_list, num_list.length+1);
            answer[answer.length - 1] = num_list[num_list.length-1] - num_list[num_list.length-2];
        }else {
            answer = Arrays.copyOf(num_list, num_list.length+1);
            answer[answer.length - 1] = num_list[num_list.length - 1] * 2;
        }
        return answer;
    }
}