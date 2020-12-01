#include <bits/stdc++.h>
#include <boost/random.hpp>
#include <boost/chrono.hpp>
#include <boost/date_time.hpp>
int main(int argv, char** argc){
    auto now = boost::posix_time::microsec_clock::local_time().time_of_day().total_microseconds() ;
    boost::mt19937 rng( now );

    if (argv<=2) {
        boost::uniform_int<> generator(0,1);
        std::cout << generator(rng) << std::endl;
    }else {
        boost::uniform_int<> generator(1,argv-1);
        std::cout << argc[generator(rng)] << std::endl;
    }

}
