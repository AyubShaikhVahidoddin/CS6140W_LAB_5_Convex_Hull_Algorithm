//============================================================================
// Name        : ConvexHull.cpp
// Author      : AYUB SHAIKH VAHIDODDIN
// ROLL Num    : CS21M515
// Copyright   : @2022 - Assignment IIT Madras.
// Description : ConvexHull Algorithm in C++, Ansi-style

// Date: 6-May-2022
//============================================================================

#include <iostream>
using namespace std;

#include <iostream>
using namespace std;
#define INF 10000


struct PointsOnAxis
{
        int point_x;
        int point_y;
};


int pointsOfOrientations(PointsOnAxis point_A, PointsOnAxis point_B, PointsOnAxis point_C)
{
    int value = (point_B.point_y - point_A.point_y) * (point_C.point_x - point_B.point_x) - (point_B.point_x - point_A.point_x) * (point_C.point_y - point_B.point_y);
    if (value == 0)
    {
        return 0;
    }
    return (value > 0) ? 1 : 2;
}

 bool pointsValidation(int numberOfPoints){
if (numberOfPoints < 3){

	cout << "------Points can not be less than 3 please enter more points/Data-------" << endl;

       return true;
   }
}

// this is Convex HUll Algorithm code
void convexHullAlgorithms(PointsOnAxis points[], int numberOfPoints)
{
	// if number of point less than 3 then just retun no need to do convex hull
	if(pointsValidation(numberOfPoints))
	{
	    return;
	}

    // integer array to store the points
    int next[numberOfPoints];

    // for loop
    for (int index = 0; index < numberOfPoints; index++)
    {
        next[index] = -1;
    }

    int k_point = 0;

    // for loop
    for (int index = 1; index < numberOfPoints; index++)
        if (points[index].point_x < points[k_point].point_x)
        	k_point = index;
    int pt = k_point, dataPoint;



    do
    {
    	dataPoint = (pt + 1) % numberOfPoints;
        for (int index = 0; index < numberOfPoints; index++)
            if (pointsOfOrientations(points[pt], points[index], points[dataPoint]) == 2)
            	dataPoint = index;
        next[pt] = dataPoint;
        pt = dataPoint;

    }
    while (pt != k_point);   // do while loop to caluclate convex hull points
    for (int index = 0; index < numberOfPoints; index++)
    {
        if (next[index] != -1)
            cout << "(" << points[index].point_x << ", " << points[index].point_y << ")\n";
    }
}


///////////Main method code, program
int main()
{

	 cout << "-----------------------------------------------------------------" << endl;
	 cout << "--------LAB Programming Assignment-5 *************************" << endl;
	 cout << "******* Implement the convex hull algorithm. in C++----------\n" << endl;

	 cout << "Submitted By: Name- AYUB SHAIKH VAHIDODDIN" << endl;

	 cout << "by Roll number: CS21M515" << endl;
	 cout << "Email Id :- Ayub.Shaikh.Vahid@gmail.com" << endl;
	 cout << "-----------------------------------------------------------------" << endl;


	int number_Of_points = 0;

	    cout<<"Number of Points : "<<endl;
	    cin>> number_Of_points;



    int dataPointsArray[20][2] ={0};
        for (int index=0;index<number_Of_points;index++)
        {
            cout<< "\nEnter the point "<< index+1 <<endl;
            cin >> dataPointsArray[index][0] >> dataPointsArray[index][1];
        }

        PointsOnAxis pointsCoordinates[] = {};

            cout<< "\nGiven coordinates : \n";

                 for (int index = 0;index< number_Of_points; index++)
            {
                 cout<<"("<<pointsCoordinates[index].point_x << ","<<pointsCoordinates[index].point_y<<"), \n\n";

             }

    cout << " \n The points in the convex hull are as follows: \n";


    convexHullAlgorithms(pointsCoordinates, number_Of_points);


	// if number of point less than 3 then just retun no need to do convex hull


    cout << " \n ----------------------END Thank You!-----------------------" << endl;
         cout << "-----------------------------------------------------------" << endl;
         int exit;
         cout << "press any number to exit: ";
         cin >> exit;
         if(exit>0)
         {
           	   return 0;
         }


//    if (numberOfPoints < 3){
//        return;
//    }
//
//    int next[numberOfPoints];
//
//    for (int index = 0; index < numberOfPoints; index++)
//    {
//        next[index] = -1;
//    }
//
//    int k_point = 0;
//
//    for (int index = 1; index < numberOfPoints; index++)
//        if (points[index].point_x < points[k_point].point_x)
//        	k_point = index;
//    int pt = k_point, q;
//    do
//    {
//        q = (pt + 1) % numberOfPoints;
//        for (int index = 0; index < numberOfPoints; index++)
//            if (pointsOfOrientations(points[pt], points[index], points[q]) == 2)
//                q = index;
//        next[pt] = q;
//        pt = q;
//    }
//    while (pt != k_point);
//    for (int index = 0; index < numberOfPoints; index++)
//    {
//        if (next[index] != -1)
//            cout << "(" << points[index].point_x << ", " << points[index].point_y << ")\n";
//    }



}
