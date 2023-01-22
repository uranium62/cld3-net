#include <iostream>
#include <fstream>
#include <map>
#include <string>

#include "base.h"
#include "nnet_language_identifier.h"

#include "script_detector.h"
#include "script_utils.h"

using chrome_lang_id::NNetLanguageIdentifier;
using chrome_lang_id::Script;
using chrome_lang_id::script_utils::DetectScript;

using namespace std;
#ifdef __linux__
#define EXPORT __attribute__((visibility("default")))
#else
#if defined(_MSC_VER)
#define EXPORT __declspec(dllexport)
#else
#define EXPORT __attribute__((visibility("default")))
#endif
#endif

enum CLD3Language
{
    UNKNOWN         = 0,   // und
    
    ESPERANTO       = 1,   // eo
    CORSICAN        = 2,   // co
    BASQUE          = 3,   // eu
    TAMIL           = 4,   // ta
    GERMAN          = 5,   // de
    MALTESE         = 6,   // mt
    PASHTO          = 7,   // ps
    TELUGU          = 8,   // te
    SUNDANESE       = 9,   // su
    UZBEK           = 10,  // uz
    CHINESE_LATIN   = 11,  // zh-Latn
    NEPALI          = 12,  // ne
    DUTCH           = 13,  // nl
    SWAHILI         = 14,  // sw
    ALBANIAN        = 15,  // sq
    HMONG           = 16,  // hmn
    JAPANESE        = 17,  // ja
    NORWEGIAN       = 18,  // no
    MONGOLIAN       = 19,  // mn
    SOMALI          = 20,  // so
    KOREAN          = 21,  // ko
    KAZAKH          = 22,  // kk
    SLOVENIAN       = 23,  // sl
    IGBO            = 24,  // ig
    MARATHI         = 25,  // mr
    THAI            = 26,  // th
    ZULU            = 27,  // zu
    MALAYALAM       = 28,  // ml
    CROATIAN        = 29,  // hr
    BOSNIAN         = 30,  // bs
    LAO             = 31,  // lo
    SINDHI          = 32,  // sd
    WELSH           = 33,  // cy
    ARMENIAN        = 34,  // hy
    UKRAINIAN       = 35,  // uk
    PORTUGUESE      = 36,  // pt
    LATVIAN         = 37,  // lv
    HEBREW          = 38,  // iw
    CZECH           = 39,  // cs
    VIETNAMESE      = 40,  // vi
    JAVANESE        = 41,  // jv
    BELARUSIAN      = 42,  // be
    KHMER           = 43,  // km
    MACEDONIAN      = 44,  // mk
    TURKISH         = 45,  // tr
    WESTERN_FRISIAN = 46,  // fy
    AMHARIC         = 47,  // am
    CHINESE         = 48,  // zh
    DANISH          = 49,  // da
    SWEDISH         = 50,  // sv
    FINNISH         = 51,  // fi
    HAITIAN_CREOLE  = 52,  // ht
    AFRIKAANS       = 53,  // af
    LATIN           = 54,  // la
    INDONESIAN      = 55,  // id
    FILIPINO        = 56,  // fil
    SAMOAN          = 57,  // sm
    CATALAN         = 58,  // ca
    GREEK           = 59,  // el
    GEORGIAN        = 60,  // ka
    SERBIAN         = 61,  // sr
    ITALIAN         = 62,  // it
    SLOVAK          = 63,  // sk
    RUSSIAN         = 64,  // ru
    RUSSIAN_LATIN   = 65,  // ru-Latn
    BULGARIAN       = 66,  // bg
    NYANJA          = 67,  // ny
    PERSIAN         = 68,  // fa
    HAWAIIAN        = 69,  // haw
    GALICIAN        = 70,  // gd
    ESTONIAN        = 71,  // et
    MALAY           = 72,  // ms
    SCOTTISH_GAELIC = 73,  // gb
    BULGARIAN_LATIN = 74,  // bg-Latn
    HAUSA           = 75,  // ha
    ICELANDIC       = 76,  // is
    URDU            = 77,  // ur
    MAORI           = 78,  // mi
    HINDI           = 79,  // hi
    BANGLA          = 80,  // bn
    HINDI_LATIN     = 81,  // hi-Latn
    FRENCH          = 82,  // fr
    YIDDISH         = 83,  // yi
    HUNGARIAN       = 84,  // hu
    XHOSA           = 85,  // xh
    BURMESE         = 86,  // my
    TAJIK           = 87,  // tg
    ROMANIAN        = 88,  // ro
    ARABIC          = 89,  // ar
    LUXEMBOURGISH   = 90,  // lb
    GREEK_LATIN     = 91,  // el-Latn
    SOUTHERN_SOTHO  = 92,  // st
    CEBUANO         = 93,  // ceb
    KANNADA         = 94,  // kn
    AZERBAIJANI     = 95,  // az
    SINHALA         = 96,  // si
    KYRGYZ          = 97,  // ky
    MALAGASY        = 98,  // mg
    ENGLISH         = 99,  // en
    GUJARATI        = 100, // gu
    SPANISH         = 101, // es
    POLISH          = 102, // pl
    JAPANESE_LATIN  = 103, // ja-Latn
    IRISH           = 104, // ga
    LITHUANIAN      = 105, // lt
    SHONA           = 106, // sn
    YORUBA          = 107, // yo
    PUNJABI         = 108, // pa
    KURDISH         = 109  // ku
};

