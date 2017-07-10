using System;

namespace CSharpDLL
{
    public class CMyAddClass
    {
        public int num1 { get; set; }
        public int num2 { get; set; }

        public int AddFunc()
        {
            return num1 + num2;
        }
    }

    public class CMyWriteLine
    {
        public string Text { get; set; }

        public void WriteLineFunc()
        {
            Console.WriteLine(Text);
        }
    }
}
