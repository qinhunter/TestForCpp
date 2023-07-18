#include <iostream> 
#include <stdlib.h> 
#include <time.h>  
#include <vector>

using namespace std;  
class Cn {
public:
    Cn(int init_cpus = 84, int init_sale_ratio = 1)
            : sale_ratio(init_sale_ratio), vcpus(init_cpus * init_sale_ratio) {
                free_vcpus = vcpus;
            }
    int sale_ratio = 1;
    int vcpus = 0;
    int free_vcpus = 0;
    std::vector<int> vms;
    void release_vm(int vm_index) {
        vcpus += vms[vm_index];
        vms.erase(vms.begin() + vm_index);
    }
    void add_vm(int vm_cpus) {
        vms.emplace_back(vm_cpus);
        vcpus -= vm_cpus;
    }
};

class Group {
    int empty_hosts;
};

static std::vector<int> vm_flavor = {2, 4, 8, 16, 32, 64};
static std::vector<int> vm_flavor_possibilities = {20, 20, 20, 15, 15, 10};

int main() {  
    // init Group and hosts
    // random schedule and release with specified 
}

