#include <iostream>
using namespace std;
int result;

void PointDetection(int Inner,int Outer, int* pointX, int* pointY) {
    
    int InnerRaduis = Inner;
    int InnerCenterX = 0;
    int InnerCenterY = 0;
    int InnerRaduisSq = sqrt(InnerRaduis);
    int NumberOfPointsInInner = 0;

    int OuterRaduis = Outer;
    int OuterCenterX = 0;
    int OuterCenterY = 0;
    int OuterRaduisSq = sqrt(OuterRaduis);
    int NOPIOuter = 0;

    for (int i = 0; i < 5; i++) {
        int InnerDistanceX = pointX[i] - InnerCenterX;
        int InnerDistanceY = pointY[i] - InnerCenterY;

        int InnerDistance = sqrt(InnerDistanceX) + sqrt(InnerDistanceY);

        if (InnerDistance <= InnerRaduisSq) {
            NumberOfPointsInInner++;
        }
    }

    for (int j = 0; j < 5; j++) {
        int OuterDistanceX = pointX[j] - OuterCenterX;
        int OuterDistanceY = pointY[j] - OuterCenterY;

        int OuterDistance = sqrt(OuterDistanceX) + sqrt(OuterDistanceY);

        if (OuterDistance <= OuterRaduisSq) {
            NOPIOuter++;
        }
    }

    cout << "Number Of Points in Inner Circle: " << NumberOfPointsInInner << endl;
    cout << "Number Of Points in Outer Circle: " << NOPIOuter << endl;
}


int main()
{
    int inner = 20;
    int outer = 35;

    int* pointX = new int[5]{ 1,3,5,7,9 };
    int* pointY = new int[5]{ 2,4,6,8,10 };

    PointDetection(inner, outer, pointX, pointY);

}
