// \\\\\Matroskin///:
#include "../hle.h"
#include "../input_bind.h"
#include "../settings.h"
#include "za_key_glyphs.h"

enum { PROMPT_TEXT = 1, PROMPT_KEYCAP, PROMPT_CROSS, PROMPT_CIRCLE, PROMPT_SQUARE, PROMPT_TRIANGLE };

// [Matroskin] Lumiose passes a logical Switch slot. Resolve it through the current bindings before naming the button.
HLE_FUNC("vmp_recomp_button_prompt", lumiose_button_prompt) {
    const uint64_t slot = c->x[0];
    c->x[0] = 0;
    if (slot > BIND_DOWN) return;

    const int style = input_prompt_style();
    const char *label;
    unsigned shape = PROMPT_TEXT;
    if (style == PROMPTS_KEYBOARD) {
        shape = PROMPT_KEYCAP;
        label = za_key_token_label(bind_prompt_keyboard_token((int)slot, 0));
    } else {
        const int host = bind_prompt_host((int)slot);
        const int family = style == PROMPTS_STEAMDECK ? 3 : style == PROMPTS_PLAYSTATION ? 2 :
                           style == PROMPTS_XBOX ? 1 : 0;
        if (family == 2 && host >= 0 && host < 4) {
            shape = PROMPT_CROSS + (unsigned)host;  // [Matroskin] SDL orders faces south, east, west, and north.
            label = "";
        } else if (host >= 11 && host <= 14) {
            static const char *const directions[] = {"Up", "Down", "Left", "Right"};
            label = directions[host - 11];
        } else {
            label = bind_pad_label(host, family);
        }
    }

    // [Matroskin] The prompt ABI puts the shape in the high byte and the label in the lower seven.
    uint64_t value = (uint64_t)shape << 56;
    for (unsigned i = 0; i < 7 && label[i]; ++i)
        value |= (uint64_t)(unsigned char)label[i] << (i * 8);
    c->x[0] = value;
}
