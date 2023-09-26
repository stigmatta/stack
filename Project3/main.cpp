#include <iostream>
#include <string.h>
#include <time.h>
using namespace std;

class Stack
{
	// Нижняя и верхняя границы стека
	enum { EMPTY = -1, FULL = 30 };

	// Массив для хранения данных
	char st[FULL + 1];

	// Указатель на вершину стека
	int top;

public:
	// Конструктор
	Stack();

	// Добавление элемента
	void Push(char c);

	// Извлечение элемента
	char Pop();

	// Очистка стека
	void Clear();

	// Проверка существования элементов в стеке
	bool IsEmpty();

	// Проверка на переполнение стека
	bool IsFull();
	char getTop();
	// Количество элементов в стеке
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
	// Изначально стек пуст
	top = EMPTY;
}

void Stack::Clear()
{
	// Эффективная "очистка" стека 
	// (данные в массиве все еще существуют, 
	// но функции класса, ориентированные на работу с вершиной стека,
	// будут их игнорировать)
	top = EMPTY;
}

bool Stack::IsEmpty()
{
	// Пуст?
	return top == EMPTY;
}

bool Stack::IsFull()
{
	// Полон?
	return top == FULL;
}

int Stack::GetCount()
{
	// Количество присутствующих в стеке элементов
	return top + 1;
}

void Stack::Push(char c)
{
	// Если в стеке есть место, то увеличиваем указатель
	// на вершину стека и вставляем новый элемент
	if (!IsFull())
		st[++top] = c;
}

char Stack::getTop()
{
	return st[top];
}

char Stack::Pop()
{
	// Если в стеке есть элементы, то возвращаем верхний и
	// уменьшаем указатель на вершину стека
	if (!IsEmpty())
		return st[top--];
	else // Если в стеке элементов нет
		return 0;
}
bool Stack::check_expression()
{
	Stack tmp;
	int i = 0;
	int open = 0, closed = 0;
	while (st[i] != ';')
	{
		if (st[i] == '(' || st[i] == '{' || st[i] == '[')
		{
			tmp.Push(st[i++]);
			++open;
		}
		else if (st[i] == ')' || st[i] == '}' || st[i] == ']') 
		{
			++closed;
			++i;
		}
		else
			++i;
	}
	if (open != closed)
		return false;
	i = 0;
	char left = tmp.getTop();
	while (st[i] != ';') /*([{}])*/
	{
		if (left == '(' && st[i] == ')' || left == '[' && st[i] == ']' || left == '{' && st[i] == '}') {
			tmp.Pop();
			left = tmp.getTop();
			i = 0;
		}
		else
			i++;
	}
	if(tmp.IsEmpty())
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
	// пока стек не заполнится
	//while (!ST.IsFull()) {
	//	c = rand() % 100;
	//	ST.Push(c);
	//}
	//// пока стек не освободится
	//while (c = ST.Pop()) {
	//	cout << c << " ";
	//}
	//cout << "\n\n";

}

