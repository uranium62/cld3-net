# Compact language detector 3 for .NET (wrapper)

### Model
CLD3 is a neural network model for language identification [more](https://github.com/google/cld3).

### Supported Languages
The model outputs BCP-47-style language codes, shown in the table below.

| Language name   | BCP-47 code |
|-----------------|-------------| 
| Unknown         | und         | 
| Esperanto       | eo          | 
| Corsican        | co          | 
| Basque          | eu          | 
| Tamil           | ta          | 
| German          | de          | 
| Maltese         | mt          | 
| Pashto          | ps          | 
| Telugu          | te          | 
| Sundanese       | su          | 
| Uzbek           | uz          | 
| Chinese latin   | zh-latn     | 
| Nepali          | ne          | 
| Dutch           | nl          | 
| Swahili         | sw          | 
| Albanian        | sq          | 
| Hmong           | hmn         | 
| Japanese        | ja          | 
| Norwegian       | no          | 
| Mongolian       | mn          | 
| Somali          | so          | 
| Korean          | ko          | 
| Kazakh          | kk          | 
| Slovenian       | sl          | 
| Igbo            | ig          | 
| Marathi         | mr          | 
| Thai            | th          | 
| Zulu            | zu          | 
| Malayalam       | ml          | 
| Croatian        | hr          | 
| Bosnian         | bs          | 
| Lao             | lo          | 
| Sindhi          | sd          | 
| Welsh           | cy          | 
| Armenian        | hy          | 
| Ukrainian       | uk          | 
| Portuguese      | pt          | 
| Latvian         | lv          | 
| Hebrew          | iw          | 
| Czech           | cs          | 
| Vietnamese      | vi          | 
| Javanese        | jv          | 
| Belarusian      | be          | 
| Khmer           | km          | 
| Macedonian      | mk          | 
| Turkish         | tr          | 
| Western frisian | fy          | 
| Amharic         | am          | 
| Chinese         | zh          | 
| Danish          | da          | 
| Swedish         | sv          | 
| Finnish         | fi          | 
| Haitian creole  | ht          | 
| Afrikaans       | af          | 
| Latin           | la          | 
| Indonesian      | id          | 
| Filipino        | fil         | 
| Samoan          | sm          | 
| Catalan         | ca          | 
| Greek           | el          | 
| Georgian        | ka          | 
| Serbian         | sr          | 
| Italian         | it          | 
| Slovak          | sk          | 
| Russian         | ru          | 
| Russian latin   | ru-latn     | 
| Bulgarian       | bg          | 
| Nyanja          | ny          | 
| Persian         | fa          | 
| Hawaiian        | haw         | 
| Galician        | gd          | 
| Estonian        | et          | 
| Malay           | ms          | 
| Scottish gaelic | gb          | 
| Bulgarian latin | bg-latn     | 
| Hausa           | ha          | 
| Icelandic       | is          | 
| Urdu            | ur          | 
| Maori           | mi          | 
| Hindi           | hi          | 
| Bangla          | bn          | 
| Hindi latin     | hi-latn     | 
| French          | fr          | 
| Yiddish         | yi          | 
| Hungarian       | hu          | 
| Xhosa           | xh          | 
| Burmese         | my          | 
| Tajik           | tg          | 
| Romanian        | ro          | 
| Arabic          | ar          | 
| Luxembourgish   | lb          | 
| Greek latin     | el-latn     | 
| Southern sotho  | st          | 
| Cebuano         | ceb         | 
| Kannada         | kn          | 
| Azerbaijani     | az          | 
| Sinhala         | si          | 
| Kyrgyz          | ky          | 
| Malagasy        | mg          | 
| English         | en          | 
| Gujarati        | gu          | 
| Spanish         | es          | 
| Polish          | pl          | 
| Japanese latin  | ja-latn     | 
| Irish           | ga          | 
| Lithuanian      | lt          | 
| Shona           | sn          | 
| Yoruba          | yo          | 
| Punjabi         | pa          | 
| Kurdish         | ku          | 

### Build
For building the library use CMAKE.
```bash
brew install cmake
brew install protobuf

cmake ./cld3
cmake --build ./cld3

# copy
cp -rf ./cld3/libcld3net.so ./src/CLD3/libcld3net.so
```

### API 
Unstable. API may change in the future
```cs
public static CLD3Result DetectLanguage(string text) { throw null; }
public static CLD3Results DetectLanguages(string text) { throw null; }
```

### Examples
A few examples of how to use api. You can see more examples in tests.
```
var cld3 = CLD3Detector.DetectLanguage("Hello, how are you?");

var cld3 = CLD3Detector.DetectLanguages("Hello, how are you? Привіт, як справи?");
```