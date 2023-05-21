#pragma once

// Handedness
#define EE_HANDS // EEPROM when flashing
// #define MASTER_LEFT
// #define MASTER_RIGHT

// Encoders
#define ENCODER_MAP_KEY_DELAY   10
#define ENCODER_DIRECTION_FLIP
#ifdef ENCODER_RESOLUTION
    #undef ENCODER_RESOLUTION
#endif
#define ENCODER_RESOLUTION 4

// Tap-hold
#ifdef TAPPING_TERM
    #undef TAPPING_TERM
#endif
#define TAPPING_TERM 200

// Mouse Keys - Kinetic Mode
#define MK_KINETIC_SPEED  	                          // Enable kinetic mode
#define MOUSEKEY_DELAY                          5     // Delay between pressing a movement key and cursor movement
#define MOUSEKEY_INTERVAL                       10    // Time between cursor movements in milliseconds
#define MOUSEKEY_MOVE_DELTA                     16    // Step size for accelerating from initial to base speed
#define MOUSEKEY_INITIAL_SPEED                  100   // Initial speed of the cursor in pixel per second
#define MOUSEKEY_BASE_SPEED                     5000  // Maximum cursor speed at which acceleration stops
#define MOUSEKEY_DECELERATED_SPEED              400   // Decelerated cursor speed
#define MOUSEKEY_ACCELERATED_SPEED              3000  // Accelerated cursor speed
#define MOUSEKEY_WHEEL_INITIAL_MOVEMENTS        8     // Initial number of movements of the mouse wheel
#define MOUSEKEY_WHEEL_BASE_MOVEMENTS           32    // Maximum number of movements at which acceleration stops
#define MOUSEKEY_WHEEL_ACCELERATED_MOVEMENTS    48    // Accelerated wheel movements
#define MOUSEKEY_WHEEL_DECELERATED_MOVEMENTS    8     // Decelerated wheel movements


// Space Saving
#undef LOCKING_SUPPORT_ENABLE
#undef LOCKING_RESYNC_ENABLE
#define NO_ACTION_ONESHOT
#define NO_MUSIC_MODE
#define LAYER_STATE_8BIT // Limit to 8 layers
