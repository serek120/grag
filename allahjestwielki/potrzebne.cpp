#include <iostream>
#include <chrono>
#include <thread>
#include <cstdio>

namespace game {
    namespace time {

        class DelayedPrinter {
        public:
            // Constructor accepts the delay time in milliseconds
            explicit DelayedPrinter(int delay_ms)
                : delay_ms_(delay_ms) {}

            // Function to print text with delay between each character
            void printWithDelay(const char* text) const {
                for (const char* c = text; *c != '\0'; ++c) {
                    std::printf("%c", *c);          // Print one character at a time
                    std::fflush(stdout);           // Ensure immediate output
                    std::this_thread::sleep_for(std::chrono::milliseconds(delay_ms_));
                }
                std::printf("\n");  // Newline after printing all characters
            }

        private:
            int delay_ms_;  // Delay between characters in milliseconds
        };

    }  // namespace time
}  // namespace game
