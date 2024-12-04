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

/*            
            Programmer jyoti = new Programmer();
            DotNetDeveloper suraj = new DotNetDeveloper();
            Console.WriteLine("Single Inheritance ");
            Console.WriteLine("jyoti's salary : "+jyoti.salary);
            Console.WriteLine("jyoti's bonus : "+jyoti.bonus+ "\n");
            Console.WriteLine("Multilevel Inheritance");
            Console.WriteLine("suraj's Insurance Cover : "+ suraj.insurance);
            Console.WriteLine("Total Equtity Valued at Year 1 : "+suraj.equity);
            Console.WriteLine("suraj's salary and bonus added : " + (suraj.salary+suraj.bonus));


            Console.WriteLine(" \n\n ");

            Console.WriteLine("Hierarchial Inheritance");
            son krishna = new son();
            daughter radha = new daughter();
            Console.WriteLine(krishna.name + " calls father as "+ krishna.father_name);
            Console.WriteLine(radha.name + " calls father as "+ radha.father_name);


            */
/*


            Student student = new Student();    //default , static
            Student student2 = new Student();    //default

            student2.Name = "Krishna";
            student2.Address = "Gokul";
            Console.WriteLine(student2.Name +" "+ student2.Address);

            Student student3 = new Student(student2);//Object Constructor



            */

            /* 1st day five questions */

            /*            MyClass obj = new MyClass();
                        Program program = new Program();
                        LabStruct StructObject = new LabStruct();
                        LabStruct EnumObject = new LabStruct();
                        LabStruct labStruct = new LabStruct();



                        obj.Hello();
                        obj.CheckOddEven();
                        obj.Sum();
                        obj.ThreeDimension();


                        /*  Classes Enums and Structures */


            /*            StructObject.MyStructFunction();
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

            */




            MyChild myChild = new MyChild();
            myChild.show();
            myChild.OverrideMethod();

            



            Console.ReadKey();

        }
    }
}
