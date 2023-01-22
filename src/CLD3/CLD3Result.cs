// ReSharper disable InconsistentNaming

using System.Runtime.InteropServices;

namespace CLD3
{
    [StructLayout(LayoutKind.Sequential)]
    public struct CLD3Result
    {
        public CLD3Language language;
        public float probability;
        [MarshalAs(UnmanagedType.I1)] public bool is_reliable;
        public float proportion;

        public static CLD3Result Empty() => new CLD3Result()
        {
            language = CLD3Language.UNKNOWN,
            is_reliable = false
        };
    }

    [StructLayout(LayoutKind.Sequential)]
    public struct CLD3Results
    {
        public CLD3Script script;
        [MarshalAs(UnmanagedType.ByValArray, SizeConst = 3)]
        public CLD3Result[] results;

        public static CLD3Results Empty() => new CLD3Results()
        {
            results = new[]
            {
                CLD3Result.Empty(),
                CLD3Result.Empty(),
                CLD3Result.Empty()
            }
        };
    }
}