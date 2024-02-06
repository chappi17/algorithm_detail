class A
{
public:
	A() {
		callA = 0;
	}
private:
	int callA;
	void inc() {
		callA++;
	}

protected:
	void func(int& a)
	{
		a = a * 2;
		inc();
	}
public:
	int getA() {
		return callA;
	}
};

class B
{
public:
	B() {
		callB = 0;
	}
private:
	int callB;
	void inc() {
		callB++;
	}
protected:
	void func(int& a)
	{
		a = a * 3;
		inc();
	}
public:
	int getB() {
		return callB;
	}
};

class C
{
public:
	C() {
		callC = 0;
	}
private:
	int callC;
	void inc() {
		callC++;
	}
protected:
	void func(int& a)
	{
		a = a * 5;
		inc();
	}
public:
	int getC() {
		return callC;
	}
};

class D : public A, B, C
{

	int val;
public:
	//Initially val is 1
	D()
	{
		val = 1;
	}


	//Implement this function
	void update_val(int new_val)
	{
		while (new_val % 2 == 0)
		{
			A::func(val);
			new_val /= 2;
		}

		// 3으로 나누어 떨어지는 횟수 계산
		while (new_val % 3 == 0)
		{
			B::func(val);
			new_val /= 3;
		}

		// 5로 나누어 떨어지는 횟수 계산
		while (new_val % 5 == 0)
		{
			C::func(val);
			new_val /= 5;
		}

	}
	void check(int); //Do not delete this line.
};