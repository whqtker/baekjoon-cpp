#include <string>
#include <vector>
#include <map>
#include <sstream>

using namespace std;

string i2s(int x) {
	if (x < 10) return "0" + to_string(x);
	return to_string(x);
}

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
	vector<int> answer;

	// today를 연, 월, 일로 쪼개기
	vector<int> ret; // 연, 월, 일
	istringstream iss(today);
	string token;

	while (getline(iss, token, '.')) {
		ret.push_back(stoi(token));
	}

	map<string, string> expiry_date;
	for (int i = 0; i < terms.size(); i++) {
		string term;
		string duration;
		stringstream ss(terms[i]);
		ss >> term >> duration;

		int year = ret[0];
		int month = ret[1] - stoi(duration);
		int day = ret[2];

		// 뺀 결과가 양의 정수가 아닌 경우 보정
		while (month <= 0) {
			year--;
			month += 12;
		}

		string date = to_string(year) + "." + i2s(month) + "." + i2s(day);
		expiry_date.insert({ term,date });
	}

	for (int i = 0; i < privacies.size(); i++) {
		stringstream ss(privacies[i]);
		string date, term;
		ss >> date >> term;

		if (expiry_date[term] >= date) {
			answer.push_back(i + 1);
		}
	}
	return answer;
}