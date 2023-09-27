#include <iostream>
#include <string.h>
#include <time.h>
using namespace std;

class Stack
{
	// ������ � ������� ������� �����
	enum { EMPTY = -1, FULL = 30 };

	// ������ ��� �������� ������
	char st[FULL + 1];

	// ��������� �� ������� �����
	int top;

public:
	// �����������
	Stack();

	// ���������� ��������
	void Push(char c);

	// ���������� ��������
	char Pop();

	// ������� �����
	void Clear();

	// �������� ������������� ��������� � �����
	bool IsEmpty();

	// �������� �� ������������ �����
	bool IsFull();
	char getTop();
	// ���������� ��������� � �����
	int GetCount();
	void init(const char* str);
	void print();
	bool check_expression();
};

void Stack::init(const char* str)
{
	if (top == FULL)
		cout << "Stack overflow" << endl;
	else
	{
		int tmp = top;
		int i = 0;
		while (top != FULL)
		{
			if (top - strlen(str) == tmp)
				break;
			Push(str[i++]);
		}
	}
}
void Stack:: print()
{
	int i = 0;
	while (i <= top)
		cout << st[i++];
}

Stack::Stack()
{
	// ���������� ���� ����
	top = EMPTY;
}

void Stack::Clear()
{
	// ����������� "�������" ����� 
	// (������ � ������� ��� ��� ����������, 
	// �� ������� ������, ��������������� �� ������ � �������� �����,
	// ����� �� ������������)
	top = EMPTY;
}

bool Stack::IsEmpty()
{
	// ����?
	return top == EMPTY;
}

bool Stack::IsFull()
{
	// �����?
	return top == FULL;
}

int Stack::GetCount()
{
	// ���������� �������������� � ����� ���������
	return top + 1;
}

void Stack::Push(char c)
{
	// ���� � ����� ���� �����, �� ����������� ���������
	// �� ������� ����� � ��������� ����� �������
	if (!IsFull())
		st[++top] = c;
}

char Stack::getTop()
{
	return st[top];
}

char Stack::Pop()
{
	// ���� � ����� ���� ��������, �� ���������� ������� �
	// ��������� ��������� �� ������� �����
	if (!IsEmpty())
		return st[top--];
	else // ���� � ����� ��������� ���
		return 0;
}
bool Stack::check_expression()
{
	string tmp1 ,tmp2;
	int i = 0;
	int open = 0, closed = 0;
	char left = '\0', right = '\0';

	while (st[i] != ';')
	{
		if (st[i] == '(' || st[i] == '{' || st[i] == '[')
		{
			tmp1.push_back(st[i]);
			left = st[i++];
			++open;
		}
		else if (st[i] == ')' || st[i] == '}' || st[i] == ']') 
		{
			if (right == '\0')
				right = st[i];
			tmp2.push_back(st[i++]);
			++closed;
		}
		else
			++i;
	}
	if (open != closed)
		return false;
	i = 0;
	while (tmp1[i] != '\0' || tmp2[i] != '\0')
	{
		if (left == '(' && right == ')' || left == '[' && right == ']' || left == '{' && right == '}') {
			tmp1.pop_back();
			tmp2.erase(0,1);
			if (!(tmp1.empty()))
				left = tmp1.back();
			if(!(tmp2.empty()))
				right = tmp2.front();
			i = 0;
		}
		else
			i++;
	}
	if(tmp1.empty())
		return true;
	return false;
}
void main()
{
	srand(time(0));
	Stack ST;
	ST.init("(5+5*[5-5]);");
	cout<<ST.check_expression()<<endl;
	Stack ST1;
	ST1.init("(5+5};");
	cout << ST1.check_expression() << endl;
	Stack ST2;
	ST2.init("(5*5+3+[3*{2+2}+6]*3);");
	cout << ST2.check_expression() << endl;
	// ���� ���� �� ����������
	//while (!ST.IsFull()) {
	//	c = rand() % 100;
	//	ST.Push(c);
	//}
	//// ���� ���� �� �����������
	//while (c = ST.Pop()) {
	//	cout << c << " ";
	//}
	//cout << "\n\n";

}

