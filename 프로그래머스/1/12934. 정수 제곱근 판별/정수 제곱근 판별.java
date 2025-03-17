class Solution {
    public long solution(long n) {
        long x = (long) Math.sqrt(n); // n의 제곱근을 구하고 long으로 반환, n이 5와 같은게 들어올경우는 long에 의해 소수점이 버려짐
        
        if( x * x == n){ // x의 제곱이 n과 같다면
            return (long) Math.pow(x + 1, 2); // (x+1)의 제곱을 리턴함
        } else {
            return -1; // 제곱수가 아니라면 -1 리턴
        }
    }
}