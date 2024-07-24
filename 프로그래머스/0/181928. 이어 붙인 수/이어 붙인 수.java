class Solution {
    public int solution(int[] num_list) {
        int answer = 0;
        String odd = "";
        String even = "";
        for (int i = 0; i<num_list.length; i++){
            if(num_list[i] % 2 == 1){
                odd += num_list[i];
            }
            if (num_list[i] % 2 == 0){
                even += num_list[i];
            }
        }
        // System.out.println("Odd numbers (ex): " + odd);
        // System.out.println("Even numbers (tm): " + even);
        answer = Integer.parseInt(odd) + Integer.parseInt(even);
        return answer;
    }
}