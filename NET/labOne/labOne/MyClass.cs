using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace labOne
{
    internal class MyClass
    {
        /*
       Create a function of Each Topic:
           1) Display Hello World five times in C#.
           2) Take a number from user and check even or odd number.
           3) Take two numbers and display sum eg.sum of 2 and 3 is 5.
           4) Create a three dimensional array and show the elements.
           5) Create a Jagged Array and show the elements.
*/

        /* 1) Display Hello World five times in C#. */
        public void Hello()
        {
            for (int i = 0; i < 5; i++)
            {
                Console.WriteLine("Hello World");
            }
            Console.WriteLine("\n\n");
        }

        /* 2) Take a number from user and check even or odd number  */
        public void CheckOddEven()
        {
            Console.WriteLine("Enter a number to check Even or Odd");
            int i = Convert.ToInt32(Console.ReadLine());
            if (i % 2 == 0)
            {
                Console.WriteLine("Number is Even");
            }
            else
            {
                Console.WriteLine("Number is Odd");
            }
            Console.WriteLine("\n\n");

        }

        /*3) Take two numbers and display sum eg.sum of 2 and 3 is 5.*/
        public void Sum()
        {
            Console.WriteLine("Enter two numbers to perform Addition");
            int numOne = Convert.ToInt32(Console.ReadLine());
            int numTwo = Convert.ToInt32(Console.ReadLine());
            Console.WriteLine($"The sum of {numOne} and {numTwo} is :{(numOne + numTwo)}");
            Console.WriteLine("\n\n");
        }


        /*4) Create a three dimensional array and show the elements.*/
        public void ThreeDimension()
        {
            int[,,] ThreeDimArray = new int[2, 3, 4]
            {
                {
                    {2,64,12,60 },{96,29,67,44 },{89,23,13,92 }
                },
                {
                    {55,45,78,65},{2,64,12,90},{96,29,4,43}
                }
            };

            for (int i = 0; i < 2; i++)
            {
                Console.WriteLine(" ");
                for (int j = 0; j < 3; j++)
                {
                    Console.WriteLine(" ");
                    for (int k = 0; k < 4; k++)
                    {
                        Console.Write($"{ThreeDimArray[i, j, k]} ");
                    }
                }
            }
            Console.WriteLine("\n\n");


        }

        /*5) Create a Jagged Array and show the elements.*/
        public void JaggedArray()
        {
            int[][] arrTop = new int[3][]
            {
               new int [6] { 9 , 8 ,7 ,2 ,3 , 1 },
               new int [1] {1} ,
               new int [3]  {9, 4, 5 }
            };

        }

    /*public void Main()
    {
            MyClass obj = new MyClass();
            
             obj.Hello();
            obj.CheckOddEven();
            obj.Sum();
            obj.ThreeDimension();
             

        }*/
    }
}
