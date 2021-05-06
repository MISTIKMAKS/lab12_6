#include <vector>
#include <string>
#include <queue>
#include <iostream>

using namespace std;

class Data {
public:
	string task;
	int priority;

	Data(string t, int p) : task(t), priority(p) {}
};


ostream& operator<<(ostream& cout, const Data* d) {
	return cout << d->task << "   Priority = " << d->priority;
}

int main()
{
	auto cmp = [](const Data* pl, const Data* pr) {
		return (pl->priority < pr->priority);
	};

	priority_queue<Data*, vector<Data*>, decltype(cmp)> data(cmp);

	data.push(new Data("Make Homework", 20));
	data.push(new Data("Spend Time With Family", 30));
	data.push(new Data("Do Household Chores", 10));
	data.push(new Data("Go For A Walk", 5));
	data.push(new Data("Play Games", 1));

	while (!data.empty()) {
		cout << data.top() << endl;
		data.pop();
	}

	return 0;
}