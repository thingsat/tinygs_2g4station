/*
 * Debug output enable.
 * Warning: Debug output will slow down the whole system significantly.
 *          Also, it will result in larger compiled binary.
 * Levels: basic - only main info
 *         protocol - mainly LoRaWAN stuff, but other protocols as well
 *         SPI - full transcript of all SPI communication
 */
#define RADIOLIB_DEBUG_BASIC          (1)
#define RADIOLIB_DEBUG_PROTOCOL       (1)
#define RADIOLIB_DEBUG_SPI            (1)
#define RADIOLIB_VERBOSE_ASSERT       (1)
// #define RADIOLIB_DEBUG_PORT           Serial // Serial /stdout
