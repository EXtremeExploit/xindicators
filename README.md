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

# Example
```lua
xi = require("xindicators")

isActive = xi.caps_lock() -- Returns the current active state of caps lock (boolean)
print(isActive)
```
