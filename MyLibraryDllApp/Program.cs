using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Runtime.InteropServices;

namespace MyLibraryApp {
    class Program {
        /*
        [DllImport("E:\\Sources\\dotNetLab\\ShareLibraryByPInvoke\\Debug\\MyLibraryDll.dll", CallingConvention = CallingConvention.Cdecl)]
        public static extern double sumTwo(double varX, double varY);

        [DllImport("E:\\Sources\\dotNetLab\\ShareLibraryByPInvoke\\Debug\\MyLibraryDll.dll", CallingConvention = CallingConvention.Cdecl)]
        public static extern int deepLoopTest(int loopCount);
        */

        ///stdCall Export
        [DllImport("E:\\Sources\\dotNetLab\\ShareLibraryByPInvoke\\Debug\\MyLibraryDll_stdCall.dll")]
        public static extern double sumTwo(double varX, double varY);

        [DllImport("E:\\Sources\\dotNetLab\\ShareLibraryByPInvoke\\Debug\\MyLibraryDll_stdCall.dll")]
        public static extern int deepLoopTest(int loopCount);

        [DllImport("E:\\Sources\\dotNetLab\\ShareLibraryByPInvoke\\Debug\\MyLibraryDll_stdCall.dll")]
        public static extern int testFun();


        static void Main(string[] args) {
            var mX = 5;
            var mY = 25;
            var result = sumTwo(mX, mY);
            Console.WriteLine($"Sum result: {result}");

            var start = DateTime.Now;
            Console.WriteLine($"Deeploop start at {start}");
            var dResult = deepLoopTest(50000);
            var end = DateTime.Now;
            Console.WriteLine($"Deeploop result: {dResult}");
            Console.WriteLine($"Deeploop end at {end}, TotalMiliSec: {(end - start).TotalMilliseconds} ");

            Console.WriteLine($"TestFunction: {testFun()}");
            Console.ReadLine();
        }
    }
}
