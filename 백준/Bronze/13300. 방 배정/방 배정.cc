#include<iostream>
#include<vector>
#include<string>
using namespace std;

int gender_arr[2][7] = {};

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int people_num, max_people, gender, grade;
	cin >> people_num >> max_people;


	for (int i = 0; i < people_num; i++) {
		cin >> gender >> grade;
		gender_arr[gender][grade]++;
	}

	int room_cnt = 0;
	for (int j = 0; j < 2; j++) {
		for (int i = 1; i <= 6; i++) {
			room_cnt += gender_arr[j][i] / max_people;
			
			if (gender_arr[j][i] % max_people)
				room_cnt++;
		}
	}
	cout << room_cnt;
}