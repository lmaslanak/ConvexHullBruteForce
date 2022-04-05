// Algoritmy I 2022
// HW 03
// Lukas Maslanak, MAS174

#include <math.h>
#include <iostream>
#include <vector>

using namespace std;

struct Point
{
	int a = 0;
	float x = 0;
	float y = 0;
};

void convex(Point points[], int n){
	int i;
    if (n < 3) {        
        cout << "Musi byt minimalne 3 body!"<< endl;    
        return;
    }   	
    //nalezeni nejkrajnejsiho bodu vlevo na ose x
    int j = 0;
	for (int i = 1; i < n; i++)
		if (points[i].x < points[j].x)
			j = i;
   
    vector<Point> hull;
    int p = j;
	int q = 0;
	do
	{
		
		hull.push_back(points[p]);
		q = (p+1)%n;
		for (int i = 0; i < n; i++)
		{
				float a = (points[q].y - points[p].y);
    			float b = (points[p].x - points[q].x);
    			float c = (points[p].x * points[q].y - points[p].y * points[q].x);
				if (i != p && i != q){
    				float c0 = points[i].x * a + points[i].y * b;
					if (c0 > c){
						q = i;}
				}
		}
		
		p = q;
	} while (p != j);	

	cout << "Konvexni obal je tvoren mnozinou indexu: {";
	for (int i = 0; i < hull.size(); i++){	
		cout << hull[i].a;	
			if (i < (hull.size() - 1)){
            cout << ", ";
			 }
	}
	cout << "} " << endl;
}


int main(int argc, char * argv[]){
	Point points[] =	{{0, 35.850, 26.850}, {1, 52.875, 10.875},
						{2, 72.750, 70.650}, {3, 21.900, 28.650},
						{4, 53.850, 67.125}, {5, 50.025, 22.425}, 
						{6, 2.625, 67.050}, {7, 41.025, 48.300},
						{8, 23.700, 2.625}, {9, 14.250, 63.150},
						{10, 16.500, 7.950}, {11, 19.800, 48.600}, 
						{12, 33.450, 60.375}, {13, 66.750, 54.675},
						{14, 0.450, 7.575}, {15, 6.300, 71.550},
						{16, 69.675, 40.575}, {17, 1.575, 55.875},
						{18, 69.300, 5.400}, {19, 7.275, 38.400},
                    	{20, 73.950, 21.750}, {21, 49.125, 43.050},
						{22, 2.325, 3.900}};
	
	int n = sizeof(points)/sizeof(points[0]);
    
    convex(points, n);

    return 0;
}
