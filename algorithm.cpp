

#include "algorithm.h"
#include "BFSWithoutVList.h"
#include "BFSWithVList.h"
#include "PDSWithoutVList.h"
#include "PDS_NoStrictList.h"
#include "AStar.h"

using namespace std;



///////////////////////////////////////////////////////////////////////////////////////////
//
// Search Algorithm:  Breadth-First Search 
//
// Move Generator:  
//
////////////////////////////////////////////////////////////////////////////////////////////
string breadthFirstSearch(string const initialState, string const goalState, int &numOfStateExpansions, int& maxQLength, float &actualRunningTime){
    string path;
	clock_t startTime;
    //add necessary variables here
    startTime = clock();
    BFSWithoutVList BFS = BFSWithoutVList(initialState,goalState);
    numOfStateExpansions = BFS.myQueue.size();
    maxQLength = BFS.max_myQueue_length;
    path = BFS.final_path;

//***********************************************************************************************************
	actualRunningTime = ((float)(clock() - startTime)/CLOCKS_PER_SEC);
	//path = "DDRRLLLUUU";  //this is just a dummy path for testing the function           
	return path;		
		
}

///////////////////////////////////////////////////////////////////////////////////////////
//
// Search Algorithm:  Breadth-First Search with VisitedList
//
// Move Generator:  
//
////////////////////////////////////////////////////////////////////////////////////////////
string breadthFirstSearch_with_VisitedList(string const initialState, string const goalState, int &numOfStateExpansions, int& maxQLength, float &actualRunningTime){
    string path;
	clock_t startTime;
    //add necessary variables here
    startTime = clock();
    BFSWithVList BFS = BFSWithVList(initialState,goalState);
    numOfStateExpansions = BFS.visited.size();
    maxQLength = BFS.max_myQueue_length;
    path = BFS.final_path;

//***********************************************************************************************************
	actualRunningTime = ((float)(clock() - startTime)/CLOCKS_PER_SEC);
	//path = "DDRRLLLUUU";  //this is just a dummy path for testing the function           
	return path;		
		
}

///////////////////////////////////////////////////////////////////////////////////////////
//
// Search Algorithm:  
//
// Move Generator:  
//
////////////////////////////////////////////////////////////////////////////////////////////
string progressiveDeepeningSearch_No_VisitedList(string const initialState, string const goalState, int &numOfStateExpansions, int& maxQLength, float &actualRunningTime, int ultimateMaxDepth){
    string path;
	clock_t startTime;
    //add necessary variables here
    startTime = clock();
    PDSWithoutVList DPS_NoVList = PDSWithoutVList(initialState,goalState);
    maxQLength = DPS_NoVList.max_myS_length;
    numOfStateExpansions = DPS_NoVList.expanded;
    ultimateMaxDepth = DPS_NoVList.max_depth;
    path = DPS_NoVList.final_path;

//***********************************************************************************************************
	actualRunningTime = ((float)(clock() - startTime)/CLOCKS_PER_SEC);
	//path = "DDRRLLLUUU";  //this is just a dummy path for testing the function           
	return path;		
		
}
	
///////////////////////////////////////////////////////////////////////////////////////////
//
// Search Algorithm:  
//
// Move Generator:  
//
////////////////////////////////////////////////////////////////////////////////////////////
string progressiveDeepeningSearch_with_NonStrict_VisitedList(string const initialState, string const goalState, int &numOfStateExpansions, int& maxQLength, float &actualRunningTime, int ultimateMaxDepth){
    string path;
	clock_t startTime;
    //add necessary variables here
    startTime = clock();

    PDS_NoStrictList DPS_NSList = PDS_NoStrictList(initialState,goalState);
    numOfStateExpansions = DPS_NSList.visited.size();
    maxQLength = DPS_NSList.max_myS_length;
    ultimateMaxDepth = DPS_NSList.max_depth;
    path = DPS_NSList.final_path;

//***********************************************************************************************************
    actualRunningTime = ((float)(clock() - startTime)/CLOCKS_PER_SEC);
	//path = "DDRRLLLUUU"; //this is just a dummy path for testing the function	
	return path;				
}
	

string aStar_ExpandedList(string const initialState, string const goalState, int &numOfStateExpansions, int& maxQLength, 
                               float &actualRunningTime, int &numOfDeletionsFromMiddleOfHeap, int &numOfLocalLoopsAvoided, int &numOfAttemptedNodeReExpansions, heuristicFunction heuristic){
											 
   string path;
   clock_t startTime;
   
   numOfDeletionsFromMiddleOfHeap=0;
   numOfLocalLoopsAvoided=0;
   numOfAttemptedNodeReExpansions=0;

	actualRunningTime=0.0;	
	startTime = clock();

	maxQLength=0;
	if(heuristic == manhattanDistance)
	{

		Astar<MisplacedTiles> astar = Astar<MisplacedTiles>
		{
			initialState,goalState
		};
		numOfStateExpansions = astar.expanded;
		maxQLength = astar.max_myQueue_length;
		actualRunningTime = ((float)(clock() - startTime)/CLOCKS_PER_SEC);
		path = astar.final_path;
		return path;
	}
	else
	{

		Astar<ManhattanDistance> astar = Astar<ManhattanDistance>
		{
			initialState, goalState
		};
		numOfStateExpansions = astar.expanded;
		maxQLength = astar.max_myQueue_length;
		actualRunningTime = ((float)(clock() - startTime)/CLOCKS_PER_SEC);
		path = astar.final_path;
		return path;
	}	
}

