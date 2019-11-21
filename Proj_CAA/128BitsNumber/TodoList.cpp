#include "TodoList.h"



void TodoList::checkList() {
	int count = 0;
	cout << endl;
	for (auto it = this->m_list.begin(); it != this->m_list.end(); ++it) {
		cout << "Task " << ++count << endl;
		(*it)->ShowAllInfor();
		cout << endl;
	}
}

vector<QInt*> TodoList::doTask() {
	vector<QInt*> res;
	int count = 1;
	for (auto it = this->m_list.begin(); it != this->m_list.end(); ++it) {
		res.push_back((*it)->Exe());
	}
	return res;
}

TodoList TodoList::operator= (const TodoList& list) {
	if (!this->m_list.empty()) {
		for (auto it = this->m_list.begin(); it != this->m_list.end(); ++it)
			delete* it;
		this->m_list.clear();
	}

	for (auto it = list.m_list.begin(); it != list.m_list.end(); ++it) {
		Task* tmp = (*it)->Alloc();
		this->m_list.push_back(tmp);
	}

	return *this;
}

TodoList::TodoList(const TodoList& list) {
	if (!this->m_list.empty()) {
		for (auto it = this->m_list.begin(); it != this->m_list.end(); ++it)
			delete* it;
		this->m_list.clear();
	}

	for (auto it = list.m_list.begin(); it != list.m_list.end(); ++it) {
		Task* tmp = (*it)->Alloc();
		this->m_list.push_back(tmp);
	}
}

TodoList::TodoList() {
	//Do nothing
}

TodoList::~TodoList() {
	if (!this->m_list.empty()) {
		for (auto it = this->m_list.begin(); it != this->m_list.end(); ++it)
			delete* it;
		this->m_list.clear();
	}
}

TodoList::TodoList(vector<Task*> tasks) {
	for (auto it = tasks.begin(); it != tasks.end(); ++it)
		this->m_list.push_back(*it);
}