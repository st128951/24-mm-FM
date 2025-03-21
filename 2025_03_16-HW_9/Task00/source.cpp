#include<string>
#include<iostream>
#include<ctime>

using namespace std;

struct Student
{	
public:
		string name;
		int hp;
		int dmg;
		int luck;
		int inithp;
		int initdmg;
		int initluck;
		int abilityInd[10];
		string fraction;
		bool slowly;
		bool noMana;
		bool isDebufed;

		Student(string name, int hp = 100, int dmg = 5, int luck = 10, int inithp = 100, int initdmg = 5, int initluck = 10, int* abilityIndex = { 0 }, string fraction = " ", bool slowly = false, bool noMana = false, bool isDebufed = false) :
		name(name), hp(hp), dmg(dmg), luck(luck), inithp(inithp), 
		initdmg(initdmg), initluck(initluck), fraction(fraction)
	{
		randomStats();
		setInitStats();
		setAbIndex();
	}

	Student()
	{
		randomStats();
		setInitStats();
		setAbIndex();
	}

	void setInitStats()
	{
		this->inithp = this->hp;
		this->initdmg = this->dmg;
		this->initluck = this->luck;
	}

	void resetStats()
	{
		this->hp = this->inithp;
		this->dmg = this->initdmg;
		this->luck = this->initluck;
	}

	void randomStats()
	{
		this->hp = rand() % (200 - 75 + 1) + 75;
		this->dmg = rand() % (20 - 5 + 1) + 5;
		this->luck = rand() % 30;
		
		if (rand() % 10 > 4)
		{
			this->fraction = "PUNK";
		}

		else
		{
			this->fraction = "GOROD";
		}
	}

	string setname(int i)
	{
		string array[16] = { " " };
		array[0] = "Evgenii";
		array[1] = "Maximilian";
		array[2] = "Gleb Pshenichniy. Gleb.";
		array[3] = "Maria";
		array[4] = "Valeria";
		array[5] = "Maxim";
		array[6] = "Fedor";
		array[7] = "Yapomip";
		array[8] = "Slava";
		array[9] = "Anton";
		array[10] = "Gleb";
		array[11] = "Alexander";
		array[12] = "Sacha";
		array[13] = "Nikita";
		array[14] = "Victor";
		array[15] = "Oleg";

		return array[i];
	}

	Student(const Student& student) :
		name(student.name),
		hp(student.hp),
		dmg(student.dmg),
		luck(student.luck),
		inithp(student.inithp),
		initdmg(student.initdmg),
		initluck(student.initluck)
	{}

	~Student()
	{}

	bool luckWorks()
	{
		return (rand() % 100 < luck);
	}

	bool isWonded()
	{
		if (this->hp < (inithp / 10))
		{
			return true;
		}

		else 
		{
			return false;
		}
	}

	bool isDead()
	{
		return (hp < 1);
	}

	void getDmg(int dmg)
	{
		if (luckWorks())
		{
			cout << "\t" << name << " LUCK WORKS FOR GETTING DAMAGE\n";
			dmg /= 2;
		}
		hp -= dmg;
	}

	int makeDmg()
	{
		if (luckWorks())
		{
			cout << "\t" << name << " LUCK WORKS FOR MAKING DAMAGE\n";
			return dmg * 2;
		}
		else
		{
			return dmg;
		}
	}

	void print()
	{
		cout << name << " [" << hp << "] (";
		cout << "luck=" << luck << ";";
		cout << "damage=" << dmg << ")\n";
	}
	
	void setAbIndex()
	{	
		int a = rand() % 10;
		int b = rand() % 10;
		int c = rand() % 10;
		for (int i = 0; i < 10; ++i)
		{
			if (i == a || i == b || i == c)
			{
				this->abilityInd[i] = 1;
			}
			else
			{
				this->abilityInd[i] = 0;
			}
			
		}
	}

