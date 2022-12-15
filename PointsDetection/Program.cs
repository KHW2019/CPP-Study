namespace PointsDetection
{
    class Program
    {

        //Shows the number of points inside the circle;
        //outer > inter
        public static int[] pointOfCircle(int inner, int outer, int[] PointX, int[] PointY)
        {

            //Inner Circle Variables
            int InnerRaduis = inner;
            int InnerCenterX = 0;
            int InnerCenterY = 0;
            int InnerRaduisSquare = InnerRaduis * InnerRaduis;
            int NumberOfPointsInInner = 0;

            //Outer Circle Variables
            int OuterRaduis = outer;
            int OuterCenterX = 0;
            int OuterCenterY = 0;
            int OuterRaduisSquare = OuterRaduis * OuterRaduis;
            int NumberOfPointsInOuter = 0;

            //jagged array
            int[][] PointXY = { PointX, PointY };

            //Two-dimensional array
            int[,] array2D = new int[Math.Max(PointX.Length, PointY.Length), 2];

            //add pointX values to row 0
            for (int i = 0; i < PointX.Length; i++)
            {
                array2D[i, 0] = PointX[i];
            }

            //add pointY values to row 1
            for (int i = 0; i < PointY.Length; i++)
            {
                array2D[i, 1] = PointY[i];
            }


            //debug check is the values added to the array
            // for (int i = 0; i < array2D.GetLength(0); i++)
            // {
            //     for (int j = 0; j < array2D.GetLength(1); j++)
            //     {

            //         Console.Write(array2D[i,j] + "\t");
            //     }
            //     Console.WriteLine();
            // }


            for (int i = 0; i < array2D.GetLength(0); i++)
            {
                int InnerDistanceX = array2D[i, 0] - InnerCenterX;
                int InnerDistanceY = array2D[i, 1] - InnerCenterY;

                int InnerDistance = (int)(Math.Pow(InnerDistanceX, 2) + Math.Pow(InnerDistanceY, 2));
                // Console.WriteLine(InnerDistanceX);
                // Console.WriteLine(InnerDistanceY);
                //  Console.WriteLine(InnerDistance);

                int OuterDistacneX = array2D[i, 0] - OuterCenterX;
                int OuterDistanceY = array2D[i, 1] - OuterCenterY;

                int OuterDistance = (int)(Math.Pow(OuterDistacneX, 2) + Math.Pow(OuterDistanceY, 2));

                // Console.WriteLine(OuterDistacneX);
                // Console.WriteLine(OuterDistanceY);
                //  Console.WriteLine(OuterDistance);

                if (InnerDistance <= InnerRaduisSquare)
                {
                    NumberOfPointsInInner++;
                }

                if (OuterDistance <= OuterRaduisSquare)
                {
                    NumberOfPointsInOuter++;
                }
            }


            //Distance Formula (pointx - centerX) ^ 2 + (Pointy - centerY) ^ 2  

            //For This example:
            //int InnerDistance = (int)(Math.Pow(PointX, 2) + Math.Pow(PointY, 2));

            //number of points in inner circle
            // for (int i = 0; i < 5; i++)
            // {
            //     int InnerDistanceX = PointX[i] - InnerCenterX;
            //     //Console.WriteLine(InnerDistanceX);
            //     int InnerDistanceY = PointY[i] - InnerCenterY;
            //     //Console.WriteLine(InnerDistanceY);

            //     int InnerDistance = (int)(Math.Pow(InnerDistanceX, 2) + Math.Pow(InnerDistanceY, 2));
            //     //Console.WriteLine(InnerDistance);

            //     if (InnerDistance <= InnerRaduisSquare)
            //     {
            //         NumberOfPointsInInner++;
            //     }
            // }

            // //number of points in outer circle 
            // for (int j = 0; j < 5; j++)
            // {
            //     int OuterDistacneX = PointX[j] - OuterCenterX;

            //     int OuterDistanceY = PointY[j] - OuterCenterY;

            //     //Console.WriteLine(OuterDistacneX);
            //     //Console.WriteLine(OuterDistanceY);

            //     int OuterDistance = (int)(Math.Pow(OuterDistacneX, 2) + Math.Pow(OuterDistanceY, 2));
            //     //Console.WriteLine(OuterDistance);

            //     if (OuterDistance <= OuterRaduisSquare)
            //     {
            //         NumberOfPointsInOuter++;
            //     }
            // }

            //Using jagged array
            // for (int i = 0; i < 5; i++)
            // {
            //    //InnerDistance
            //    int InnerDistanceX = PointXY[0][i] - InnerCenterX;
            //    int InnerDistanceY = PointXY[1][i] - InnerCenterY;

            //    int InnerDistance = (int)(Math.Pow(InnerDistanceX, 2) + Math.Pow(InnerDistanceY, 2));

            //    //debug
            //    //Console.WriteLine(InnerDistanceX);
            //    //Console.WriteLine(InnerDistanceY);
            //     // Console.WriteLine(InnerDistance);


            //    //OuterDistance
            //    int OuterDistacneX = PointXY[0][i] - OuterCenterX;
            //    int OuterDistanceY = PointXY[1][i] - OuterCenterY;

            //    int OuterDistance = (int)(Math.Pow(OuterDistacneX, 2) + Math.Pow(OuterDistanceY, 2));

            //    // debug
            //    //Console.WriteLine(OuterDistacneX);
            //    //Console.WriteLine(OuterDistanceY);
            //     // Console.WriteLine(OuterDistance);

            //    if (InnerDistance <= InnerRaduisSquare)
            //    {
            //        NumberOfPointsInInner++;
            //    }

            //    if (OuterDistance <= OuterRaduisSquare)
            //    {
            //        NumberOfPointsInOuter++;
            //    }
            // }

            //Calculate how many points that only part of outer circle
            int PointsOnlyInOuter = NumberOfPointsInOuter - NumberOfPointsInInner;

            //debug
            //Console.WriteLine(NumberOfPointsInOuter);
            //Console.WriteLine(NumberOfPointsInInner);

            int[] results = new int[3];

            results[0] = NumberOfPointsInInner;
            results[1] = NumberOfPointsInOuter;
            results[2] = PointsOnlyInOuter;

            return results;
        }


        public static void Main(string[] args)
        {
            int inner = 7;
            int outer = 15;

            int[] PointX = new int[5] { 1, 3, 5, 7, 9 };
            int[] PointY = new int[5] { 2, 4, 6, 8, 10 };

            var result = pointOfCircle(inner, outer, PointX, PointY);

            Console.WriteLine("Number Of Points in Inner Circle: " + result[0]);
            Console.WriteLine("Number Of Points in Outer Circle: " + result[1]);
            Console.WriteLine("Number Of Points Only in Outer Circle: " + result[2]);

        }
    }
}
