import java.util.*;

class Solution {
    public int[] solution(int N, int[] stages) {
        //스테이지마다 도달한 유저의 수를 저장할 공간 생성
        //인덱스와 스테이지 기준을 맞추기 위해서 N+1, 모든 스테이지를 통과한 유저를 저장하기 위해 N+1
        //총 N+2의 배열이 필요합니다.
        int[] stageCounts = new int[N+2];
        //배열안에 도달한 유저를 저장 -> stages를 순회하며 stageCounts에 할당
        for (int stage : stages){
            stageCounts[stage]++;
        }

        //실패율 계산 해야함
        //실패율을 저장할 공간 생성
        List<Stage> failureRates = new ArrayList<>();

        //실패율을 계산하기 위해 분모로 올 사용자의 수를 저장할 변수 선언
        int playerReached = stages.length;

        //각 스테이지별 실패율 계산해서 저장
        for (int i = 1; i <= N; i++){
            if (stageCounts[i] == 0){
                failureRates.add(new Stage(i,0));
            }else {
                double rate = (double) stageCounts[i] / playerReached;
                failureRates.add(new Stage(i,rate));
            }
            playerReached -= stageCounts[i];
        }
        //이제 정렬 해야지
        Collections.sort(failureRates, (a,b)->{
            if(a.failureRate == b.failureRate){
                return a.stage - b.stage;
            }else {
                return Double.compare(b.failureRate, a.failureRate);
            }
        });

        return failureRates.stream().mapToInt(stage -> stage.stage).toArray();
    }

    //스테이지와 실패율을 관리하는 클래스
    private static class Stage{
        int stage;
        double failureRate;

        Stage(int stage, double failureRate){
            this.stage = stage;
            this.failureRate = failureRate;
        }
    }
}