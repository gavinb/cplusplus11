/*
    chrono_ex1.cpp

    Time how fast we can write random data to disk.
 */

#include <memory>
#include <chrono>
#include <iostream>
#include <fstream>

int main()
{
    // Set up buffer

    const uint32_t file_size_MB = 4;
    const uint32_t file_bytes = file_size_MB * 1024 * 1024;
    auto buffer = std::unique_ptr<char>(new char[file_bytes]);

    // Fill with random data to thwart filesystem compression

    for (unsigned i = 0; i < file_bytes; i++)
    {
        buffer.get()[i] = random() % 255;
    }

    // Start the clock

    auto time_before = std::chrono::system_clock::now();

    std::ofstream outf("_test_.tmp", std::ios::out);

    outf.write(buffer.get(), file_bytes);
    outf.flush();
    outf.close();

    // Stop the clock

    auto time_after = std::chrono::system_clock::now();

    // Calculate elapsed time and write speed

    auto time_elapsed_us = std::chrono::duration_cast<std::chrono::microseconds>(time_after-time_before).count();
    auto write_rate = (float)file_size_MB/(time_elapsed_us/1e6);

    std::cout << "Elapsed: " << time_elapsed_us << " us" << std::endl;
    std::cout << "Write rate: " << write_rate << " MB/sec" << std::endl;

    return 0;
}
