using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace labOne
{
    class MyParent
    {
        public virtual void OverrideMethod()
        {
            Console.WriteLine("Virtual Parent");
        }
        public void show()
        {
            Console.WriteLine("This is Parent");
        }
    }

    class MyChild : MyParent
    {
        public override void OverrideMethod()
        {
            Console.WriteLine("Override Child");
        }
        public new void show()
        {
            Console.WriteLine("This is Child");
            base.show();
        }

    }
        
}
