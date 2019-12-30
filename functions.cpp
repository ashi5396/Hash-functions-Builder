#include "functions.h"
#include <chrono>

/******************************************************************************************************************************************************
* Programmer:   Kadupitige Ashi Chamarasinghe and Jessica Cuevas
* Class :       CptS 223, FAll 2019;
* Professor :   Hassan Ghasemzadeh
* Programming Assignment : PA 6
* Date :        November 23, 2019
* Description :This program has two parts.In the first part we would read two files. Once the first file is read in, it would do different insertions
*              into the hash table. Such as chaining, linear and quadratic.It will calculate the total time it took to insert, average time as well as number
*              of collisions. Once the second file is read in, it would do the searching with different hash functions such as chaining, linear and quadratic.
*              It will also calculate the total time it took to do insertion,average time. The second part would read same two files and would do the same
*              operations. However, it would do those operations with functions such as simple,prefix and full.
* File Description : This file is functions.functions.cpp. This file contains proper functions for functions.h
********************************************************************************************************************************************************/

SeparateChaining<string> ChainingHT;


LinearProbing<string> LinearHT;


QuadraticProbing<string> QuadraticHT;
QuadraticProbing<string> QuadraticFull;
QuadraticProbing<string> QuadraticPrefix;
QuadraticProbing<string> QuadraticSimple;

//variables for the first part
double InsertionTimerChainingHT = 0.0;
double InsertionTimerLinearHT = 0.0;
double InsertionTimerQuadraticHT = 0.0;

double SearchTimerChainingHT = 0.0;
double SearchTimerLinearHT = 0.0;
double SearchTimerQuadraticHT = 0.0;

int CollisionsChainingHT = 0;
int CollisionsLinearHT = 0;
int CollisionsQuadraticHT = 0;

//variables forthe second part
double InsertionTimerFull = 0.0;
int CollisionsQuadraticFull= 0;
double SearchTimerFull = 0.0;

double InsertionTimerPrefix= 0.0;
int CollisionsQuadraticPrefix = 0;
double SearchTimerPrefix = 0.0;

double InsertionTimerSimple= 0.0;
int CollisionsQuadraticSimple = 0;
double SearchTimerSimple = 0.0;

/*************************************************************************
* Function: vector<string> readTheFile(ifstream &infile)
* Date Created: November 11, 2019
* Date Last Modified: November 23, 2019
* Description: This is the file that reads data from the file and insert
*              into a vector.
* Input parameters: file name
* Returns: vector with file input.
**************************************************************************/
vector<string> readTheFile(ifstream &infile) 
{
	vector<string> vec;
	string str;
	int num = 1;
	
	while (!infile.eof()) 
	{
		getline(infile, str);
		num++;
		vec.push_back(str);
	}
	
	infile.close();
	return vec;
	
}

/*************************************************************************
* Function: void InsertIntoChainingHT(vector<string> &firstVect)
* Date Created: November 11, 2019
* Date Last Modified: November 23, 2019
* Description: This function would do insertions into chaining hash table
* Input parameters: vector
* Returns: none.
**************************************************************************/
void InsertIntoChainingHT(vector<string> &firstVect)
{
	for (vector<string>::iterator it = firstVect.begin(); it != firstVect.end(); ++it)
	{
		auto start = std::chrono::high_resolution_clock::now();
		ChainingHT.insert(*it);
		auto end = std::chrono::high_resolution_clock::now(); 
		InsertionTimerChainingHT += std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
	}
	
	CollisionsChainingHT = ChainingHT.getNumOfCollisions();
	cout << "Chaining Insertion" << endl;
	cout <<"Total time: " << InsertionTimerChainingHT << endl;
	cout<<"Average time: "<<(InsertionTimerChainingHT / firstVect.size())<<endl;
	cout << "Collisions: " << CollisionsChainingHT << endl;
	cout << endl;
}

/*************************************************************************
* Function: void InsertIntoLinearHT(vector<string> &firstVect)
* Date Created: November 11, 2019
* Date Last Modified: November 23, 2019
* Description: This function would do insertions into linear hash table
* Input parameters: vector
* Returns: none.
**************************************************************************/
void InsertIntoLinearHT(vector<string> &firstVect)/////////////!
{
	for (vector<string>::iterator it = firstVect.begin(); it != firstVect.end(); ++it)
	{
		auto start = std::chrono::high_resolution_clock::now();
		LinearHT.insert(*it);
		auto end = std::chrono::high_resolution_clock::now();
		InsertionTimerLinearHT += std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
        CollisionsLinearHT += LinearHT.getCollisions();
	}

    cout << "Linear Probing Insertion" << endl;
    cout << "Total time: " << InsertionTimerLinearHT << endl;
    cout << "Average time: " << (InsertionTimerLinearHT / firstVect.size()) << endl;
    cout << "Collisions: " << CollisionsLinearHT << endl;
    cout << endl;
}



