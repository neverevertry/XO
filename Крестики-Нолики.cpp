#include <iostream>
#include <ctime>

using namespace std;

enum Step
{
	Cross,
	Circle
};

class Board
{
private:
	static const int rows = 3;
	static const int cols = 3;
	bool IsFinished;
	Step step = Cross;
	char arr[rows][cols];
public:
	Board()
	{
		IsFinished = false;
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				arr[i][j] = '_';
				cout << arr[i][j] << ' ';
			}
			cout << endl;
		}
	}

	void Step(int num)
	{
		char Sign;
		if (step == Cross)
			Sign = 'x';
		else
			Sign = 'o';

		switch (num)
		{
		case 1:
		{
			arr[0][0] = Sign;
		}; break;
		case 2:
		{
			arr[0][1] = Sign;
		}; break;
		case 3:
		{
			arr[0][2] = Sign;
		}; break;
		case 4:
		{
			arr[1][0] = Sign;
		}; break;
		case 5:
		{
			arr[1][1] = Sign;
		}; break;
		case 6:
		{
			arr[1][2] = Sign;
		}; break;
		case 7:
		{
			arr[2][0] = Sign;
		}; break;
		case 8:
		{
			arr[2][1] = Sign;
		}; break;
		case 9:
		{
			arr[2][2] = Sign;
		}; break;
		}

		if (step == Cross)
			step = Circle;
		else
			step = Cross;
	}

	bool IsAllowedStep(int num, bool WhoseStep)
	{
		bool flag = false;
		while (!flag)
		{
			int answer = num / 3;
			int remainder = num % 3 - 1;
			int FinishCols = num % 3;

			if (FinishCols == 0)
			{
				arr[answer][2] = step;
				return true;
			}
			if (arr[answer][remainder] == '_')
			{
				arr[answer][remainder] = step;
				return true;
			}
			else
			{
				if (WhoseStep)
				{
					cout << "Ячейка занята, выберите другую ячейку!";
					cin >> num;
				}
				else
					num = rand() % 8 + 1;
			}
		}
	}

	bool IsGameOver(int i, int _ChoisFigure)
	{
		
		if (i >= 5)
		{
			if ((arr[0][0] == arr[0][1] && arr[0][1] == arr[0][2]) && arr[0][0] != '_')
			{
				if (_ChoisFigure == 1)
					cout << "Победа Х\n";
				else
					cout << "Победа О\n";
				return true;
			}
			if ((arr[1][0] == arr[1][1] && arr[1][1] == arr[1][2]) && arr[1][0] != '_')
			{
				if (_ChoisFigure == 1)
					cout << "Победа Х\n";
				else
					cout << "Победа О\n";
				return true;
			}
			if ((arr[2][0] == arr[2][1] && arr[2][1] == arr[2][2]) && arr[2][1] != '_')
			{
				if (_ChoisFigure == 1)
					cout << "Победа Х\n";
				else
					cout << "Победа О\n";
				return true;
			}
			if ((arr[0][0] == arr[1][0] && arr[1][0] == arr[2][0]) && arr[0][0] != '_')
			{
				if (_ChoisFigure == 1)
					cout << "Победа Х\n";
				else
					cout << "Победа О\n";
				return true;
			}
			if ((arr[0][1] == arr[1][1] && arr[1][1] == arr[2][1]) && arr[0][1] != '_')
			{
				if (_ChoisFigure == 1)
					cout << "Победа Х\n";
				else
					cout << "Победа О\n";
				return true;
			}
			if ((arr[0][2] == arr[1][2] && arr[1][2] == arr[2][2]) && arr[0][2] != '_')
			{
				if (_ChoisFigure == 1)
					cout << "Победа Х\n";
				else
					cout << "Победа О\n";
				return true;
			}
			if ((arr[0][0] == arr[1][1] && arr[1][1] == arr[2][2]) && arr[0][0] != '_')
			{
				if (_ChoisFigure == 1)
					cout << "Победа Х\n";
				else
					cout << "Победа О\n";
				return true;
			}
			if ((arr[0][2] == arr[1][1] && arr[1][1] == arr[2][0]) && arr[0][2] != '_')
			{
				if (_ChoisFigure == 1)
					cout << "Победа Х\n";
				else
					cout << "Победа О\n";
				return true;
			}

			if (i == 9)
			{
				cout << "Ничья!\n";
				return true;
			}
			return false;
		}
		else
			return false;
	}

	void Print()
	{
		for (int i = 0; i < cols; i++)
		{
			for (int j = 0; j < rows; j++)
				cout << arr[i][j] << ' ';
			cout << endl;
		}
	}
};

int main()
{
	setlocale(LC_ALL, "russian");
	srand(time(NULL));

	int menu;
	do
	{
		cout << "1.Начать игру с компьютером\n";
		//cout << "2.Начать игру с другом\n";
		cout << "0.Выход\n";
		cin >> menu;
		switch (menu)
		{
		case 1:
		{
			cout << "Выберите фигуру. 1-Х 2-О. Первыми ходят крестики\n";
			int ChoisFigure;
			cin >> ChoisFigure;
			int i = 0;
			Board* board = new Board();
			cout << endl;
			while (board->IsGameOver(i, ChoisFigure) == false)
			{
				if (ChoisFigure == 1)
				{
					bool HumanStep = true;
					int numb;
					i++;
					cin >> numb;
					board->IsAllowedStep(numb, HumanStep);
					board->Step(numb);
					board->Print();
					ChoisFigure = 2;
					cout << endl;
					cout << endl;
					cout << endl;
				}
				else
				{
					bool ComputerStep = false;
					int numb = rand() % 9 + 1;
					i++;
					board->IsAllowedStep(numb, ComputerStep);
					board->Step(numb);
					board->Print();
					ChoisFigure = 1;
					cout << endl;
					cout << endl;
					cout << endl;
				}
			}
		};break;
		case 0:
		{
			break;
		}; break;
		}
	} while (menu != 0);
	
	

	system("pause");
	return 0;
}