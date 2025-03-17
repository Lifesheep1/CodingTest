// seoul 배열의 길이만큼 for문을 돌림
// seoul[i]가 Kim인 i의 인덱스 탐색 그리고 그 i를 answer에 넣어서 반환
class Solution {
    public String solution(String[] seoul) {
        for(int i = 0; i < seoul.length; i++){
            if(seoul[i].equals("Kim")){
                return "김서방은 " + i + "에 있다";
            }
        }
        return ""; // 예외 있을경우에 String 타입 반환해야함, 컴파일러 오류방지
    }
}