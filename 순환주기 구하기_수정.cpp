#include <iostream>
#include <cstdlib>
using namespace std;


int main()
{
	int N, rmdidx = -1, *rmds, *res, now = 1, i, j = 1, *check;
	int length, length1 = 0;
	
	cin >> now >> N;
	
	rmds = (int *)calloc(sizeof(int), N);                         // int형이 N개 있는 배열을 동적할당한다. (rmds : 세로 나눗셈에서의 나머지 집합, res = 세로 나눗셈에서의 몫 집합, check =  
	res = (int *)calloc(sizeof(int), N);
	check = (int *)calloc(sizeof(int), N);
	
	for (i = 0; now; now *= 10)                                   // i=0이라 하고 계속 now (분자)에 10을 곱해가면서 
	{
		res[i] = now / N;                                         // res[i]를 분자를 분모로 나눈 몫 (자연수 부분)으로 한다. 
		rmds[i] = (now %= N);                                     // 분자에  분자를 분모로 나눈 나머지를 대입하고, 이 나머지 값들을 rmds[i]에 집어넣는다.  (대분수의 분자 부분) 
		
		if (check[now])                                           // check[now]가 0이 아니면 (즉, 1을 추가한 check[now]가 다시 등장한다면 => 나머지가 같다면 => 순환마디가 한 번 돔장한다면 
		{
			rmdidx = check[now];                                  // rmdidx (1 + 비순환주기의 길이)에 반복된 수가 처음 나타나는 지점 check[now]를 대입한다.
			break;                                                // 순환주기를 찾기 위한 반복을 중단한다. 
		} else {
			check[now] = ++i;                                     // check[now]는 1 증가된 i (먼저 증가 후 대입)이다 => i, 즉 비순환주기와 순환주기 제 1주기까지의 개수.
		}
	}
	
	cout << "0.";
	for(++i; j < i; j++)                                          // j < i일 때까지 (j = i-1일 때까지) j를 증가시킨다. (순환주기의 끝이 될 때까지) 
	{
		if (j == rmdidx)                                          // j가 비순환주기의 끝에 도달했다면 
		{
			cout << "|";                                          // 순환주기의 시작을 알린다. 
		}
		cout << res[j]; 
		length++;                                                 // j번째 몫을 출력한다.
	}
	if (rmdidx >= 0) cout << "|" << "\n";                         // 유한소수가 아니라면 (다시 말해 반복되는 부분이 존재한다면) 존재한다면 마지막에 순환주기의 끝을 알린다. 
	cout << "순환주기의 길이는 " << length - rmdidx + 1;
	return 0;
}
