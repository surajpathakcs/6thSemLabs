using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace labfive
{
    internal class Program
    {
        static void Main(string[] args)
        {

            linq linq = new linq(); //linq constructor call
            


            DelegateTest delegateObj = new DelegateTest();
            Calculation call = new Calculation(delegateObj.Add);
            Calculation1 callArea = new Calculation1(delegateObj.Area);
            call(17, 26);
            call = delegateObj.Sub;
            call(17, 26);
            callArea(17);


            Console.ReadKey();


        }
    }
}

            
            