#pragma once

#include <iostream>
#include <SDL.h>

#define FILL_RECT(x, y) SDL_RenderFillRect(x, y);
using Rect = SDL_Rect;

using Engine_Event = SDL_Event;
#define EVENT_POLL(x) SDL_PollEvent(x)

#ifdef _DEBUG
	#define LOG_ERROR(x) std::cout << x << std::endl;
#else
	#define LOG_ERROR(x) throw std::runtime_error(x);
#endif

#define SET_RENDER_DRAW_COLOR(x, y, z, w, v) SDL_SetRenderDrawColor(x, y, z, w, v);
#define CLEAR_RENDERER(x) SDL_RenderClear(x);
#define PRESENT(x) SDL_RenderPresent(x);

typedef enum
{
    EVT_FIRSTEVENT     = 0,     /**< Unused (do not remove) */

    /* Application events */
    EVT_QUIT           = 0x100, /**< User-requested quit */

    /* These application events have special meaning on iOS, see README-ios.md for details */
    EVT_APP_TERMINATING,        /**< The application is being terminated by the OS
                                     Called on iOS in applicationWillTerminate()
                                     Called on Android in onDestroy()
                                */
    EVT_APP_LOWMEMORY,          /**< The application is low on memory, free memory if possible.
                                     Called on iOS in applicationDidReceiveMemoryWarning()
                                     Called on Android in onLowMemory()
                                */
    EVT_APP_WILLENTERBACKGROUND, /**< The application is about to enter the background
                                     Called on iOS in applicationWillResignActive()
                                     Called on Android in onPause()
                                */
    EVT_APP_DIDENTERBACKGROUND, /**< The application did enter the background and may not get CPU for some time
                                     Called on iOS in applicationDidEnterBackground()
                                     Called on Android in onPause()
                                */
    EVT_APP_WILLENTERFOREGROUND, /**< The application is about to enter the foreground
                                     Called on iOS in applicationWillEnterForeground()
                                     Called on Android in onResume()
                                */
    EVT_APP_DIDENTERFOREGROUND, /**< The application is now interactive
                                     Called on iOS in applicationDidBecomeActive()
                                     Called on Android in onResume()
                                */

    /* Display events */
    EVT_DISPLAYEVENT   = 0x150,  /**< Display state change */

    /* Window events */
    EVT_WINDOWEVENT    = 0x200, /**< Window state change */
    EVT_SYSWMEVENT,             /**< System specific event */

    /* Keyboard events */
    EVT_KEYDOWN        = 0x300, /**< Key pressed */
    EVT_KEYUP,                  /**< Key released */
    EVT_TEXTEDITING,            /**< Keyboard text editing (composition) */
    EVT_TEXTINPUT,              /**< Keyboard text input */
    EVT_KEYMAPCHANGED,          /**< Keymap changed due to a system event such as an
                                     input language or keyboard layout change.
                                */

    /* Mouse events */
    EVT_MOUSEMOTION    = 0x400, /**< Mouse moved */
    EVT_MOUSEBUTTONDOWN,        /**< Mouse button pressed */
    EVT_MOUSEBUTTONUP,          /**< Mouse button released */
    EVT_MOUSEWHEEL,             /**< Mouse wheel motion */

    /* Joystick events */
    EVT_JOYAXISMOTION  = 0x600, /**< Joystick axis motion */
    EVT_JOYBALLMOTION,          /**< Joystick trackball motion */
    EVT_JOYHATMOTION,           /**< Joystick hat position change */
    EVT_JOYBUTTONDOWN,          /**< Joystick button pressed */
    EVT_JOYBUTTONUP,            /**< Joystick button released */
    EVT_JOYDEVICEADDED,         /**< A new joystick has been inserted into the system */
    EVT_JOYDEVICEREMOVED,       /**< An opened joystick has been removed */

    /* Game controller events */
    EVT_CONTROLLERAXISMOTION  = 0x650, /**< Game controller axis motion */
    EVT_CONTROLLERBUTTONDOWN,          /**< Game controller button pressed */
    EVT_CONTROLLERBUTTONUP,            /**< Game controller button released */
    EVT_CONTROLLERDEVICEADDED,         /**< A new Game controller has been inserted into the system */
    EVT_CONTROLLERDEVICEREMOVED,       /**< An opened Game controller has been removed */
    EVT_CONTROLLERDEVICEREMAPPED,      /**< The controller mapping was updated */

    /* Touch events */
    EVT_FINGERDOWN      = 0x700,
    EVT_FINGERUP,
    EVT_FINGERMOTION,

    /* Gesture events */
    EVT_DOLLARGESTURE   = 0x800,
    EVT_DOLLARRECORD,
    EVT_MULTIGESTURE,

    /* Clipboard events */
    EVT_CLIPBOARDUPDATE = 0x900, /**< The clipboard changed */

    /* Drag and drop events */
    EVT_DROPFILE        = 0x1000, /**< The system requests a file open */
    EVT_DROPTEXT,                 /**< text/plain drag-and-drop event */
    EVT_DROPBEGIN,                /**< A new set of drops is beginning (NULL filename) */
    EVT_DROPCOMPLETE,             /**< Current set of drops is now complete (NULL filename) */

    /* Audio hotplug events */
    EVT_AUDIODEVICEADDED = 0x1100, /**< A new audio device is available */
    EVT_AUDIODEVICEREMOVED,        /**< An audio device has been removed. */

    /* Sensor events */
    EVT_SENSORUPDATE = 0x1200,     /**< A sensor was updated */

    /* Render events */
    EVT_RENDER_TARGETS_RESET = 0x2000, /**< The render targets have been reset and their contents need to be updated */
    EVT_RENDER_DEVICE_RESET, /**< The device has been reset and all textures need to be recreated */

    /** Events ::EVT_USEREVENT through ::EVT_LASTEVENT are for your use,
     *  and should be allocated with EVT_RegisterEvents()
     */
    EVT_USEREVENT    = 0x8000,

    /**
     *  This last event is only for bounding internal arrays
     */
    EVT_LASTEVENT    = 0xFFFF
} EVT_EventType;