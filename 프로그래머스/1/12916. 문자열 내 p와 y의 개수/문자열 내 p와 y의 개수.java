class Solution {
    boolean solution(String s) {
        boolean answer = true;

        int numy = 0;
        int nump = 0;

        for(int i = 0; i<s.length(); i++){
            if(s.charAt(i)== 'y' || s.charAt(i) == 'Y'){
                numy +=1;
            }
            else if(s.charAt(i) == 'p' || s.charAt(i) == 'P'){
                nump +=1;
            }
        }
        if(numy != nump){
            answer = false;
        }

        return answer;
    }
}