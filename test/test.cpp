#include <iostream>
#include <gtest/gtest.h>
#include "../src/Converter.h"

using namespace std;

TEST(Converter, correctness_reading) 
{
    stringstream in, out;
    std::string ans;
    in << "ABCDEFG";
    ans = "65\n66\n67\n68\n69\n70\n71\n";

    TConverter conv(in, out);
    conv.Start();
    while (!conv.IsFinished()) {
        this_thread::sleep_for(chrono::milliseconds(100));
    }
    conv.Stop();

    ASSERT_EQ(out.str(), ans);
}

TEST(Converter, repeated_reading)
{
    stringstream in, out;
    std::string ans;
    in << "ABCDEFGABCDEFG";
    ans = "65\n66\n67\n68\n69\n70\n71\n65\n66\n67\n68\n69\n70\n71\n";

    TConverter conv(in, out);
    conv.Start();
    this_thread::sleep_for(chrono::milliseconds(10));
    conv.Stop();
    conv.Start();
    while (!conv.IsFinished()) {
        this_thread::sleep_for(chrono::milliseconds(100));
    }
    conv.Stop();

    ASSERT_EQ(out.str(), ans);
}

TEST(Converter, reading_empty)
{
    stringstream in, out;
    std::string ans;
    in << "";
    ans = "";

    TConverter conv(in, out);
    conv.Start();
    while (!conv.IsFinished()) {
        this_thread::sleep_for(chrono::milliseconds(100));
    }
    conv.Stop();

    ASSERT_EQ(out.str(), ans);
}

TEST(Converter, exception_start)
{
    stringstream in, out;
    in << "ABCDEFG";
    TConverter conv(in, out);

    conv.Start();
    ASSERT_THROW(conv.Start(), std::logic_error);
    conv.Stop();
}
