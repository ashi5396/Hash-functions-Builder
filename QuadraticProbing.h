#ifndef QUADRATIC_PROBING_H
#define QUADRATIC_PROBING_H

#include <vector>
#include <algorithm>
#include <functional>
#include <string>
using namespace std;

// QuadraticProbing Hash table class
//
// CONSTRUCTION: an approximate initial size or default of 101
//
// ******************PUBLIC OPERATIONS*********************
// bool insert( x )       --> Insert x
// bool remove( x )       --> Remove x
// bool contains( x )     --> Return true if x is present
// void makeEmpty( )      --> Remove all items
// int hashCode( string str ) --> Global method to hash strings

template <typename HashedObj>
class QuadraticProbing
{
public:

	explicit QuadraticProbing(int size = 101) : array(nextPrime(size))
	{
		makeEmpty();
	}
    
    
	int getCollisions() const
	{
		return collisions;
	}
	
	
	void setCollisions(int coll) const 
	{
		this->collisions = coll;
	}


	bool isPrime(int n)
	{
		if (n == 2 || n == 3)
			return true;

		if (n == 1 || n % 2 == 0)
			return false;

		for (int i = 3; i * i <= n; i += 2)
			if (n % i == 0)
				return false;

		return true;
	}


	int nextPrime(int n)
	{
		if (n % 2 == 0)
			++n;

		for (; !isPrime(n); n += 2);

		return n;
	}


	bool contains(const HashedObj & x) const
	{
		return isActive(findPos(x));
	}


	bool contains(const HashedObj &x, int number) const 
	{ 
		switch (number) 
		{
		case 1:
			return isActive(findSimple(x));
			break;
		case 2:
			return isActive(findPrefix(x));
			break;
		case 3:
			return isActive(findFull(x));
			break;
		default:
			return isActive(findPos(x));
			break;
		}
	}
	
	
	void makeEmpty()
	{
		currentSize = 0;
		for (auto & entry : array) 
		{
			entry.info = EMPTY;
		}
	}


	bool insert(const HashedObj &x)
	{
		// Insert x as active
		unsigned int currentPos = (unsigned int)findPos(x);
		if (isActive(currentPos))
			return false;

		if (array[currentPos].info != DELETED)
			++currentSize;

		array[currentPos].element = x;
		array[currentPos].info = ACTIVE;

		// Rehash; see Section 5.5
		if (currentSize > array.size() / 2)
			rehash();

		return true;
	}


	bool insert(const HashedObj &x, int number) 
	{ // HASH CODE = 1: simple; 2: prefix; 3: full
		int currentPos;
		// Insert x as active
		switch (number) 
		{
		case 1:
			currentPos = findSimple(x);
			break;
		case 2:
			currentPos = findPrefix(x);
			break;
		case 3:
			currentPos = findFull(x);
			break;
		default:
			currentPos = findPos(x);
		}

		if (isActive(currentPos))
			return false;

		if (array[currentPos].info != DELETED)
			++currentSize;

		array[currentPos].element = x;
		array[currentPos].info = ACTIVE;

		// Rehash; see Section 5.5
		if (currentSize > array.size() / 2)
			rehash();

		return true;
	}

	
	bool insert(HashedObj && x)
	{
		// Insert x as active
		int currentPos = findPos(x);
		if (isActive(currentPos))
			return false;

		if (array[currentPos].info != DELETED)
			++currentSize;

		array[currentPos] = std::move(x);
		array[currentPos].info = ACTIVE;

		// Rehash; see Section 5.5
		if (currentSize > array.size() / 2)
			rehash();

		return true;
	}


	bool remove(const HashedObj & x)
	{
		int currentPos = findPos(x);
		if (!isActive(currentPos))
			return false;

		array[currentPos].info = DELETED;
		return true;
	}


	enum EntryType { ACTIVE, EMPTY, DELETED };

private:

	mutable int collisions = 0;
	
	
	struct HashEntry
	{
		HashedObj element;
		EntryType info;

