// ReSharper disable InconsistentNaming

using System.Runtime.InteropServices;
using System.Text;

namespace CLD3
{
    public static class CLD3Detector
    {
        [DllImport("libcld3net", EntryPoint = "cld3_detect_language", CallingConvention = CallingConvention.Cdecl)]
        static extern unsafe CLD3Result DetectLanguage(byte* utf8Text);

        [DllImport("libcld3net", EntryPoint = "cld3_detect_languages", CallingConvention = CallingConvention.Cdecl)]
        static extern unsafe CLD3Results DetectLanguages(byte* utf8Text);

        public static unsafe CLD3Result DetectLanguage(string text)
        {
            if (string.IsNullOrWhiteSpace(text))
            {
                return CLD3Result.Empty();
            }

            fixed (byte* utf8Text = Encoding.UTF8.GetBytes(text))
            {
                return DetectLanguage(utf8Text);
            }
        }

        public static unsafe CLD3Results DetectLanguages(string text)
        {
            if (string.IsNullOrWhiteSpace(text))
            {
                return CLD3Results.Empty();
            }

            fixed (byte* utf8Text = Encoding.UTF8.GetBytes(text))
            {
                return DetectLanguages(utf8Text);
            }
        }
    }
}