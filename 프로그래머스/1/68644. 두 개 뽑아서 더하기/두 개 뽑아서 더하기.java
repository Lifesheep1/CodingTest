import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

class Solution {
    public int[] solution(int[] numbers) {
        //결과를 담을 list 생성
        List<Integer> list = new ArrayList<>();
        //numbers 순회하며 선번째 숫자 선택
        for (int i= 0; i< numbers.length; i++){
            //첫번째 숫자 이후 숫자부터 numbers 순회
            for (int j = i+1; j< numbers.length; j++){
                int num = numbers[i] + numbers[j];
                //결과를 담을 list에 없다면
                if(!list.contains(num)){
                    //list에 추가
                    list.add(num);
                }
            }
        }
        Collections.sort(list);
        //list convert to array
        //return array;
        return list.stream().mapToInt(Integer::intValue).toArray();
    }
}