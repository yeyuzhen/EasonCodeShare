using System;
using System.Runtime.InteropServices;

namespace HelloCSharp
{
    class Program
    {
        [DllImport("HelloCpp.dll", CharSet = CharSet.Unicode)]
        public static extern int FunctionInDLL(String s);
        static void Main(string[] args)
        {
            Console.WriteLine("Writen by C#.");
            int res = FunctionInDLL("Some string from C#.");
            Console.WriteLine("C++ returned the value " + res);
        }
    }
}
