#include <iostream>
#include <sstream>
#include <thread>

class TConverter {
public:
    TConverter(std::istream& source, std::ostream& sink);
    void Start();
    void Stop();
    const bool& IsFinished() const;

private:
    void Run();

private:
    std::istream& _Source;
    std::ostream& _Sink;
    std::thread _Thread;
    bool _IsRunning;
    bool _IsFinished;
};
