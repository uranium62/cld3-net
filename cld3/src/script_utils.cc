#include <string>
#include "script_detector.h"
#include "utils.h"

namespace chrome_lang_id {
namespace script_utils {
   Script DetectScript(const string &text){
      // counts[s] is the number of characters with script s.
      // Note: {} "value-initializes" the array to zero.
      int counts[kNumRelevantScripts]{};
      int total_count = 0;

      const char *const text_end = text.data() + text.size();
        for (const char *curr = text.data(); curr < text_end; curr += utils::OneCharLen(curr)) {
          const int num_bytes = utils::OneCharLen(curr);

            // If a partial UTF-8 character is encountered, break out of the loop.
            if (curr + num_bytes > text_end) {
              break;
            }

            // Skip spaces, numbers, punctuation, and all other non-alpha ASCII
            // characters: these characters are used in so many languages, they do not
            // communicate language-related information.
            if ((num_bytes == 1) && !isalpha(*curr)) {
              continue;
            }
            Script script = GetScript(curr, num_bytes);
            CLD3_DCHECK(script >= 0);
            CLD3_DCHECK(script < kNumRelevantScripts);
            counts[static_cast<int>(script)]++;
            total_count++;
          }

          // Get script with max counts symbols
          int script_id = static_cast<int>(kScriptError);
          int max_count = -1;
          for (int i = 0; i < kNumRelevantScripts; ++i) {
            if (counts[i] > max_count){
                max_count = counts[i];
                script_id = i;
            }
          }
          return static_cast<Script>(script_id);
    }

}  // namespace script_utils
}  // namespace chrome_lang_id