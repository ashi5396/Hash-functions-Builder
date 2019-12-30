#pragma once
#include "SeparateChaining.h"
#include "QuadraticProbing.h"
#include "LinearProbing.h"
#include <string>
#include <cstring>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <ctime>

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
* File Description : This file is functions.h. This file holds appropriate function protypes for functions.
********************************************************************************************************************************************************/
using namespace std;

/*************************************************************************
* Function: vector<string> readTheFile(ifstream &infile)
* Date Created: November 11, 2019
* Date Last Modified: November 23, 2019
* Description: This is the file that reads data from the file and insert
*              into a vector.
* Input parameters: file name
* Returns: vector with file input.
**************************************************************************/
vector<string> readTheFile(ifstream &infile);

/*************************************************************************
* Function: void InsertIntoChainingHT(vector<string> &firstVect)
* Date Created: November 11, 2019
* Date Last Modified: November 23, 2019
* Description: This function would do insertions into chaining hash table
* Input parameters: vector
* Returns: none.
**************************************************************************/
void InsertIntoChainingHT(vector<string> &firstVect);

/*************************************************************************
* Function: void InsertIntoLinearHT(vector<string> &firstVect)
* Date Created: November 11, 2019
* Date Last Modified: November 23, 2019
* Description: This function would do insertions into linear hash table
* Input parameters: vector
* Returns: none.
**************************************************************************/
void InsertIntoLinearHT(vector<string> &firstVect);/////////////!

/*************************************************************************
* Function: void InsertIntoQuadraticHT(vector<string> &firstVect, int val)
* Date Created: November 11, 2019
* Date Last Modified: November 23, 2019
* Description: This function would do insertions into quadratic hash table
* Input parameters: vector
* Returns: none.
**************************************************************************/
void InsertIntoQuadraticHT(vector<string> &firstVect, int val);

/*************************************************************************
* Function: void SearchChainingHT(vector<string> &secondVect)
* Date Created: November 11, 2019
* Date Last Modified: November 23, 2019
* Description: This function would do search on the chaining hash table
* Input parameters: vector
* Returns: none.
**************************************************************************/
void SearchChainingHT(vector<string> &secondVect);

/*************************************************************************
* Function: void SearchLinearHT(vector<string> &secondVect)
* Date Created: November 11, 2019
* Date Last Modified: November 23, 2019
* Description: This function would do search on the linear hash table
* Input parameters: vector
* Returns: none.
**************************************************************************/
void SearchLinearHT(vector<string> &secondVect);///////////////!

/*************************************************************************
* Function: void SearchQuadratic HT(vector<string> &secondVect)
* Date Created: November 11, 2019
* Date Last Modified: November 23, 2019
* Description: This function would do search on the quadratic hash table
* Input parameters: vector
* Returns: none.
**************************************************************************/
void SearchQuadraticHT(vector<string> &secondVect, int val);

/*************************************************************************
* Function: void InsertIntoQuadraticFull(vector<string> &firstVect, int val)
* Date Created: November 11, 2019
* Date Last Modified: November 23, 2019
* Description: This function would do insertions into full hash table
* Input parameters: vector
* Returns: none.
**************************************************************************/
void InsertIntoQuadraticFull(vector<string> &firstVect, int val);

/*************************************************************************
* Function: void InsertIntoQuadraticSimple(vector<string> &firstVect, int val)
* Date Created: November 11, 2019
* Date Last Modified: November 23, 2019
* Description: This function would do insertions into simple hash table
* Input parameters: vector
* Returns: none.
**************************************************************************/
void InsertIntoQuadraticSimple(vector<string> &firstVect, int val);

/*************************************************************************
* Function: void InsertIntoQuadraticPrefix(vector<string> &firstVect, int val)
* Date Created: November 11, 2019
* Date Last Modified: November 23, 2019
* Description: This function would do insertions into prefix hash table
* Input parameters: vector
* Returns: none.
**************************************************************************/
void InsertIntoQuadraticPrefix(vector<string> &firstVect, int val);

/*************************************************************************
* Function: void SearchQuadraticFull (vector<string> &secondVect, int val)
* Date Created: November 11, 2019
* Date Last Modified: November 23, 2019
* Description: This function would do search on the full hash table
* Input parameters: vector
* Returns: none.
**************************************************************************/
void SearchQuadraticFull (vector<string> &secondVect, int val);

/*************************************************************************
* Function: void SearchQuadraticSimple(vector<string> &secondVect, int val)
* Date Created: November 11, 2019
* Date Last Modified: November 23, 2019
* Description: This function would do search on the simple hash table
* Input parameters: vector
* Returns: none.
**************************************************************************/
void SearchQuadraticSimple(vector<string> &secondVect, int val);

/*************************************************************************
* Function: void SearchQuadraticPrefix (vector<string> &secondVect, int val)
* Date Created: November 11, 2019
* Date Last Modified: November 23, 2019
* Description: This function would do search on the prefix hash table
* Input parameters: vector
* Returns: none.
**************************************************************************/
void SearchQuadraticPrefix(vector<string> &secondVect, int val);


