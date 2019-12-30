#pragma once
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
* File Description : This file is functions.Test.h. This file would call the main two functions.
********************************************************************************************************************************************************/

/*************************************************************************
* Function: void TestOne();
* Date Created: November 11, 2019
* Date Last Modified: November 23, 2019
* Description: This function would do the first part of the program
* Input parameters: vector
* Returns: none.
**************************************************************************/
void TestOne();

/*************************************************************************
* Function: void TestTwo();
* Date Created: November 11, 2019
* Date Last Modified: November 23, 2019
* Description: This function would do the second part of the program
* Input parameters: vector
* Returns: none.
**************************************************************************/
void TestTwo();