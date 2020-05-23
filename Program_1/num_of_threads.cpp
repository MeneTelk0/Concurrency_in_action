#include <thread>
#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>
#include <sstream>

void print_thread(size_t i){
    // Using additional buffer to eliminate concurrency between threads
    std::stringstream out; 
    out << "Num of thread: " << i << ", Thread id: " 
                        << std::this_thread::get_id() << std::endl;
    std::cout << out.str();
}

int main(int argc, char *argv[]){

    unsigned num_threads;
    if (argc < 2){
        std::cout << "Bad input data \nUsage: " << argv[0] 
                        << " Number_of_threads" << std::endl;
    } else {
        num_threads = std::atoi(argv[1]);
    }
    // Selecting minimum between input number of threads
    // and allowed by hardware (if it could be extracted)
    unsigned hardware_threads = std::thread::hardware_concurrency();
    num_threads = std::min(hardware_threads != 0 ? 
                            hardware_threads : 8, num_threads);

    // Main thread
    std::cout << "Main Thread, Thread id: " 
                        << std::this_thread::get_id() << std::endl;

    std::vector<std::thread> threads;
    for (size_t i = 1; i <= num_threads; i++){
        threads.push_back(std::thread(print_thread, i));
    }

    // Waiting until all processes will end  
    std::for_each(threads.begin(),threads.end(),
        std::mem_fn(&std::thread::join));

    return EXIT_SUCCESS;
}