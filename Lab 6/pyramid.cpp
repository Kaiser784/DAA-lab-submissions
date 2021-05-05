#include<bits/stdc++.h>
using namespace std;

int maxLevel(int *boxes, int num)
{
	sort(boxes, boxes + num);

	int ans = 1;
	int prev = boxes[0];
	int prev_count = 1;

	int curr_count = 0;

	int curr = 0;
	for (int i=1; i<num; i++)
	{
		curr += boxes[i];
		curr_count += 1;

		if (curr > prev && curr_count > prev_count)
		{
			prev = curr;
			prev_count = curr_count;

			curr_count = 0;
			curr = 0;
			ans++;
		}
	}
	return ans;
}

int main()
{
	int boxes[] = {10, 20, 30, 50, 60, 70};

	int num = sizeof(boxes)/sizeof(boxes[0]);
	cout<<maxLevel(boxes, num)<<"\n";
	return 0;
}