struct CLD3Result {
    CLD3Language language;
    float probability;
    bool is_reliable;
    float proportion;
};

struct CLD3Results {
    Script script;
    CLD3Result results[3];
};

extern "C" EXPORT CLD3Result  cld3_detect_language(const char* utf8Text);
extern "C" EXPORT CLD3Results cld3_detect_languages(const char* utf8Text);

CLD3Language MapLanguage(string lang){
    if (lang == "und")     return UNKNOWN;
    if (lang == "eo")      return ESPERANTO;
    if (lang == "co")      return CORSICAN;
    if (lang == "eu")      return BASQUE;
    if (lang == "ta")      return TAMIL;
    if (lang == "de")      return GERMAN;
    if (lang == "mt")      return MALTESE;
    if (lang == "ps")      return PASHTO;
    if (lang == "te")      return TELUGU;
    if (lang == "su")      return SUNDANESE;
    if (lang == "uz")      return UZBEK;
    if (lang == "zh-Latn") return CHINESE_LATIN;
    if (lang == "ne")      return NEPALI;
    if (lang == "nl")      return DUTCH;
    if (lang == "sw")      return SWAHILI;
    if (lang == "sq")      return ALBANIAN;
    if (lang == "hmn")     return HMONG;
    if (lang == "ja")      return JAPANESE;
    if (lang == "no")      return NORWEGIAN;
    if (lang == "mn")      return MONGOLIAN;
    if (lang == "so")      return SOMALI;
    if (lang == "ko")      return KOREAN;
    if (lang == "kk")      return KAZAKH;
    if (lang == "sl")      return SLOVENIAN;
    if (lang == "ig")      return IGBO;
    if (lang == "mr")      return MARATHI;
    if (lang == "th")      return THAI;
    if (lang == "zu")      return ZULU;
    if (lang == "ml")      return MALAYALAM;
    if (lang == "hr")      return CROATIAN;
    if (lang == "bs")      return BOSNIAN;
    if (lang == "lo")      return LAO;
    if (lang == "sd")      return SINDHI;
    if (lang == "cy")      return WELSH;
    if (lang == "hy")      return ARMENIAN;
    if (lang == "uk")      return UKRAINIAN;
    if (lang == "pt")      return PORTUGUESE;
    if (lang == "lv")      return LATVIAN;
    if (lang == "iw")      return HEBREW;
    if (lang == "cs")      return CZECH;
    if (lang == "vi")      return VIETNAMESE;
    if (lang == "jv")      return JAVANESE;
    if (lang == "be")      return BELARUSIAN;
    if (lang == "km")      return KHMER;
    if (lang == "mk")      return MACEDONIAN;
    if (lang == "tr")      return TURKISH;
    if (lang == "fy")      return WESTERN_FRISIAN;
    if (lang == "am")      return AMHARIC;
    if (lang == "zh")      return CHINESE;
    if (lang == "da")      return DANISH;
    if (lang == "sv")      return SWEDISH;
    if (lang == "fi")      return FINNISH;
    if (lang == "ht")      return HAITIAN_CREOLE;
    if (lang == "af")      return AFRIKAANS;
    if (lang == "la")      return LATIN;
    if (lang == "id")      return INDONESIAN;
    if (lang == "fil")     return FILIPINO;
    if (lang == "sm")      return SAMOAN;
    if (lang == "ca")      return CATALAN;
    if (lang == "el")      return GREEK;
    if (lang == "ka")      return GEORGIAN;
    if (lang == "sr")      return SERBIAN;
    if (lang == "it")      return ITALIAN;
    if (lang == "sk")      return SLOVAK;
    if (lang == "ru")      return RUSSIAN;
    if (lang == "ru-Latn") return RUSSIAN_LATIN;
    if (lang == "bg")      return BULGARIAN;
    if (lang == "ny")      return NYANJA;
    if (lang == "fa")      return PERSIAN;
    if (lang == "haw")     return HAWAIIAN;
    if (lang == "gl")      return GALICIAN;
    if (lang == "et")      return ESTONIAN;
    if (lang == "ms")      return MALAY;
    if (lang == "gd")      return SCOTTISH_GAELIC;
    if (lang == "bg-Latn") return BULGARIAN_LATIN;
    if (lang == "ha")      return HAUSA;
    if (lang == "is")      return ICELANDIC;
    if (lang == "ur")      return URDU;
    if (lang == "mi")      return MAORI;
    if (lang == "hi")      return HINDI;
    if (lang == "bn")      return BANGLA;
    if (lang == "hi-Latn") return HINDI_LATIN;
    if (lang == "fr")      return FRENCH;
    if (lang == "yi")      return YIDDISH;
    if (lang == "hu")      return HUNGARIAN;
    if (lang == "xh")      return XHOSA;
    if (lang == "my")      return BURMESE;
    if (lang == "tg")      return TAJIK;
    if (lang == "ro")      return ROMANIAN;
    if (lang == "ar")      return ARABIC;
    if (lang == "lb")      return LUXEMBOURGISH;
    if (lang == "el-Latn") return GREEK_LATIN;
    if (lang == "st")      return SOUTHERN_SOTHO;
    if (lang == "ceb")     return CEBUANO;
    if (lang == "kn")      return KANNADA;
    if (lang == "az")      return AZERBAIJANI;
    if (lang == "si")      return SINHALA;
    if (lang == "ky")      return KYRGYZ;
    if (lang == "mg")      return MALAGASY;
    if (lang == "en")      return ENGLISH;
    if (lang == "gu")      return GUJARATI;
    if (lang == "es")      return SPANISH;
    if (lang == "pl")      return POLISH;
    if (lang == "ja-Latn") return JAPANESE_LATIN;
    if (lang == "ga")      return IRISH;
    if (lang == "lt")      return LITHUANIAN;
    if (lang == "sn")      return SHONA;
    if (lang == "yo")      return YORUBA;
    if (lang == "pa")      return PUNJABI;
    if (lang == "ku")      return KURDISH;
                           return UNKNOWN;
}

CLD3Result MapResult(NNetLanguageIdentifier::Result result){
    CLD3Result cld3Result;

    cld3Result.language    = MapLanguage(result.language);
    cld3Result.probability = result.probability;
    cld3Result.is_reliable = result.is_reliable;
    cld3Result.proportion  = result.proportion;

    return cld3Result;
}

CLD3Results MapResults(std::vector<NNetLanguageIdentifier::Result> results){
    CLD3Results cld3Results;

    int i = 0;
    for(auto result : results){
        cld3Results.results[i++] = MapResult(result);
    }
    return cld3Results;
}

CLD3Result cld3_detect_language(const char* utf8Text) {
    string text(utf8Text);
    NNetLanguageIdentifier lang_id(0, 1000);

    auto lang_result = lang_id.FindLanguage(text);
    auto cld3_result = MapResult(lang_result);

    return cld3_result;
}

CLD3Results cld3_detect_languages(const char* utf8Text) {
    string text(utf8Text);
    NNetLanguageIdentifier lang_id(0, 1000);

    auto lang_results = lang_id.FindTopNMostFreqLangs(text, 3);
    auto cld3_results = MapResults(lang_results);

    cld3_results.script = DetectScript(text);

    return cld3_results;
}