#ifndef GAME_HPP
#define GAME_HPP

#include <string>
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

    void loading(int czas) {
        const int krok = 200;
        int ilosc_krokow = (czas * 1000) / krok;
        const char animacja[] = { '|', '/', '-', '\\' };
        int anim_index = 0;

        std::cout << "\033[1;31mLoading: \033[0m" << std::flush;
        for (int i = 0; i < ilosc_krokow; i++) {
            std::cout << "\b" << animacja[anim_index] << std::flush;
            anim_index = (anim_index + 1) % 4;
            std::this_thread::sleep_for(std::chrono::milliseconds(krok));
        }
        std::cout << "\033[1;32mDone\033[0m" << std::endl;
    }

    void cls(int delay) {
        std::this_thread::sleep_for(std::chrono::seconds(delay));
        system("cls");
    }

    void cc(char* input) {
        system(input);
    }

    void sequence(int time, int time2) {
        game::cls( time2 );
        game::loading( time );
        game::cls( time2 );
    }
}

#endif // GAME_HPP
