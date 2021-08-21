#include <iostream>
#include <iomanip>
#include <glog/logging.h>

using std::setw;
using std::setfill;


/* This function writes a prefix that matches glog's default format.
 * (The third parameter can be used to receive user-supplied data, and is
 * NULL by default.)
 */
void CustomPrefix(std::ostream &s, const LogMessageInfo &l, void*) {
   s << l.severity[0]
   << setw(4) << 1900 + l.time.year()
   << setw(2) << 1 + l.time.month()
   << setw(2) << l.time.day()
   << ">>>>>>>>>>>>"
   << setw(2) << l.time.hour() << ':'
   << setw(2) << l.time.min()  << ':'
   << setw(2) << l.time.sec() << "."
   << setw(6) << l.time.usec()
   << ' '
   << setfill(' ') << setw(5)
   << l.thread_id << setfill('0')
   << ' '
   << l.filename << ':' << l.line_number << "]";
}

int main(int argc, char* argv[]) {
    // FLAGS_log_dir  = "./log";
    google::InitGoogleLogging(argv[0], &CustomPrefix);
    FLAGS_logtostderr = 1;
    int num_cookies = 10;
    LOG_IF(INFO, num_cookies > 10) << "Got lots of cookies";

    for (int i = 0; i < 30; i++) {
        LOG_EVERY_N(INFO, 10) << "Got the " << google::COUNTER << "th cookie";
    }

    DLOG(INFO) << "Found cookies";
    // CHECK_EQ(1, 2) << ": The world must be ending!";

    FLAGS_v = 2;
    VLOG(1) << "I’m printed when you run the program with --v=1 or higher";
    VLOG(2) << "I’m printed when you run the program with --v=2 or higher";



    google::ShutdownGoogleLogging();
}
