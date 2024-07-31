import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.stream.Collectors;

class Solution {
    public int[] solution(int n, int[] numlist) {


        List<Integer> intList = new ArrayList<>();

        for (int i = 0; i< numlist.length; i++){
            if (numlist[i] % n == 0){
                intList.add(numlist[i]);
            }
        }
        int[] answer = new int[intList.size()];
        for (int j = 0; j<intList.size(); j++){
            answer[j] = intList.get(j);
        }
        return answer;
    }
}