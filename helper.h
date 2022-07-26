#ifndef HELPER_H_INCLUDED
#define HELPER_H_INCLUDED
#include <string>
#include <vector>
using std::vector;
using std::string;

namespace BookReader {

class Helper{
public:


static int ReadInt(int low, int high);

static int ShowReadMenu(const vector<string> &choices);

static string GetCurrentTimeDate();
};


}

#endif // HELPER_H_INCLUDED
