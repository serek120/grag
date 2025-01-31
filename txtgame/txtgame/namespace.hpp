#ifndef GAME_HPP
#define GAME_HPP

#include <iostream>
#include <chrono>
#include <thread>
#include <cstdio>
#include <ctime>

namespace game {
    class DelayedPrinter {
    public:
        explicit DelayedPrinter(int delay_ms)
            : delay_ms_(delay_ms) {
        }
        void printWithDelay(const char* text) const {
            for (const char* c = text; *c != '\0'; ++c) {
                std::printf("%c", *c);
                std::fflush(stdout);
                std::this_thread::sleep_for(std::chrono::milliseconds(delay_ms_));
            }
            std::printf("\n");
        }
    private:
        int delay_ms_;
    };

    void loading(int Time) {
        const int steps = 200;
        int steps_count = (Time * 1000) / steps;
        const char animation[] = { '|', '/', '-', '\\' };
        int anim_index = 0;

        std::cout << "Loading: " << std::flush;
        for (int i = 0; i < steps; i++) {
            std::cout << "\b" << animation[anim_index] << std::flush;
            anim_index = (anim_index + 1) % 4;
            std::this_thread::sleep_for(std::chrono::milliseconds(steps));
        }
        std::cout << "\b\033[32mzaladowane\33[0m" << std::endl;
    }
} // namespace game

#endif // GAME_HPP