		HashEntry(const HashedObj & e = HashedObj{}, EntryType i = EMPTY)
			: element{ e }, info{ i } { }

		HashEntry(HashedObj && e, EntryType i = EMPTY)
			: element{ std::move(e) }, info{ i } { }
	};

	vector<HashEntry> array;
	unsigned int currentSize;


	bool isActive(int currentPos) const
	{
		return array[currentPos].info == ACTIVE;
	}


	int findPos(const HashedObj &x) const
	{
		int offset = 1;
		int currentPos = myhash(x);
		int col = 0;
		setCollisions(0);
		while (array[currentPos].info != EMPTY && array[currentPos].element != x) 
		{
			col = getCollisions();
			col++;
			setCollisions(col);
			currentPos += offset;  // Compute ith probe
			offset += 2;
			if (currentPos >= array.size())
				currentPos -= array.size();
		}

		return currentPos;
	}


	int findSimple(const HashedObj &x) const 
	{
		int offset = 1;
		int currentPos = simple_hash(x);
		int col = 0;
		setCollisions(0);
		while (array[currentPos].info != EMPTY && array[currentPos].element != x)
		{
			col=getCollisions();
			col++;
			setCollisions(col);
			currentPos += offset; // Compute ith probe
			offset += 2;
			if (currentPos >= array.size())
				currentPos -= array.size();
		}

		return currentPos;
	}


	int findPrefix(const HashedObj &x) const 
	{
		int offset = 1;

		/*if (x.size() == 1) {
			cout << "x: " << x[0] << " x_size:" << x.size() << endl;
		}
		else if (x.size() == 2) {
			cout << "x: " << x[0] << " x1: " << x[1] << " x_size:" << x.size() << endl;
		}
		else {
			cout << "x: " << x[0] << " x1: " << x[1] << " x2:" << x[2] << " x_size:" << x.size() << endl;
		}
*/

		int currentPos = prefix_hash(x);
		int col = 0;
		setCollisions(0);
		while (array[currentPos].info != EMPTY && array[currentPos].element != x)
		{
			col = getCollisions();
			col++;
			setCollisions(col);
			currentPos += offset; // Compute ith probe
			offset += 2;
			if (currentPos >= array.size())
				currentPos -= array.size();
		}

		return currentPos;
	}


	int findFull(const HashedObj &x) const 
	{
		int offset = 1;
		int currentPos = full_hash(x);
		int col = 0;
		setCollisions(0);

		while (array[currentPos].info != EMPTY && array[currentPos].element != x)
		{
			col = getCollisions();
			col++;
			setCollisions(col);
			currentPos += offset; // Compute ith probe
			offset += 2;
			if (currentPos >= array.size())
				currentPos -= array.size();
		}

		return currentPos;
	}


	void rehash() 
	{
		vector<HashEntry> oldArray = array;

		// Create new double-sized, empty table
		array.resize(nextPrime(2 * oldArray.size()));
		for (auto & entry : array)
			entry.info = EMPTY;

		// Copy table over
		currentSize = 0;
		for (auto & entry : oldArray)
			if (entry.info == ACTIVE)
				insert(std::move(entry.element));
	}


	size_t myhash(const HashedObj & x) const 
	{
		static hash<HashedObj> hf;
		return hf(x) % array.size();
	}


	size_t simple_hash(const HashedObj &x) const 
	{
		int hashVal = 0;

		for (char ch : x)
			hashVal += ch;

		return hashVal % array.size();
	}


	size_t prefix_hash(const HashedObj &x) const 
	{
		if (x.size() == 1) {
			return (x[0]) % array.size();
		}
		else if (x.size() == 2) {
			return (x[0] + 27 * x[1]) % array.size();
		}
		else {
			return (x[0] + 27 * x[1] + 729 * x[2]) % array.size();
		}
	}


	size_t full_hash(const HashedObj &x) const 
	{
		unsigned int hashVal = 0;

		for (char ch : x)
			hashVal = 37 * hashVal + ch;

		return hashVal % array.size();
	}


};

#endif
