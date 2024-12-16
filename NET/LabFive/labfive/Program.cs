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

            linq linq = new linq();


            Console.ReadKey();


        }
    }
}

            /*
            DelegateTest delegateObj = new DelegateTest();
            Calculation call = new Calculation(delegateObj.Add);
            Calculation1 call2 = new Calculation1(delegateObj.Area);
            call(17, 26);   
            call = delegateObj.Sub;
            call(17, 26);
            call2(17);*/