	int getStats(Student st1, string a)
	{
		if (a == "hp")
		{
			return st1.hp;
		}
		else if (a == "dmg")
		{
			return st1.dmg;
		}
		else if (a == "luck")
		{
			return st1.luck;
		}
		else if (a == "inithp")
		{
			return st1.inithp;
		}
		else if (a == "initdmg")
		{
			return st1.initdmg;
		}
		else if (a == "initluck")
		{
			return st1.initluck;
		}
		else
		{
			exit(0);
		}
		// int a = getStats(st1, hp)
	}
};

void abilityUse(Student st1, Student st2, int** tempab, int n1)
{
	for (int i = 0; i < 10; ++i)
	{
		if (tempab[n1][i] == 1)
		{
			switch (i)
			{
				case(0):
				{
					cout << "\tEXTRA COMBO\n";
					st2.hp -= st1.dmg;
					break;
				}
				case(1):
				{
					cout << "\tSEE YOU NEXT TIME, GRIGOR\n";
					st2.isDebufed = true;

					break;
				}
				case(2):
				{
					cout << "\tDO WE HAVE HILL?\n";

					if (st1.hp <= (st1.inithp / 2))
					{
						st1.hp += st1.inithp / 5;
					}

					else
					{
						st1.hp += 5;
					}

					break;
				}
				case(3):
				{
					cout << "\tDO WE HAVE HOMETASKS FOR TOMORROW?\n";
					if (st1.name == "Gleb Pshenichniy.Gleb.")
					{
						cout << "\tHUH, FIRST TIME?\n";
						st2.hp -= 10;
					}

					int a = (rand() % 1000);

					if(((a % 127) == 0) && (st1.name != "Gleb Pshenichniy.Gleb."))
					{
						st2.hp -= 1000000;
						cout << "\tK.O\n";
					}
					
					else
					{
						cout << "\tIT'S BAD FOR YOU YOURSELF\n";
						st1.hp -= 5;
					}

					break;
				}
				case(4):
				{
					cout << "\tOH MY GOD, ELKA\n";
					if (st2.fraction == "PUNK")
					{
						cout << "\n\tIT'S NOTHING FOR ME\n";
						st2.luck += 1;
					}
					else
					{
						st1.luck += 1;
						st2.slowly = true;
					}

					break;
				}
				case(5):
				{
					cout << "\tAND NOW - REVERCE\n";
					st1.hp = st2.inithp;
					st2.hp = st1.inithp;
					st1.dmg = st2.initdmg;
					st2.dmg = st1.initdmg;
					st1.abilityInd[5] = 0;

					break;
				}
				case(6):
				{
					if (st1.hp < (st1.inithp * 9 / 10))
					{
						cout << "\tHOW LONG YOU ARE SEVENTEEN?\n";
						st1.hp += (st1.inithp / 15);
						st2.hp -= (st1.inithp / 15);
					}

					else
					{
						cout << "\tYOU ARE VAMPIRE?\n";
						st1.hp = (st1.inithp * 9 / 10);
					}

					break;
				}
				case(7):
				{
					if (rand() % 3 == 1)
					{
						cout << "\tPHYSIC? IS MAGIC, LOL\n";
						st1.slowly = true;
						st2.slowly = true;
					}

					break;
				}
				case(8):
				{
					if (rand() % 4 == 1)
					{
						cout << "\t2 HANDS WITH SWORD >> MAGIC\n";
						st1.noMana = true;
						st2.noMana = true;
					}
					else if (rand() % 15 == 1)
					{
						cout << "\tHAPPY MIRROR\n";
						abilityUse(st1, st2, tempab, n1);
					}

					break;
				}
				case(9):
				{
					if (rand() % 8 == 1)
					{
						cout << "\tTACTICAL DEVELOPMENT\n";
						for (int i = 0; i < 10; ++i)
						{
							st1.abilityInd[i] = 0;
						}
						int a = rand() % 10;
						int b = rand() % 10;
						for (int i = 0; i < 10; ++i)
						{
							if (i == a || i == b)
							{
								st1.abilityInd[i] = 1;
							}
							else
							{
								st1.abilityInd[i] = 0;
							}
						}
						st1.abilityInd[9] = 1;
						st2.abilityInd[rand() % 10] = 0;
					}

					break;
				}

			}
		}

		else
		{
			continue;
		}
	}
}

