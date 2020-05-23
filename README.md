# Concurrency_in_action

Usage of `C++11 threads` library with examples from "Concurrency in Action" book written by Anthony Williams

## Program 1

Program receives on input number `N` as a command line argument and makes `N` threads via `C+11 threads` library. Each thread prints its executable number in order it has been created and its ID (`std::thread::id`).
