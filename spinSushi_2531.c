/*
벨트 위에는 같은 종류의 초밥이 둘 이상 있을 수 있다.

1. 벨트의 임의의 한 위치부터 k개의 접시를 연속해서 먹을 경우 할인된 정액 가격으로 제공한다.
2. 각 고객에게 초밥의 종류 하나가 쓰인 쿠폰을 발행하고, 1번 행사에 참가할 경우 이 쿠폰에 적혀진 종류의 초밥 하나를 추가로 무료로 제공한다.
    만약 이 번호에 적혀진 초밥이 현재 벨트 위에 없을 경우, 요리사가 새로 만들어 손님에게 제공한다.

Input
    1st line: 접시의 수 N, 초밥의 가짓수 d, 연속해서 먹는 접시의 수 k, 쿠폰 번호 c
    2 ≤ N ≤ 30,000, 2 ≤ d ≤ 3,000, 2 ≤ k ≤ 3,000 (k ≤ N), 1 ≤ c ≤ d이다.
    2nd line~:두 번째 줄부터 N개의 줄에는 벨트의 한 위치부터 시작하여 회전 방향을 따라갈 때 초밥의 종류를 나타내는 1 이상 d 이하의 정수가 각 줄마다 하나씩 주어진다.

Output
    max num of sushi type one can eat
*/

#include <stdio.h>

#define max(x, y) (x) > (y) ? (x) : (y)

int count_type(int visited[], int d);

int main(){
    int N, d, k, c;
    int sushi[30001];
    scanf("%d %d %d %d",&N, &d, &k, &c);

    int temp;
    for(int loc=0;loc<N;loc++){
        scanf("%d",&temp);
        sushi[loc]=temp;
    }

    int visited[3001] = { 0 };

    visited[c]=1;
    int cnt;
    int ans=-1;

    for(int start=0;start<N;start++){
        for(int loc=start;loc<start+k;loc++){
            visited[sushi[loc%N]]=1;
        }

        cnt = count_type(visited, d+1);
        ans = max(ans,cnt);

        // re-initialize
        for(int i=0;i<d+1;i++){
            visited[i]=0;
        }
        visited[c]=1;
    }
    
    printf("%d",ans);
    return 0;
}

int count_type(int arr[], int d){
    int cnt=0;
    for(int loc=0;loc<d;loc++){
        if(arr[loc]==1) cnt++;
    }

    return cnt;
}