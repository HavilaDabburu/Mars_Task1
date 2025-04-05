#include<stdio.h>//header file
#include<math.h>//library of math functions
void newpos(double *x,double *y,double *z,int ccd)//function to change the coordinates with reference of rover center
//NOTE im taking that rover turned behind the marker in z axix , we can also take it x axis
{
	*z=*z+ccd;//taking rover centre as reference
	//ccd : distance between camera and center
}
//function to calculate distance between to points
double distance(double x,double y,double z,double x1,double y1,double z1)
{
	double dist;//initialisation
	dist = sqrt((x1-x)*(x1-x)+(y1-y)*(y1-y)+(z1-z)*(z1-z));//using math fuctions
	return dist;
}
int main()
{
	double x,y,z,x1,y1,z1,c1,c2,c3;//initialisation
	int ccd = 55;//distance between camera and center
	//in this case only if we want we can make it in scanf
	printf("Enter coordinates of camera detection\n");
	scanf("%lf %lf %lf",&c1,&c2,&c3);
	double dis1,dis2;
	x=0,y=0,z=0;//initially camera is the reference point;
	//before changing;
	dis1 = distance(x,y,z,c1,c2,c3);
	//changing the reference point to rover center
	newpos(&c1,&c2,&c3,ccd);
	dis2 = distance(x,y,z,c1,c2,c3);//calculating distance
	printf("new postion of marker : %lf,%lf,%lf\n",c1,c2,c3);
	printf("intial distance between cam and marker is : %lf\n",dis1);
	printf("final distance between cam and marker is : %lf\n",dis2);
	return 0;
}
