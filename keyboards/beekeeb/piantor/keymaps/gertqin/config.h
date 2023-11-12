#pragma once

// how long before a tap becomes a hold, if set above 500, a key tapped during the tapping term will turn it into a hold too
#define TAPPING_TERM 250

// makes tap and hold keys trigger the hold if another key is pressed before releasing, even if it hasn't hit the TAPPING_TERM
#define PERMISSIVE_HOLD

// makes it possible to use a dual role key as modifier shortly after having been tapped (see Hold after tap)
// Breaks any Tap Toggle functionality (TT or the One Shot Tap Toggle)
#define QUICK_TAP_TERM 0