/*************************************************************************
* Function: void InsertIntoQuadraticHT(vector<string> &firstVect, int val)
* Date Created: November 11, 2019
* Date Last Modified: November 23, 2019
* Description: This function would do insertions into quadratic hash table
* Input parameters: vector
* Returns: none.
**************************************************************************/
void InsertIntoQuadraticHT(vector<string> &firstVect, int val)
{
	for (vector<string>::iterator it = firstVect.begin(); it != firstVect.end(); ++it)
	{
			auto start = std::chrono::high_resolution_clock::now();
			QuadraticHT.insert(*it, 3);
			auto end = std::chrono::high_resolution_clock::now();
			InsertionTimerQuadraticHT += std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
			CollisionsQuadraticHT += QuadraticHT.getCollisions();
	}
	cout << "Quadratic Probing Insertion" << endl;
	cout << "Total time: " << InsertionTimerQuadraticHT << endl;
	cout << "Average time: " << (InsertionTimerQuadraticHT / firstVect.size()) << endl;
	cout << "Collisions: " << CollisionsQuadraticHT << endl;
	cout << endl;
}

/*************************************************************************
* Function: void SearchChainingHT(vector<string> &secondVect)
* Date Created: November 11, 2019
* Date Last Modified: November 23, 2019
* Description: This function would do search on the chaining hash table
* Input parameters: vector
* Returns: none.
**************************************************************************/
void SearchChainingHT(vector<string> &secondVect)
{
	for (vector<string>::iterator it = secondVect.begin(); it != secondVect.end(); ++it)
	{
		auto start = std::chrono::high_resolution_clock::now();
		ChainingHT.contains(*it);
		auto end = std::chrono::high_resolution_clock::now();
		SearchTimerChainingHT += std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
	}
	cout << "Chaining Search" << endl;
	cout << "Total time: " << SearchTimerChainingHT << endl;
	cout << "Average time: " << (SearchTimerChainingHT / secondVect.size()) << endl;
	cout << endl;
}

/*************************************************************************
* Function: void SearchLinearHT(vector<string> &secondVect)
* Date Created: November 11, 2019
* Date Last Modified: November 23, 2019
* Description: This function would do search on the linear hash table
* Input parameters: vector
* Returns: none.
**************************************************************************/
void SearchLinearHT(vector<string> &secondVect)///////////////////////!
{
	clock_t start, end;

	for (vector<string>::iterator it = secondVect.begin(); it != secondVect.end(); ++it)
	{
		auto start = std::chrono::high_resolution_clock::now();
		LinearHT.contains(*it);
		auto end = std::chrono::high_resolution_clock::now();
		SearchTimerLinearHT += std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
	}
	cout << "Linear Probing Search" << endl;
    cout << "Total time: " << SearchTimerLinearHT << endl;
    cout << "Average time: " << (SearchTimerLinearHT / secondVect.size()) << endl;
    cout << endl;
}

/*************************************************************************
* Function: void SearchQuadratic HT(vector<string> &secondVect)
* Date Created: November 11, 2019
* Date Last Modified: November 23, 2019
* Description: This function would do search on the quadratic hash table
* Input parameters: vector
* Returns: none.
**************************************************************************/
void SearchQuadraticHT(vector<string> &secondVect, int val)
{
	for (vector<string>::iterator it = secondVect.begin(); it != secondVect.end(); ++it)
	{
		auto start = std::chrono::high_resolution_clock::now();
		QuadraticHT.contains(*it,3);
		auto end = std::chrono::high_resolution_clock::now();
		SearchTimerQuadraticHT += std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
	}
	cout << "Quadratic Probing Search" << endl;
	cout << "Total time: " << SearchTimerQuadraticHT << endl;
	cout << "Average time: " << (SearchTimerQuadraticHT / secondVect.size()) << endl;
	cout << endl;
}

/*************************************************************************
* Function: void InsertIntoQuadraticPrefix(vector<string> &firstVect, int val)
* Date Created: November 11, 2019
* Date Last Modified: November 23, 2019
* Description: This function would do insertions into prefix hash table
* Input parameters: vector
* Returns: none.
**************************************************************************/
void InsertIntoQuadraticPrefix(vector<string> &firstVect, int val)
{
	for (vector<string>::iterator it = firstVect.begin(); it != firstVect.end(); ++it)
	{
			auto start = std::chrono::high_resolution_clock::now();
			QuadraticPrefix.insert(*it, 2);
			auto end = std::chrono::high_resolution_clock::now();
			InsertionTimerPrefix += std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
			CollisionsQuadraticPrefix += QuadraticPrefix.getCollisions();
	}
	cout << "Quadratic Prefix Insertion" << endl;
	cout << "Total time: " << InsertionTimerPrefix << endl;
	cout << "Average time: " << (InsertionTimerPrefix / firstVect.size()) << endl;
	cout << "Collisions: " << CollisionsQuadraticPrefix << endl;
	cout << endl;
}

