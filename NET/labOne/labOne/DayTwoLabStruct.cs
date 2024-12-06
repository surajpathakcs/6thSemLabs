using System;
using System.Collections.Generic;
using System.Linq;
using System.Security.Policy;
using System.Text;
using System.Threading.Tasks;

namespace labOne
{
    static class StaticCLass { 
    public static void Display()
    {
        Console.WriteLine("\nThis is a Static Class");
        Console.WriteLine("\n\n");

        }
    }
    struct MyStruct
    {
        public string Name;
        public string Address;
        public void StructFunction()
        {
            Console.WriteLine("\nThis is a struct function");
            Console.WriteLine("\n\n");

        }
    }

    enum WeekDays
    {
        Sunday,
        Monday,
        Tuesday,
        Wednesday,
        Thursday,
        Friday,
        Saturday
    }

    internal class DayTwoLabStruct
    {
        public void NamedFunction(string a = "sudipa" , string b = "jordan" , string c = "sita")
        {
            Console.WriteLine($"{a} {b} {c}");
            Console.WriteLine("\n\n");

        }

        public void RefFunction(ref int a)
        {
            a = 20;
        }
        public void OutFucntion(out int a, out int b, out int c) {
            a = 3;
            b= 4;
            c = a*b;
        }

        public void EnumFunction()
        {
            Console.WriteLine(WeekDays.Sunday);
            Console.WriteLine(WeekDays.Monday);
            Console.WriteLine((int)WeekDays.Sunday);
            Console.WriteLine((int)WeekDays.Monday);
            Console.WriteLine((WeekDays)4);

        }

        public void MyStructFunction()
        {
            MyStruct str = new MyStruct();
            str.Name = "sudipa amgai";
            str.Address = "gorkha";

            Console.WriteLine(str.Name);
            Console.WriteLine(str.Address);

            str.StructFunction();
        }
        




    }
}
