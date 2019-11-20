#pragma once
#include"pch.h"
#include"Task.h"

class TodoList{
private:
	vector<Task*> m_list;
public:
	void checkList();
	vector<QInt*> doTask();
public:
	TodoList operator= (const TodoList& list);
	TodoList(const TodoList& list);
	TodoList();
	~TodoList();
public:
	TodoList(vector<Task*> tasks);
};

