#pragma once
template<typename T>
class MySet{
	virtual void insert(T) = 0;
	virtual void remove(T) = 0;
	virtual void contains(T) = 0;

	//Template Method pattern
	void Union(MySet* first, MySet* second);
	
	void Intersection(MySet* first, MySet* second);
	
	void Diff(MySet* first, MySet* second);
	
	void SymDiff(MySet* first, MySet* second);
};

class MySetTree {
	
};