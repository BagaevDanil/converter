#include "Converter.h"

TConverter::TConverter(std::istream& source, std::ostream& sink)
    : _Source(source)
    , _Sink(sink)
    , _IsRunning(false)
    , _IsFinished(true) {}

void TConverter::Start() 
{
    if (_IsRunning) {
        throw std::logic_error("Already working");
    }
    _IsRunning = true;
    _IsFinished = false;
    _Thread = std::thread(&TConverter::Run, this);
}

void TConverter::Stop() 
{
    _IsRunning = false;
    _IsFinished = true;
    _Thread.join();
}

const bool& TConverter::IsFinished() const
{
    return _IsFinished;
}

void TConverter::Run() 
{
    std::stringstream ss;
    while (_IsRunning && !_Source.eof()) {
        char byte;
        _Source.get(byte);

        if (_Source.eof() ||  byte == '\n' || byte == -52) {
            continue;
        }

        ss.str(std::string());
        ss << static_cast<int>(byte);
        std::string str = ss.str();

        _Sink << str << std::endl;
    }
    _IsFinished = true;
}
