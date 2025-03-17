// 이 문제는 정렬을 쓰면 안될것같음 -> 리턴 배열에 정렬조건이 없기때문 따라서 포문으로 크기비교를해야할것같음
class Solution {
    public int[] solution(int[] arr) {
        // 배열이 1개뿐이면 [-1] 반환
        if(arr.length == 1) return new int[]{-1};
        
        int min = arr[0]; // 첫번째값을 최소값으로 설정
        for(int i = 0; i < arr.length; i++){
            if(arr[i] < min){
                min = arr[i]; // 더 작은 값 나오면 갱신
            }
        }
        
        int [] answer = new int[arr.length - 1];
        int index = 0;
        for(int i = 0; i < arr.length; i++){
            if(arr[i] != min){ // 최소값 아닐때 추가
                answer[index++] = arr[i];
            }
        }
        return answer;
    }
}