void battle(Student st1, Student st2, int* arr, int n1, int n2, int** tempab)
{
	int round = 1;
	while (!(st1.isDead() || st2.isDead()))
	{
		cout << "\n\t\tROUND " << round++ << "\n";
		st1.print();
		cout << "versus\n";
		st2.print();
		if (st1.slowly == false)
		{
			st2.getDmg(st1.makeDmg());
		}
		if ((st1.slowly == false))
		{
			st1.getDmg(st2.makeDmg());
		}
		if (st1.name == "Gleb Pshenichniy. Gleb." && st1.luckWorks())
		{
			st1.getDmg(-st1.makeDmg());
		}

		st1.slowly = false;
		st2.slowly = false;

		cout << "\n" << st1.name << " USE";
		abilityUse(st1, st2, tempab, n1);
		cout << "\n" << st2.name << " USE";
		abilityUse(st2, st1, tempab, n1);
		st1.noMana = false;
		st2.noMana = false;

		if (st1.isDebufed == true)
		{
			st1.hp -= 5;
		}

		if (st2.isDebufed == true)
		{
			st2.hp -= 5;
		}
	}
	if (st1.isDead() && st2.isDead())
	{
		st1.resetStats();
		st2.resetStats();
		cout << "DRAW!! RESTART FIGHT\n";
		battle(st1, st2, arr, n1, n2, tempab);
	}
	else
	{
		cout << (st1.isDead() ? st2.name : st1.name) << " wins\n";
		if (st1.isDead())
		{
			arr[n1] = 0;
		}
		else if (st2.isDead())
		{
			arr[n2] = 0;
		}
	}
}

int count(int* arr, int len)
{
	int count = 0;
	for (int i = 0; i < 16; ++i)
	{
		count += arr[i];
	}

	return count;
}

string setname(int i)
{
	string array[16] = { " " };
	array[0] = "Evgenii";
	array[1] = "Maximilian";
	array[2] = "Gleb Pshenichniy. Gleb.";
	array[3] = "Maria";
	array[4] = "Valeria";
	array[5] = "Maxim";
	array[6] = "Fedor";
	array[7] = "Yapomip";
	array[8] = "Slava";
	array[9] = "Anton";
	array[10] = "Gleb";
	array[11] = "Alexander";
	array[12] = "Sacha";
	array[13] = "Nikita";
	array[14] = "Victor";
	array[15] = "Oleg";

	return array[i];
}

int main()
{
	srand(time(0));

	Student* st = new Student[16];

	int array[16] = { 0 };

	for (int i = 0; i < 16; ++i)
	{
		array[i] = 1;
	}


	for (int i = 0; i < 16; ++i)
	{
		st[i].name = setname(i);
	}

	int **tempab = new int* [16];

	for (int j = 0; j < 16; ++j)
	{
			tempab[j] = new int[10];
	}

	for (int j = 0; j < 16; ++j)
	{
		for (int i = 0; i < 10; ++i)
		{
			tempab[j][i] = st[j].abilityInd[i];
		}
	}

	int counter = 1;

		for (int i = 0; i < 16; ++i)
		{
			int temp = i;
			for (int j = 15; j > temp; --j)
			{
				if (array[i] + array[j] == 2)
				{
					cout << "\n\n\t\tBATTLE " << counter << "\n";
					battle(st[i], st[j], array, i, j, tempab);
					++counter;
				}
				int summ = count(array, 16);

				if (summ == 1)
				{
					cout << "TOURNIR ENDED";
				}
			}
		}
	return 0;
}