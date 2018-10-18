#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
#include<iomanip>
using namespace std;

int P1065() {
	int N;
	cin >> N;
	int id1, id2;
	map<int, int> cuples;
	set<int> guests;
	vector<int> soloGuests;
	for (int i = 0; i < N; i++) {
		cin >> id1 >> id2;
		cuples.insert(make_pair(id1, id2));
		cuples.insert(make_pair(id2, id1));
	}
	int M;
	cin >> M;
	int guestId;
	for (int i = 0; i < M; i++) {
		cin >> guestId;
		guests.insert(guestId);
	}
	for (auto iterSet = guests.begin(); iterSet != guests.end(); ++iterSet) {
		try {
			if (guests.find(cuples.at(*iterSet)) == guests.end())
				soloGuests.push_back(*iterSet);
		}
		catch (out_of_range) {
			soloGuests.push_back(*iterSet);
		}
	}
	sort(soloGuests.begin(), soloGuests.end());
	cout << soloGuests.size() << endl;
	if (soloGuests.size() != 0) {
		for (int i = 0; i < soloGuests.size() - 1; i++)
			cout << setw(5) << setfill('0') << soloGuests[i] << " ";
		cout << soloGuests[soloGuests.size() - 1];
	}
	return 0;
}