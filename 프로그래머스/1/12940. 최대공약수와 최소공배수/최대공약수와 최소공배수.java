class Solution {
    public int[] solution(int n, int m) {
        int g = gcd(n, m); // 최대공약수
        int l = n * m / g; // 최소공배수
        return new int[] {g, l};
    }
    
    //유클리드 호재법 최대공약수
    private int gcd(int a, int b){
        while(b !=0){
            int r = a % b; // 나머지
            a = b;
            b = r;
        }
        return a;
    }
}