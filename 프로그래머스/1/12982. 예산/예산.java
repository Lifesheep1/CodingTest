import java.util.*;

class Solution {
    public int solution(int[] d, int budget) {
        Arrays.sort(d);
        int sum = 0;
        int count = 0;
        for(int i : d){
            if(sum + i > budget){
                break;
            }
            sum += i;
            count++;
        }
        return count;
    }
}