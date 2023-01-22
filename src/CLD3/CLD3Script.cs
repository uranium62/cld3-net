// ReSharper disable InconsistentNaming

namespace CLD3
{
    public enum CLD3Script
    {
        // Special value to indicate internal errors in the script detection code.
        kScriptError,

        // Special values for all Unicode scripts that we do not detect.  One special
        // value for Unicode characters of 1, 2, 3, respectively 4 bytes (as we
        // already have that information, we use it).  kScriptOtherUtf8OneByte means
        // ~Latin and kScriptOtherUtf8FourBytes means ~Han.
        kScriptOtherUtf8OneByte,
        kScriptOtherUtf8TwoBytes,
        kScriptOtherUtf8ThreeBytes,
        kScriptOtherUtf8FourBytes,

        kScriptGreek,
        kScriptCyrillic,
        kScriptHebrew,
        kScriptArabic,
        kScriptHangulJamo, // Used primarily for Korean.
        kScriptHiragana, // Used primarily for Japanese.
        kScriptKatakana, // Used primarily for Japanese.

        // Do not add any script after kNumRelevantScripts.  This value indicates the
        // number of elements in this enum Script (except this value) such that we can
        // easily iterate over the scripts.
        kNumRelevantScripts,
    }
}