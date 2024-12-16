using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;

namespace labOne
{
    internal class Program
    {


        static void Main(string[] args)
        {
            /* 1st day five questions */

                        DayTwoMyClass obj = new DayTwoMyClass();
                        DayTwoLabStruct StructObject = new DayTwoLabStruct();
                        DayTwoLabStruct EnumObject = new DayTwoLabStruct();
                        DayTwoLabStruct labStruct = new DayTwoLabStruct();



                        obj.Hello();
                        obj.CheckOddEven();
                        obj.Sum();
                        obj.ThreeDimension();


                        /*  Classes Enums and Structures */


                        StructObject.MyStructFunction();
                        EnumObject.EnumFunction();

                        StaticCLass.Display();

                        labStruct.NamedFunction();

                        int x = 10;
                        Console.WriteLine(x);
                        labStruct.RefFunction(ref x);
                        Console.WriteLine(x);

                        int x1, x2, x3;
                        labStruct.OutFucntion(out x1, out x2, out x3);
                        Console.WriteLine($"{x1} {x2} {x3}");

                        Console.WriteLine("\n\nPress any key to Exit");
                        Console.ReadKey();
        }
            
     
    }
}

