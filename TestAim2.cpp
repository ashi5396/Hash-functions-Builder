#include "functions.h"

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
* File Description : This file is functions.TestAim2.cpp. This file would run the second part of the program.
********************************************************************************************************************************************************/
void TestTwo(void) 
{
	
	ifstream ifs("OHenry.txt");
	vector<string> DataArray = readTheFile(ifs);
	ifstream input("queries.txt");
	vector<string> QueryArray = readTheFile(input);
	
	//Insertions
	InsertIntoQuadraticSimple(DataArray, 1);
    InsertIntoQuadraticPrefix(DataArray, 2);
	InsertIntoQuadraticFull(DataArray, 3);
	
	//Searches
	SearchQuadraticSimple(QueryArray, 1);
    SearchQuadraticPrefix(QueryArray, 2);
	SearchQuadraticFull(QueryArray, 3);	
	
}


