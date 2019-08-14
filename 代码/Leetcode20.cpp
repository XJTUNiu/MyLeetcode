class Solution {
    template<typename T>
class Array
{
public:
	Array(int capacity){
    	data = new T[capacity];
	size = 0;
	this->capacity = capacity;
    }
	Array(){
	this->capacity = 20;
	data = new T[capacity];
	size = 0;
    }
	T& operator[](int i){
    return data[i];}

	bool IsEmpty(){
    return size == 0;}

	void add(int index, T e){
    	if (size == capacity) {
			reSize(this->capacity * 2);
	}
	if (index<0 || index>size) {
		throw "add::index<0 || index>size";
	}
	for (int i = size - 1; i >= index; i--) {
		data[i + 1] = data[i];
	}
	data[index] = e;
	size++;
    }
    T remove(int index) {
	if (index<0 || index>size) {
		throw "remove::index<0 || index>size";
	}
	int ret = data[index];
	for (int i = index + 1; i < size; i++) {
		data[i - 1] = data[i];
	}
	size--;
	data[size] = NULL;
	if (size == capacity / 4 && this->capacity / 2 != 0)
	{
		reSize(this->capacity / 2);
	}
	return ret;}


	void AddLast(T e){
    add(size, e);}

	T removeLast(){
    return remove(size - 1);}

	~Array(){
        	if (data != NULL) {
       delete[] data;
	   data = NULL;
	}
    }

private:
	void reSize(int newcapacity){
    	T* newdata = new T[newcapacity];
	for (int i = 0; i < size; i++) {
		newdata[i] = data[i];
	}
	data = newdata;
	this->capacity = newcapacity;}
protected:

private:
	int size;
	T *data;
	int capacity;
};

template<typename T>
class ArrayStack
{
public:
	ArrayStack(){
    }
	bool IsEmpty(){
    return array.IsEmpty();}
	void Push(T e){
    array.AddLast(e);}
	T pop(){
    return array.removeLast();}

private:
	Array<T> array;
};

    
public:
	bool isValid(string s) {
		ArrayStack<char> mystack;
		for (unsigned int i = 0; i < s.length(); i++) {
			char ch = s[i];
			if (ch == '(' || ch == '[' || ch == '{') {
				mystack.Push(ch);
			}
			else {
				if (mystack.IsEmpty()) {
					return false;
				}
				char topch = mystack.pop();
				if (ch == ')'&&topch != '(') {
					return false;
				}
				if (ch == ']'&&topch != '[') {
					return false;
				}
				if (ch == '}'&&topch != '{') {
					return false;
				}
			}
		}
		return mystack.IsEmpty();
	}
};
