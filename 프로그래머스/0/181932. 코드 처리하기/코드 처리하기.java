class Solution {
    public String solution(String code) {
        String answer = "";
        int mode = 0;
        for (int i =0; i<code.length(); i++){ // for문으로 code인덱스 순회
            if(code.charAt(i) != '1'){// code 가 알파벳일때
                if(mode == 0 && i % 2 == 0){//mode가
                    answer += code.charAt(i);
                }
                else if (mode == 1 && i % 2 ==1){
                    answer += code.charAt(i);
                }
            } else if (code.charAt(i) == '1') {
                if (mode == 0){
                    mode =1;
                } else if (mode == 1) {
                    mode = 0;
                }
            }
        }
        if(answer.isEmpty()){
            return "EMPTY";
        }
        return answer;
    }
}