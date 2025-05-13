import java.util.Arrays;

public class Solution {
    public int[] solution(int []arr) {
        int[] answer = new int[arr.length]; // 최대 arr.length 크기로 미리 할당
        int write = 0; // 값을 쓸 위치를 가리킬 포인터
        
        for(int i = 0; i < arr.length; i++){ // i == 0이거나 이전값과 다를때만 저장
            if(i == 0 || arr[i] != arr[i - 1]){
                answer[write++] = arr[i];
            }
        }
        
        return Arrays.copyOf(answer, write);
    }
}