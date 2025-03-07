#include<iostream>
class ArrayList
{
private:
	int len;
	int* data;
	void init(int len = 10)
	{
		this->len = len;
		this->data = (int*)malloc(sizeof(int) * len);
	}
	bool indexValid(int index)
	{
		return 0 <= index < this->len;
	}
	void expand();

public:
	ArrayList(int len = 10)
	{
		this->init(len);
		for (int i = 0; i < this->len; ++i)
		{
			this->data[i] = 0;
		}
	}
	ArrayList(ArrayList& list)
	{
		this->init(list.len);
		for (int i = 0; i < list.len; ++i)
		{
			this->set(i, list.get(i));
		}
	}
	~ArrayList()
	{
		free(this->data);
	}
	void randomize(int min = 10, int max = 99)
	{
		for (int i = 0; i < len; ++i)
		{
			this->data[i] = rand() % (max - min + 1) + min;
		}
	}
	void print()
	{
		for (int i = 0; i < this->len; ++i)
		{
			printf("%d ", this->data[i]);
		}
		printf("\n");
	}
	int get(int index)
	{
		if (indexValid(index))
		{
			return this->data[index];
		}
		return -1;
	}
	void set(int index, int value)
	{
		if (indexValid(index))
		{
			this->data[index] = value;
		}
	}
	int count()
	{
		return len;
	}

	void pushBack(int elem)
	{
		int* temp = (int*)malloc(sizeof(int) * (this->len + 1));
		int t1 = this->len + 1;
		temp[this->len] = elem;
		for (int i = 0; i < len; ++i)
		{
			temp[i] = this->data[i];
		}
		this->data = temp;
		(this->len) = t1;
	}
	void pushFront(int element)
	{
		int* temp = (int*)malloc(sizeof(int) * (this->len + 1));
		int t1 = this->len + 1;
		temp[0] = element;
		for (int i = 1; i < len + 1; ++i)
		{
			temp[i] = this->data[i];
		}
		this->data = temp;
		(this->len) = t1;
	}
	void insert(int index, int element)
	{
		int* temp = (int*)malloc(sizeof(int) * (this->len + 1));
		int t1 = this->len + 1;
		for (int i = 0; i < this->len; ++i)
		{
			int b = 0;
			if (i < index)
			{
				temp[b] = this->data[i];
				++b;
			}
			else if (i == index)
			{
				temp[index] = element;;
			}
			else if (i > index)
			{
				temp[b] = this->data[i];
				++b;
			}
		}
		this->data = temp;
		(this->len) = t1;
	}
	void popBack()
	{
		int* temp = (int*)malloc(sizeof(int) * (this->len - 1));
		int b = 0;
		int t1 = this->len - 1;
		for (int i = 0; i < len - 1; ++i)
		{
			temp[b] = this->data[i];
			++b;
		}
		this->data = temp;
		(this->len) = t1;
	}
	void popFront()
	{
		int* temp = (int*)malloc(sizeof(int) * ((this->len - 1)));
		int b = 0;
		int t1 = this->len - 1;
		for (int i = 1; i < this->len; ++i)
		{
			temp[b] = this->data[i];
			++b;
		}
		this->data = temp;
		(this->len) = t1;
	}
	int extract(int index)
	{
		int* temp = ((int*)malloc(sizeof(int) * (this->len - 1)));
		int t1 = this->len - 1;
		int ex = 0;
		for (int i = 0; i < this->len; ++i)
		{
			int b = 0;
			if (i < index)
			{
				(temp[b]) = this->data[i];
				++b;
			}
			else if (i == index)
			{
				ex = this->data[i];
			}
			else if (i > index)
			{
				temp[b] = this->data[i];
				++b;
			}
		}
		this->data = temp;
		(this->len) = t1;
		return ex;
	}
	void reverse(int start, int end)
	{
		for (int i = 0; i < (end - start) / 2 + (end - start) % 2; ++i)
		{
			std::swap(this->data[start + i], this->data[end - i]);
		}
	}
	int sum()
	{
		int s = 0;
		for (int i = 0; i < this->len; ++i)
		{
			s += this->data[i];
		}
		return s;
	}
	int secondMax()
	{
		int st = this->data[0];
		int c = 0;
		for (int i = 1; i < this->len; ++i)
		{
			if (this->data[i] > st)
			{
				st = this->data[i];
				c = i;
			}
		}
		this->data[c] = st - 1;
		int sm = this->data[0];
		for (int i = 1; i < len; ++i)
		{
			if (this->data[i] > st)
			{
				sm = this->data[i];
			}
		}
		this->data[c] = st;
		return sm;
	}
	int lastMinIndex()
	{
		int st = this->data[0];
		int min = 0;
		for (int i = 1; i < this->len; ++i)
		{
			if (this->data[i] <= min)
			{
				st = this->data[i];
				min = i;
			}
		}
		return min;
	}
	void shift(int k)
	{
		int* a = (int*)malloc(sizeof(int) * this->len);
		int b = 0;
		for (int i = 0; i + k < this->len; ++i)
		{
				a[i + k] = this->data[i];
				++b;
		}
		for (int j = 0; j < k; ++j)
		{
			a[j] = this->data[b];
			++b;
		}
		this->data = a;
	}
	int countOdd()
	{
		int sod = 0;
		for (int i = 1; i < this->len; ++i)
		{
			if (this->data[i] % 2 == 1)
			{
				sod += 1;
			}
		}
		return sod;
	}
	int sumEven()
	{
		int se = 0;
		for (int i = 0; i < this->len; ++i)
		{
			if (this->data[i] % 2 == 0)
			{
				se += this->data[i];
			}
		}
		return se;
	}
};

int max(ArrayList list)
{
	int mx = list.get(0);
	for (int i = 0; i < list.count(); ++i)
	{
		mx = (mx > list.get(i) ? mx : list.get(i));
	}
	return mx;
}

int main(int argc, char* argv[])
{
	ArrayList list(10);
	list.randomize();
	list.print();
	list.popBack();
	list.print();
	list.shift(2);
	list.print();
	return 0;
}