#pragma once
class IntegerArray
{
private:
	int m_length{};
	int* m_data{};
public:
	IntegerArray() = default;
	IntegerArray(int length);
	~IntegerArray();

	IntegerArray& operator=(const IntegerArray& a);
	int& operator[](int index);

	void erase();
	void reallocate(int newLength);
	void resize(int newLength);
	IntegerArray(const IntegerArray& a);
	void insertBefore(int value, int index);
	void remove(int index);
	int getLength() const;
	void insertAtBeginning(int value);
	void insertAtEnd(int value);
};

