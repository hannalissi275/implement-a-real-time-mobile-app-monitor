#include <iostream>
#include <string>
#include <map>
#include <thread>
#include <chrono>

// Mobile App Monitor class
class MobileAppMonitor {
private:
    std::map<std::string, int> appUsage; // app name, usage time
    std::string currentApp; // current foreground app

    // update app usage time
    void updateAppUsage(const std::string& appName, int time) {
        if (appUsage.find(appName) != appUsage.end()) {
            appUsage[appName] += time;
        } else {
            appUsage[appName] = time;
        }
    }

public:
    // constructor
    MobileAppMonitor() : currentApp("") {}

    // get current foreground app
    std::string getCurrentApp() {
        return currentApp;
    }

    // set current foreground app
    void setCurrentApp(const std::string& appName) {
        currentApp = appName;
    }

    // start monitoring
    void startMonitoring() {
        while (true) {
            // get current foreground app
            std::string currentApp = getCurrentApp();

            // simulate app usage time (1 second)
            std::this_thread::sleep_for(std::chrono::seconds(1));

            // update app usage time
            updateAppUsage(currentApp, 1);

            // print app usage time
            std::cout << "App: " << currentApp << ", Usage Time: " << appUsage[currentApp] << " seconds" << std::endl;
        }
    }

    // get app usage time
    int getAppUsage(const std::string& appName) {
        if (appUsage.find(appName) != appUsage.end()) {
            return appUsage[appName];
        } else {
            return 0;
        }
    }
};

int main() {
    MobileAppMonitor monitor;

    // set initial foreground app
    monitor.setCurrentApp("Facebook");

    // start monitoring
    monitor.startMonitoring();

    return 0;
}