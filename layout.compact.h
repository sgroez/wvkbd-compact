/* constants */
/* how tall the keyboard should be by default (can be overriden) */
#define KBD_PIXEL_HEIGHT 250

/* how tall the keyboard should be by default (can be overriden) */
#define KBD_PIXEL_LANDSCAPE_HEIGHT 120

/* spacing around each key */
#define KBD_KEY_BORDER 2

/* layout declarations */
enum layout_id {
	Full = 0,
	Landscape,
	Index,
	NumLayouts,
};

static struct key keys_full[], keys_landscape[], keys_index[];

/*
 * first parameter is key struct
 * second parameter is keymap name
 * third parameter is layout name
 * last parameter indicates if it's an alphabetical/primary layout
 */
static struct layout layouts[NumLayouts] = {
  [Full] = {keys_full, "latin", "full", true}, 
  [Landscape] = {keys_landscape, "latin", "landscape", true},

  [Index] = {keys_index,"latin","index", false},
};

/* key layouts
 *
 * define keys like:
 *
 *  `{
 *     "label",
 *     "SHIFT_LABEL",
 *     1,
 *     [Code, Mod, Layout, EndRow, Last],
 *     [KEY_CODE, Modifier],
 *     [&layout]
 *  },`
 *
 * - label: normal label for key
 *
 * - shift_label: label for key in shifted (uppercase) layout
 *
 * - width: column width of key
 *
 * - type: what kind of action this key peforms (emit keycode, toggle modifier,
 *   switch layout, or end the layout)
 *
 * - code: key scancode or modifier name (see
 *   `/usr/include/linux/input-event-codes.h` for scancode names, and
 *   `keyboard.h` for modifiers)
 *
 * - layout: layout to switch to when key is pressed
 */
static struct key keys_full[] = {
  {"1", "1", 1.0, Code, KEY_1},
  {"2", "2", 1.0, Code, KEY_2},
  {"3", "3", 1.0, Code, KEY_3},
  {"4", "4", 1.0, Code, KEY_4},
   {"", "", 0.0, EndRow},

  {"5", "5", 1.0, Code, KEY_5},
  {"6", "6", 1.0, Code, KEY_6},
  {"7", "7", 1.0, Code, KEY_7},
  {"8", "8", 1.0, Code, KEY_8},
   {"", "", 0.0, EndRow},

  {"9", "9", 1.0, Code, KEY_9},
  {"0", "0", 1.0, Code, KEY_0},
  {"", "", 0.0, Last},
};

static struct key keys_index[] = {
  {"Full", "Full", 1.0, Layout, 0, &layouts[Full], .scheme = 1},
  {"Landscape", "Landscape", 1.5, Layout, 0,  &layouts[Landscape], .scheme = 1},
  {"", "", 0.0, Last},
};

static struct key keys_landscape[] = {
  {"1", "1", 1.0, Code, KEY_1},
  {"2", "2", 1.0, Code, KEY_2},
  {"3", "3", 1.0, Code, KEY_3},
  {"4", "4", 1.0, Code, KEY_4},
   {"", "", 0.0, EndRow},

  {"5", "5", 1.0, Code, KEY_5},
  {"6", "6", 1.0, Code, KEY_6},
  {"7", "7", 1.0, Code, KEY_7},
  {"8", "8", 1.0, Code, KEY_8},
   {"", "", 0.0, EndRow},

  {"9", "9", 1.0, Code, KEY_9},
  {"0", "0", 1.0, Code, KEY_0},
  {"", "", 0.0, Last},
};
