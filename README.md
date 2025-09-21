# xindicators
* XIndicators is a lua library made to interact the the X server keyboard indicators (Caps lock, num lock, pause, etc)

* It follows the same spec as `xset q` (XkbUseCoreKbd)

# API
* `xindicators.caps_lock()`
* `xindicators.num_lock()`
* `xindicators.scroll_lock()`
* `xindicators.compose()`
* `xindicators.kana()`
* `xindicators.sleep()`
* `xindicators.suspend()`
* `xindicators.mute()`
* `xindicators.misc()`
* `xindicators.mail()`
* `xindicators.charging()`
* `xindicators.shift_lock()`
* `xindicators.group_2()`
* `xindicators.mouse_keys()`
* `xindicators.raw()` // Used to get all of the above at the same time in the form of a bitfield

# Example
```lua
xi = require("xindicators")

caps_lock_state = xi.caps_lock()
print(caps_lock_state) -- Prints the current active state of caps lock (0 = inactive, any other number = active)
```
