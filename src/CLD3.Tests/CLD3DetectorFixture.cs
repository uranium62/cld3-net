// ReSharper disable InconsistentNaming
using Xunit;

namespace CLD3.Tests;

public class CLD3DetectorFixture
{
    [Fact] 
    public void Should_detect_language()
    {
        var result = CLD3Detector.DetectLanguage("Hello, how are you?");
        
        Assert.Equal(CLD3Language.ENGLISH, result.language);
    }
    
    [Fact]
    public void Should_detect_languages()
    {
        var cld3 = CLD3Detector.DetectLanguages("Hello, how are you? Привіт, як справи?");

        Assert.Equal(CLD3Language.UKRAINIAN, cld3.results[0].language);
        Assert.Equal(CLD3Language.ENGLISH, cld3.results[1].language);
        Assert.Equal(CLD3Language.UNKNOWN, cld3.results[2].language);
    }

    [Fact]
    public void Should_detect_script()
    {
        var cld3 = CLD3Detector.DetectLanguages("Привіт, як справи?");
        
        Assert.Equal(CLD3Script.kScriptCyrillic, cld3.script);
    }

    [Theory]  
    [InlineData(CLD3TestData.AF,  CLD3Language.AFRIKAANS)]
    [InlineData(CLD3TestData.AR,  CLD3Language.ARABIC)]
    [InlineData(CLD3TestData.AZ,  CLD3Language.AZERBAIJANI)]
    [InlineData(CLD3TestData.BE,  CLD3Language.BELARUSIAN)]
    [InlineData(CLD3TestData.BG,  CLD3Language.BULGARIAN)]
    [InlineData(CLD3TestData.BN,  CLD3Language.BANGLA)]
    [InlineData(CLD3TestData.CA,  CLD3Language.CATALAN)]
    [InlineData(CLD3TestData.CEB, CLD3Language.CEBUANO)]
    [InlineData(CLD3TestData.CS,  CLD3Language.CZECH)]
    [InlineData(CLD3TestData.CY,  CLD3Language.WELSH)]
    [InlineData(CLD3TestData.DA,  CLD3Language.DANISH)]
    [InlineData(CLD3TestData.DE,  CLD3Language.GERMAN)]
    [InlineData(CLD3TestData.EL,  CLD3Language.GREEK)]
    [InlineData(CLD3TestData.EN,  CLD3Language.ENGLISH)]
    [InlineData(CLD3TestData.EO,  CLD3Language.ESPERANTO)]
    [InlineData(CLD3TestData.ES,  CLD3Language.SPANISH)]
    [InlineData(CLD3TestData.ET,  CLD3Language.ESTONIAN)]
    [InlineData(CLD3TestData.EU,  CLD3Language.BASQUE)]
    [InlineData(CLD3TestData.FA,  CLD3Language.PERSIAN)]
    [InlineData(CLD3TestData.FI,  CLD3Language.FINNISH)]
    [InlineData(CLD3TestData.FIL, CLD3Language.FILIPINO)]
    [InlineData(CLD3TestData.FR,  CLD3Language.FRENCH)]
    [InlineData(CLD3TestData.GA,  CLD3Language.IRISH)]
    [InlineData(CLD3TestData.GL,  CLD3Language.GALICIAN)]
    [InlineData(CLD3TestData.GU,  CLD3Language.GUJARATI)]
    [InlineData(CLD3TestData.HA,  CLD3Language.HAUSA)]
    [InlineData(CLD3TestData.HI,  CLD3Language.HINDI)]
    [InlineData(CLD3TestData.HMN, CLD3Language.HMONG)]
    [InlineData(CLD3TestData.HR,  CLD3Language.CROATIAN)]
    [InlineData(CLD3TestData.HT,  CLD3Language.HAITIAN_CREOLE)]
    [InlineData(CLD3TestData.HU,  CLD3Language.HUNGARIAN)]
    [InlineData(CLD3TestData.HY,  CLD3Language.ARMENIAN)]
    [InlineData(CLD3TestData.IG,  CLD3Language.IGBO)]
    [InlineData(CLD3TestData.IS,  CLD3Language.ICELANDIC)]
    [InlineData(CLD3TestData.IT,  CLD3Language.ITALIAN)]
    [InlineData(CLD3TestData.IW,  CLD3Language.HEBREW)]
    [InlineData(CLD3TestData.JA,  CLD3Language.JAPANESE)]
    [InlineData(CLD3TestData.JV,  CLD3Language.JAVANESE)]
    [InlineData(CLD3TestData.KA,  CLD3Language.GEORGIAN)]
    [InlineData(CLD3TestData.KK,  CLD3Language.KAZAKH)]
    [InlineData(CLD3TestData.KM,  CLD3Language.KHMER)]
    [InlineData(CLD3TestData.KN,  CLD3Language.KANNADA)]
    [InlineData(CLD3TestData.KO,  CLD3Language.KOREAN)]
    [InlineData(CLD3TestData.LA,  CLD3Language.LATIN)]
    [InlineData(CLD3TestData.LO,  CLD3Language.LAO)]
    [InlineData(CLD3TestData.LT,  CLD3Language.LITHUANIAN)]
    [InlineData(CLD3TestData.LV,  CLD3Language.LATVIAN)]
    [InlineData(CLD3TestData.MG,  CLD3Language.MALAGASY)]
    [InlineData(CLD3TestData.MI,  CLD3Language.MAORI)]
    [InlineData(CLD3TestData.MK,  CLD3Language.MACEDONIAN)]
    [InlineData(CLD3TestData.ML,  CLD3Language.MALAYALAM)]
    [InlineData(CLD3TestData.MN,  CLD3Language.MONGOLIAN)]
    [InlineData(CLD3TestData.MR,  CLD3Language.MARATHI)]
    [InlineData(CLD3TestData.MS,  CLD3Language.MALAY)]
    [InlineData(CLD3TestData.MT,  CLD3Language.MALTESE)]
    [InlineData(CLD3TestData.MY,  CLD3Language.BURMESE)]
    [InlineData(CLD3TestData.NE,  CLD3Language.NEPALI)]
    [InlineData(CLD3TestData.NL,  CLD3Language.DUTCH)]
    [InlineData(CLD3TestData.NO,  CLD3Language.NORWEGIAN)]
    [InlineData(CLD3TestData.NY,  CLD3Language.NYANJA)]
    [InlineData(CLD3TestData.PA,  CLD3Language.PUNJABI)]
    [InlineData(CLD3TestData.PL,  CLD3Language.POLISH)]
    [InlineData(CLD3TestData.PT,  CLD3Language.PORTUGUESE)]
    [InlineData(CLD3TestData.RO,  CLD3Language.ROMANIAN)]
    [InlineData(CLD3TestData.RU,  CLD3Language.RUSSIAN)]
    [InlineData(CLD3TestData.SI,  CLD3Language.SINHALA)]
    [InlineData(CLD3TestData.SK,  CLD3Language.SLOVAK)]
    [InlineData(CLD3TestData.SL,  CLD3Language.SLOVENIAN)]
    [InlineData(CLD3TestData.SO,  CLD3Language.SOMALI)]
    [InlineData(CLD3TestData.SQ,  CLD3Language.ALBANIAN)]
    [InlineData(CLD3TestData.SR,  CLD3Language.SERBIAN)]
    [InlineData(CLD3TestData.ST,  CLD3Language.SOUTHERN_SOTHO)]
    [InlineData(CLD3TestData.SU,  CLD3Language.SUNDANESE)]
    [InlineData(CLD3TestData.SV,  CLD3Language.SWEDISH)]
    [InlineData(CLD3TestData.SW,  CLD3Language.SWAHILI)]
    [InlineData(CLD3TestData.TA,  CLD3Language.TAMIL)]
    [InlineData(CLD3TestData.TE,  CLD3Language.TELUGU)]
    [InlineData(CLD3TestData.TG,  CLD3Language.TAJIK)]
    [InlineData(CLD3TestData.TH,  CLD3Language.THAI)]
    [InlineData(CLD3TestData.TR,  CLD3Language.TURKISH)]
    [InlineData(CLD3TestData.UK,  CLD3Language.UKRAINIAN)]
    [InlineData(CLD3TestData.UR,  CLD3Language.URDU)]
    [InlineData(CLD3TestData.UZ,  CLD3Language.UZBEK)]
    [InlineData(CLD3TestData.VI,  CLD3Language.VIETNAMESE)]
    [InlineData(CLD3TestData.YI,  CLD3Language.YIDDISH)]
    [InlineData(CLD3TestData.YO,  CLD3Language.YORUBA)]
    [InlineData(CLD3TestData.ZH,  CLD3Language.CHINESE)]
    [InlineData(CLD3TestData.ZU,  CLD3Language.ZULU)]
    public void Should_detect_lang(string text, CLD3Language expected)
    {
        var result = CLD3Detector.DetectLanguage(text);
    
        Assert.Equal(expected, result.language);
    }
    
}