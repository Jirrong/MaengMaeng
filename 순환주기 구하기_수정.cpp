#include <iostream>
#include <cstdlib>
using namespace std;


int main()
{
	int N, rmdidx = -1, *rmds, *res, now = 1, i, j = 1, *check;
	int length, length1 = 0;
	
	cin >> now >> N;
	
	rmds = (int *)calloc(sizeof(int), N);                         // int���� N�� �ִ� �迭�� �����Ҵ��Ѵ�. (rmds : ���� ������������ ������ ����, res = ���� ������������ �� ����, check =  
	res = (int *)calloc(sizeof(int), N);
	check = (int *)calloc(sizeof(int), N);
	
	for (i = 0; now; now *= 10)                                   // i=0�̶� �ϰ� ��� now (����)�� 10�� ���ذ��鼭 
	{
		res[i] = now / N;                                         // res[i]�� ���ڸ� �и�� ���� �� (�ڿ��� �κ�)���� �Ѵ�. 
		rmds[i] = (now %= N);                                     // ���ڿ�  ���ڸ� �и�� ���� �������� �����ϰ�, �� ������ ������ rmds[i]�� ����ִ´�.  (��м��� ���� �κ�) 
		
		if (check[now])                                           // check[now]�� 0�� �ƴϸ� (��, 1�� �߰��� check[now]�� �ٽ� �����Ѵٸ� => �������� ���ٸ� => ��ȯ���� �� �� �����Ѵٸ� 
		{
			rmdidx = check[now];                                  // rmdidx (1 + ���ȯ�ֱ��� ����)�� �ݺ��� ���� ó�� ��Ÿ���� ���� check[now]�� �����Ѵ�.
			break;                                                // ��ȯ�ֱ⸦ ã�� ���� �ݺ��� �ߴ��Ѵ�. 
		} else {
			check[now] = ++i;                                     // check[now]�� 1 ������ i (���� ���� �� ����)�̴� => i, �� ���ȯ�ֱ�� ��ȯ�ֱ� �� 1�ֱ������ ����.
		}
	}
	
	cout << "0.";
	for(++i; j < i; j++)                                          // j < i�� ������ (j = i-1�� ������) j�� ������Ų��. (��ȯ�ֱ��� ���� �� ������) 
	{
		if (j == rmdidx)                                          // j�� ���ȯ�ֱ��� ���� �����ߴٸ� 
		{
			cout << "|";                                          // ��ȯ�ֱ��� ������ �˸���. 
		}
		cout << res[j]; 
		length++;                                                 // j��° ���� ����Ѵ�.
	}
	if (rmdidx >= 0) cout << "|" << "\n";                         // ���ѼҼ��� �ƴ϶�� (�ٽ� ���� �ݺ��Ǵ� �κ��� �����Ѵٸ�) �����Ѵٸ� �������� ��ȯ�ֱ��� ���� �˸���. 
	cout << "��ȯ�ֱ��� ���̴� " << length - rmdidx + 1;
	return 0;
}
