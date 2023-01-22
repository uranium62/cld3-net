#ifndef SCRIPT_UTILS_H_
#define SCRIPT_UTILS_H_

#include <string>
#include "script_detector.h"

namespace chrome_lang_id {
namespace script_utils {

  Script DetectScript(const string &text);

}  // namespace script_utils
}  // namespace chrome_lang_id

#endif  // SCRIPT_UTILS_H_