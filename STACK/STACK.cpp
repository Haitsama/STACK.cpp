#include <iostream>

using namespace std;

const int MAX_STACK = 5;

struct Stack
{
	int top;
	int data[MAX_STACK];
};

void inisialisasi();
void push(int data);
void pop();
void clear();
bool isEmpty();
bool isFull();
void print();

Stack stack;

int main()
{
	inisialisasi();

	int pilihanMenu;
	int data;

	do
	{
		cout << ">>>PILIHAN MENU STACK<<<\n\n";
		cout << "1. Menambah item stack"<<endl;
		cout << "2. Mengahpus item stack "<<endl;
		cout << "3. Menampilakn item stack"<<endl;
		cout << "4. Mengosongkan stack"<<endl;
		cout << "5. Selesai"<<endl;
		cout << "Masukan pilihan Anda : "; cin >> pilihanMenu;
		cout << endl;

		switch (pilihanMenu) {
		case 1:
			cout << "Masukan data : "; cin >> data;
			push(data);
			break;

		case 2:
			pop();
			break;

		case 3:
			print();
			break;

		case 4:
			clear();
			break;

		case 5:
			return 0;
		default:
			cout << "pilihan tidak tersedia!!!\n";
		}

	} while (pilihanMenu != 5);
	cout << endl;
	system("pause");
	return 0;
}

void inisialisasi()
{
	stack.top = -1;
}

void push(int data)
{
	if (isFull() == false)
	{
		stack.top++;
		stack.data[stack.top] = data;
		cout << "\nData berhasil di tambahkan\n\n";
	}
	else
	{
		cout << "\nStack sudah penuh !!!\n\n";
	}
}

void pop()
{
	if (isEmpty() == false)
	{
		cout << "Data " << stack.data[stack.top];
		stack.top--;
		cout << endl;
	}
	else
	{
		cout << "Stack masih kosong !!!\n\n";
	}
}

void clear()
{
	if (isEmpty() ==true)
	{
		cout << "Stack masih kosong !!!\n\n";
	}
	else 
	{
		stack.top = -1;
		cout << "Stack sudah dikosongkan" << endl << endl;
	}
	
}

bool isEmpty()
{
	return (stack.top == -1);
}

bool isFull()
{
	return (stack.top >= (MAX_STACK - 1));
}

void print()
{
	if (stack.top == -1)
	{
		cout << "Stack masih kosong !!!\n\n";
	}
	else
	{
		cout << "Isi stack :" << endl << endl;
		for (int i = 0;i <= stack.top;i++)
		{
			cout << stack.data[i] << endl;
		}
		cout << endl << endl;
	}
}

