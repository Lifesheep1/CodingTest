import java.util.stream.Stream;

class Solution {
    public int[] solution(long n) {
        int[] answer = Stream.of(String.valueOf(n).split(""))
                .mapToInt(Integer::parseInt)
                .toArray();
        int[] result = new int[answer.length];
        for (int i = 0; i< answer.length; i++){
            result[i] = answer[answer.length-i-1];
        }
        return result;
    }
}