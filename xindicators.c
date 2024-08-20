#include <stdbool.h>
#include <stdlib.h>
#include <lua.h>
#include <lauxlib.h>
#include <X11/XKBlib.h>

// clang-format off
// Order is indicator(name, mask)
#define INDICATOR_LIST(indicator)  \
	indicator(raw, 0xffffffff)     \
	indicator(caps_lock, 1 << 0)   \
	indicator(num_lock, 1 << 1)    \
	indicator(scroll_lock, 1 << 2) \
	indicator(compose, 1 << 3)     \
	indicator(kana, 1 << 4)        \
	indicator(sleep, 1 << 5)       \
	indicator(suspend, 1 << 6)     \
	indicator(mute, 1 << 7)        \
	indicator(misc, 1 << 8)        \
	indicator(mail, 1 << 9)        \
	indicator(charging, 1 << 10)   \
	indicator(shift_lock, 1 << 11) \
	indicator(group_2, 1 << 12)    \
	indicator(mouse_keys, 1 << 13)
// clang-format on

#define GET_INDICATOR_FUNC(indicator, mask)                                    \
	static int(indicator)(lua_State * L) {                                     \
		Display* display = XOpenDisplay(getenv("DISPLAY"));                    \
		if (!display) {                                                        \
			lua_pushboolean(L, 0);                                             \
			return 1;                                                          \
		}                                                                      \
                                                                               \
		unsigned int state = 0;                                                \
		if (XkbGetIndicatorState(display, XkbUseCoreKbd, &state) != Success) { \
			lua_pushboolean(L, 0);                                             \
			return 1;                                                          \
		}                                                                      \
                                                                               \
		XCloseDisplay(display);                                                \
		state = state & ((mask));                                              \
		lua_pushboolean(L, state);                                             \
		return 1;                                                              \
	}
INDICATOR_LIST(GET_INDICATOR_FUNC)
#undef GET_INDICATOR_FUNC

static const struct luaL_Reg xindicators[] = {
#define GENERATE_LIST(name, mask) \
	{#name, name},

	INDICATOR_LIST(GENERATE_LIST)
#undef GENERATE_LIST
		{NULL, NULL}};

int luaopen_xindicators(lua_State* L) {
	luaL_newlib(L, xindicators);
	return 1;
}