/*************************************************************************
* Function: void InsertIntoQuadraticFull(vector<string> &firstVect, int val)
* Date Created: November 11, 2019
* Date Last Modified: November 23, 2019
* Description: This function would do insertions into full hash table
* Input parameters: vector
* Returns: none.
**************************************************************************/
void InsertIntoQuadraticFull(vector<string> &firstVect, int val)
{
	for (vector<string>::iterator it = firstVect.begin(); it != firstVect.end(); ++it)
	{
			auto start = std::chrono::high_resolution_clock::now();
			QuadraticFull.insert(*it, 3);
			auto end = std::chrono::high_resolution_clock::now();
			InsertionTimerFull += std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
		    CollisionsQuadraticFull += QuadraticFull.getCollisions();
	}
	cout << "Quadratic Full Insertion" << endl;
	cout << "Total time: " << InsertionTimerFull << endl;
	cout << "Average time: " << (InsertionTimerFull/ firstVect.size()) << endl;
	cout << "Collisions: " << CollisionsQuadraticFull << endl;
	cout << endl;
}

/*************************************************************************
* Function: void InsertIntoQuadraticSimple(vector<string> &firstVect, int val)
* Date Created: November 11, 2019
* Date Last Modified: November 23, 2019
* Description: This function would do insertions into simple hash table
* Input parameters: vector
* Returns: none.
**************************************************************************/
void InsertIntoQuadraticSimple(vector<string> &firstVect, int val)
{
	for (vector<string>::iterator it = firstVect.begin(); it != firstVect.end(); ++it)
	{
			auto start = std::chrono::high_resolution_clock::now();
			QuadraticSimple.insert(*it, 1);
			auto end = std::chrono::high_resolution_clock::now();
			InsertionTimerSimple += std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
			CollisionsQuadraticSimple += QuadraticSimple.getCollisions();
	}
	cout << "Quadratic Simple Insertion" << endl;
	cout << "Total time: " << InsertionTimerSimple << endl;
	cout << "Average time: " << (InsertionTimerSimple / firstVect.size()) << endl;
	cout << "Collisions: " << CollisionsQuadraticSimple << endl;
	cout << endl;
}

/*************************************************************************
* Function: void SearchQuadraticFull (vector<string> &secondVect, int val)
* Date Created: November 11, 2019
* Date Last Modified: November 23, 2019
* Description: This function would do search on the full hash table
* Input parameters: vector
* Returns: none.
**************************************************************************/
void SearchQuadraticFull(vector<string> &secondVect, int val)
{
	for (vector<string>::iterator it = secondVect.begin(); it != secondVect.end(); ++it)
	{
		auto start = std::chrono::high_resolution_clock::now();
		QuadraticFull.contains(*it, 3);
		auto end = std::chrono::high_resolution_clock::now();
		SearchTimerFull += std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
	}
	cout << "Quadratic Full Search" << endl;
	cout << "Total time: " << SearchTimerFull << endl;
	cout << "Average time: " << (SearchTimerFull / secondVect.size()) << endl;
	cout << endl;
}

/*************************************************************************
* Function: void SearchQuadraticSimple(vector<string> &secondVect, int val)
* Date Created: November 11, 2019
* Date Last Modified: November 23, 2019
* Description: This function would do search on the simple hash table
* Input parameters: vector
* Returns: none.
**************************************************************************/
void SearchQuadraticSimple(vector<string> &secondVect, int val)
{
	for (vector<string>::iterator it = secondVect.begin(); it != secondVect.end(); ++it)
	{
		auto start = std::chrono::high_resolution_clock::now();
		QuadraticSimple.contains(*it, 1);
		auto end = std::chrono::high_resolution_clock::now();
		SearchTimerSimple += std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
	}
	cout << "Quadratic Simple Search" << endl;
	cout << "Total time: " << SearchTimerSimple << endl;
	cout << "Average time: " << (SearchTimerSimple / secondVect.size()) << endl;
	cout << endl;
}

/*************************************************************************
* Function: void SearchQuadraticPrefix (vector<string> &secondVect, int val)
* Date Created: November 11, 2019
* Date Last Modified: November 23, 2019
* Description: This function would do search on the prefix hash table
* Input parameters: vector
* Returns: none.
**************************************************************************/
void SearchQuadraticPrefix(vector<string> &secondVect, int val)
{
	for (vector<string>::iterator it = secondVect.begin(); it != secondVect.end(); ++it)
	{
		auto start = std::chrono::high_resolution_clock::now();
		QuadraticPrefix.contains(*it, 2);
		auto end = std::chrono::high_resolution_clock::now();
		SearchTimerPrefix += std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
	}
	cout << "Quadratic Prefix Search" << endl;
	cout << "Total time: " << SearchTimerPrefix << endl;
	cout << "Average time: " << (SearchTimerPrefix / secondVect.size()) << endl;
	cout << endl;
}
