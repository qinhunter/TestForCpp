#include <iostream> 
#include <stdlib.h> 
#include <time.h>  
#include <vector>
#include <thread>

using namespace std;  
// m balls, n boxes
int SHOW_TIMES = 1000;
bool happened(int m, int n) {
    std::vector<int> boxes(n, 0);
    for (int i = 0; i < m; ++i) {
        ++boxes[rand() % n];
    }
    for (const auto n : boxes) {
        if (n > 0) {
            return n > 1;
        }
    }
    return false;
}
void times_happened(int m, int n, int times, int* ans) {
    auto t_id = std::this_thread::get_id();
    for (int i = 1; i <= times; ++i) {
        if (happened(m, n)) {
            ++*ans;
        }
        if (i % SHOW_TIMES == 0) {
            std::cout << "thread " << t_id << " has calculated for " << i << " times" << std::endl;
        }
    }
    std::cout << "thread " << t_id << " calculates " << times << " done" << std::endl;
}
int main() 
{  
    int m = 20;
    int n = 20003;
    int times = 5000;
    int thread_num = 20;
    std::vector<int> threads_result(thread_num, 0);
    std::vector<std::thread*> threads(thread_num, nullptr);
    printf("m %d, n %d, test total times %d, thread_num %d \n", m, n, times, thread_num);
    int ans = 0;
    for (int i = 0; i < thread_num; ++i) {
        threads[i] = new std::thread(times_happened, m, n, times / thread_num, &threads_result[i]);
    }
    for (int i = 0; i < thread_num; ++i) {
        threads[i]->join();
        ans += threads_result[i];
    }
    std::cout << "ans " << ans << std::endl;
} 
