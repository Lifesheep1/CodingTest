import java.util.*;

class Solution {
    public String solution(String[] participant, String[] completion) {
        // 참가자 이름별 등장 횟수 카운트
        Map<String, Integer> countMap = new HashMap<>();
        for(String p : participant) {
            countMap.put(p, countMap.getOrDefault(p,0) + 1);
        }
        //완주자 이름별로 카운트 1씩 감소
        for(String c : completion) {
            countMap.put(c,countMap.get(c) - 1);
        }
        //여전히 카운트가 1 이상인 사람이 미완주자
        for(String p : participant) {
            if(countMap.get(p) > 0) {
                return p;
            }
        }
        
        return "";
    }
}