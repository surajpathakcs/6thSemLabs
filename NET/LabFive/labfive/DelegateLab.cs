using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace labfive
{
    public delegate void Calculation(int a , int b);
    public delegate void Calculation1(int a);
    class DelegateTest { 
        public void Add(int a , int b) { 
            Console.WriteLine("Delegate Add :");
            Console.WriteLine(a + b );
        }

        public void Sub(int a , int b) {
            Console.WriteLine("Delegate Sub :");
            Console.WriteLine(a - b );

        }

        public void Area(int a)
        {
            Console.WriteLine("Delegate Area :");
            Console.WriteLine(a * a);
        }
    }

}
