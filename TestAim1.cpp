#include "functions.h"
#include "Tests.h"

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
* File Description : This file is functions.TestAim1.cpp. This file would run the second part of the program.
********************************************************************************************************************************************************/
void TestOne() 
{

	//Open two files for reading
	ifstream ifs  ("OHenry.txt");
	vector<string> DataArray = readTheFile(ifs);
	ifstream input("queries.txt");
	vector<string> QueryArray = readTheFile(input);
	
	//Do insertions
	InsertIntoChainingHT(DataArray);
	InsertIntoLinearHT(DataArray);
	InsertIntoQuadraticHT(DataArray, 3);

	//Do searching
	SearchChainingHT(QueryArray);
	SearchLinearHT(QueryArray);
	SearchQuadraticHT(QueryArray,3);

}


