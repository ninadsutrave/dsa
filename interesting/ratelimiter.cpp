/* implement a rate limiter */

#include <iostream>
#include <unordered_map>
#include <queue>
#include <ctime>
using namespace std;

class RateLimiter {

    private: 
    unordered_map<int, queue<int>> customerData;
    int timeWindow;
    int limit;
    
    public:
    RateLimiter(int timeWindow, int limit) {
        this->timeWindow = timeWindow;
        this->limit = limit;
    }

    bool rateLimit (int customerId) {
        queue<int> apiCallLogs = customerData[customerId];

        if (apiCallLogs.size() >= limit) {
            int firstApiCallInWindow = apiCallLogs.front();
            if(time(0) - firstApiCallInWindow < timeWindow) return true;

            apiCallLogs.pop();
        }

        apiCallLogs.push(time(0));
        return false;
    }
};

/*

ratelimit ()
    - queue is an array
    - if array.size < limit
        - add timestamp
        - return false
    - get the current timestamp
        - remove all old entres from the array
        - check limit again 

*/



/*
class Application {
    Application () {
        RateLimiter ratelimter = new RateLimiter(limit, timeWindow);
    }
    void api (int customerId) {
        if (ratelimter.rateLimit(cusomterId)) {
            return;
        }

        ... business logic
    }
}

*/

