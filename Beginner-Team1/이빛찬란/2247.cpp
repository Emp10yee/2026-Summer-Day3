#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n,start,end;
	int yes, no;
	cin >> n;
	vector<pair<int, int>> time(n);
	for (int i = 0; i < n; i++) {
		cin >> time[i].first >> time[i].second;
	}

	sort(time.begin(), time.end());
    int maxIn = 0, maxOut = 0;
    int curStart = time[0].first, curEnd = time[0].second;

    for (int i = 1; i < n; i++) {
        if (time[i].first <= curEnd) {
            
            curEnd = max(curEnd, time[i].second);
        }
        else {
            
            maxIn = max(maxIn, curEnd - curStart);
            maxOut = max(maxOut, time[i].first - curEnd);
            curStart = time[i].first;
            curEnd = time[i].second;
        }
    }
    maxIn = max(maxIn, curEnd - curStart); 

    cout << maxIn << " " << maxOut << endl;

    return 0;
}