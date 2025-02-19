#ifndef GAME_HPP
#define GAME_HPP

#include <string>
#include <chrono>
#include <thread>
#include <cstdio>
#include <ctime>

extern bool isThiren;
extern bool isHuman;

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
        const char animacja[] = {'|', '/', '-', '\\'};
        int anim_index = 0;

        std::cout << "\033[1;31mLoading: \033[0m" << std::flush;
        for (int i = 0; i < ilosc_krokow; i++) {
            std::cout << "\b" << animacja [anim_index] << std::flush;
            anim_index = (anim_index + 1) % 4;
            std::this_thread::sleep_for(std::chrono::milliseconds(krok));
        }
        std::cout << "\033[1;32mDone\033[0m" << std::endl;
    }

    void cls(int delay) {
        std::this_thread::sleep_for(std::chrono::milliseconds(delay));
        system("cls");
    }

    void sleep_for(int delay_ms_) {
        std::this_thread::sleep_for(std::chrono::milliseconds(delay_ms_));
    }

    void sequence(int time, int time2) {
        game::cls(time2);
        game::loading(time);
        game::cls(time2);
    }

    #include <Windows.h>

    std::wstring convertToWideString(const char* narrowStr) {
        int len = MultiByteToWideChar(CP_UTF8, 0, narrowStr, -1, NULL, 0);
        std::wstring wideStr(len, 0);
        MultiByteToWideChar(CP_UTF8, 0, narrowStr, -1, &wideStr [0], len);
        return wideStr;
    }

    std::thread showMessageBoxThread;

    void stopMessageBox() {
        if (showMessageBoxThread.joinable()) {
            showMessageBoxThread.detach();
        }
    }

    void showMessageBox(const char* title, const char* message) {
        std::thread([title, message]() {
            std::wstring wTitle = convertToWideString(title);
            std::wstring wMessage = convertToWideString(message);

            while (true) {
                int response = MessageBox(NULL, wMessage.c_str(), wTitle.c_str(), MB_OKCANCEL | MB_ICONWARNING);
                if (response == IDCANCEL) {
                    game::sleep_for(5000);
                    continue;
                }

            }
            }).join();

        showMessageBoxThread = std::thread(showMessageBox, title, message);
    }



}

#endif // GAME_HPP
