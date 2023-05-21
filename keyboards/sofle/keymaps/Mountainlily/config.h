#pragma once

#define EE_HANDS

#define ENCODER_MAP_KEY_DELAY   10
#define ENCODER_DIRECTION_FLIP
// #define ENCODER_RESOLUTION 4 // Defined in sofle/rev1/info.json

// Accelerated Mode (default)
/*
#define MOUSEKEY_DELAY 	            10  // Delay between pressing a movement key and cursor movement
#define MOUSEKEY_INTERVAL 	        20  // Time between cursor movements in milliseconds
#define MOUSEKEY_MOVE_DELTA 	    8   // Step size
#define MOUSEKEY_MAX_SPEED 	        10  // Maximum cursor speed at which acceleration stops
#define MOUSEKEY_TIME_TO_MAX 	    30  // Time until maximum cursor speed is reached
#define MOUSEKEY_WHEEL_DELAY 	    10  // Delay between pressing a wheel key and wheel movement
#define MOUSEKEY_WHEEL_INTERVAL     80  // Time between wheel movements
#define MOUSEKEY_WHEEL_MAX_SPEED    8   // Maximum number of scroll steps per scroll action
#define MOUSEKEY_WHEEL_TIME_TO_MAX  40  // Time until maximum scroll speed is reached
*/

// Kinetic Mode
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
