#include<stdio.h>//header file
#include<math.h>//math library for math operations
struct quaternion//defining a structure for quternion
{
    double w,x,y,z;//double axes
}q;
struct quaternion etq(double x,double y,double z)//function having return type struct
{
    //math formulea for conversion
    q.w = cos(x/2)*cos(z/2)*cos(y/2) + sin(x/2)*sin(y/2)*sin(z/2);
    q.x = sin(x/2)*cos(z/2)*cos(y/2) - cos(x/2)*sin(y/2)*sin(z/2);
    q.y = cos(x/2)*cos(z/2)*sin(y/2) + sin(x/2)*cos(y/2)*sin(z/2);
    q.z = cos(x/2)*sin(z/2)*cos(y/2) - sin(x/2)*sin(y/2)*cos(z/2);
    return q;
}
//main function
int main()
{
    struct quaternion Q;//initialization
    printf("enter euler's angles(roll,pitch,yaw):\n");
    double x,y,z;
    //taking input
    scanf("%lf %lf %lf",&x,&y,&z);
    Q = etq(x,y,z);//decleration
    printf("the Quaternion angles are :");
    //printing quaternion angles
    printf("(%lf,%lf,%lf,%lf)\n",Q.w,Q.x,Q.y,Q.z);
}
